/*
 * File: FOC_Model.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Thu Apr 11 11:04:56 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Model.h"

/* Named constants for Chart: '<S2>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_RunStage                    ((uint8_T)3U)
#define NumBitsPerChar                 8U

/* Exported data definition */

/* Definition for custom storage class: Struct */
foc_type foc;
motor_type motor = {
  /* Flux */
  0.00103001F,

  /* Ls */
  2.235E-5F,

  /* Rs */
  0.112F
};

observer_flux_type observer_flux;

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real32_T rt_modf_snf(real32_T u0, real32_T u1);
static uint32_T plook_u32ff_evencg(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex, real32_T *fraction);
static real32_T intrp1d_fu32fl(uint32_T bpIndex, real32_T frac, const real32_T
  table[]);
static void Clark_Trans(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic,
  real32_T *rty_ialpha, real32_T *rty_ibeta);
static void Park_Trans(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T
  rtu_theta, real32_T *rty_id, real32_T *rty_iq);
static void Anti_Park_Trans(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta,
  real32_T *rty_ualpha, real32_T *rty_ubeta);
static void speed_loop_Init(void);
static void speed_loop_Enable(void);
static void speed_loop(void);
static void rate_scheduler(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

static uint32_T plook_u32ff_evencg(real32_T u, real32_T bp0, real32_T bpSpace,
  uint32_T maxIndex, real32_T *fraction)
{
  real32_T fbpIndex;
  real32_T invSpc;
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  invSpc = 1.0F / bpSpace;
  fbpIndex = (u - bp0) * invSpc;
  if (fbpIndex < maxIndex) {
    bpIndex = (uint32_T)fbpIndex;
    *fraction = (u - ((real32_T)(uint32_T)fbpIndex * bpSpace + bp0)) * invSpc;
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0F;
  }

  return bpIndex;
}

static real32_T intrp1d_fu32fl(uint32_T bpIndex, real32_T frac, const real32_T
  table[])
{
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }
}

/* System initialize for function-call system: '<S1>/speed_loop' */
static void speed_loop_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S199>/Integrator' */
  rtDW.Integrator_PrevResetState = 2;
}

/* Enable for function-call system: '<S1>/speed_loop' */
static void speed_loop_Enable(void)
{
  rtDW.speed_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S199>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;
}

/* Output and update for function-call system: '<S1>/speed_loop' */
static void speed_loop(void)
{
  real32_T Integrator;
  real32_T rtb_IProdOut;
  real32_T rtb_IProdOut_0;
  real32_T rtb_SignPreIntegrator;
  real32_T rtb_Sum;
  uint32_T speed_loop_ELAPS_T;
  if (rtDW.speed_loop_RESET_ELAPS_T) {
    speed_loop_ELAPS_T = 0U;
  } else {
    speed_loop_ELAPS_T = rtM->Timing.clockTick1 - rtDW.speed_loop_PREV_T;
  }

  rtDW.speed_loop_PREV_T = rtM->Timing.clockTick1;
  rtDW.speed_loop_RESET_ELAPS_T = false;

  /* Sum: '<S4>/Sum2' */
  rtb_IProdOut = foc.spd_ref - foc.spd_fdbk;

  /* DiscreteIntegrator: '<S199>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S199>/Integrator' */
    Integrator = rtDW.Integrator_DSTATE_d;
  } else if ((rtDW.RateTransition3 > 0.0F) && (rtDW.Integrator_PrevResetState <=
              0)) {
    rtDW.Integrator_DSTATE_d = 0.0F;

    /* DiscreteIntegrator: '<S199>/Integrator' */
    Integrator = rtDW.Integrator_DSTATE_d;
  } else {
    /* DiscreteIntegrator: '<S199>/Integrator' */
    Integrator = 0.001F * (real32_T)speed_loop_ELAPS_T * rtDW.Integrator_PREV_U
      + rtDW.Integrator_DSTATE_d;
  }

  /* End of DiscreteIntegrator: '<S199>/Integrator' */

  /* Sum: '<S208>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S204>/PProd Out'
   */
  rtb_Sum = rtb_IProdOut * 0.0144F + Integrator;

  /* DeadZone: '<S192>/DeadZone' incorporates:
   *  Saturate: '<S206>/Saturation'
   */
  if (rtb_Sum > 5.0F) {
    rtb_SignPreIntegrator = rtb_Sum - 5.0F;

    /* Saturate: '<S206>/Saturation' */
    rtDW.Saturation = 5.0F;
  } else {
    if (rtb_Sum >= -5.0F) {
      rtb_SignPreIntegrator = 0.0F;
    } else {
      rtb_SignPreIntegrator = rtb_Sum - -5.0F;
    }

    if (rtb_Sum < -5.0F) {
      /* Saturate: '<S206>/Saturation' */
      rtDW.Saturation = -5.0F;
    } else {
      /* Saturate: '<S206>/Saturation' */
      rtDW.Saturation = rtb_Sum;
    }
  }

  /* End of DeadZone: '<S192>/DeadZone' */

  /* Product: '<S196>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_IProdOut *= 0.6389F;

  /* Update for DiscreteIntegrator: '<S199>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 0U;
  rtDW.Integrator_DSTATE_d = Integrator;
  if (rtDW.RateTransition3 > 0.0F) {
    rtDW.Integrator_PrevResetState = 1;
  } else if (rtDW.RateTransition3 < 0.0F) {
    rtDW.Integrator_PrevResetState = -1;
  } else if (rtDW.RateTransition3 == 0.0F) {
    rtDW.Integrator_PrevResetState = 0;
  } else {
    rtDW.Integrator_PrevResetState = 2;
  }

  /* Signum: '<S190>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    Integrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    Integrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    Integrator = 0.0F;
  } else {
    Integrator = (rtNaNF);
  }

  /* End of Signum: '<S190>/SignPreSat' */

  /* Signum: '<S190>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut_0 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut_0 = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut_0 = 0.0F;
  } else {
    rtb_IProdOut_0 = (rtNaNF);
  }

  /* End of Signum: '<S190>/SignPreIntegrator' */

  /* Switch: '<S190>/Switch' incorporates:
   *  DataTypeConversion: '<S190>/DataTypeConv1'
   *  DataTypeConversion: '<S190>/DataTypeConv2'
   *  Gain: '<S190>/ZeroGain'
   *  Logic: '<S190>/AND3'
   *  RelationalOperator: '<S190>/Equal1'
   *  RelationalOperator: '<S190>/NotEqual'
   */
  if ((0.0F * rtb_Sum != rtb_SignPreIntegrator) && ((int8_T)Integrator ==
       (int8_T)rtb_IProdOut_0)) {
    /* Update for DiscreteIntegrator: '<S199>/Integrator' incorporates:
     *  Constant: '<S190>/Constant1'
     */
    rtDW.Integrator_PREV_U = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S199>/Integrator' */
    rtDW.Integrator_PREV_U = rtb_IProdOut;
  }

  /* End of Switch: '<S190>/Switch' */
}

/* Output and update for atomic system: '<S3>/Clark_Trans' */
static void Clark_Trans(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic,
  real32_T *rty_ialpha, real32_T *rty_ibeta)
{
  /* Sum: '<S9>/Add1' incorporates:
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   *  Sum: '<S9>/Add'
   */
  *rty_ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) * 0.333333343F;

  /* Gain: '<S9>/Gain2' incorporates:
   *  Sum: '<S9>/Add2'
   */
  *rty_ibeta = (rtu_ib - rtu_ic) * 0.577350259F;
}

/* Output and update for atomic system: '<S3>/Park_Trans' */
static void Park_Trans(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T
  rtu_theta, real32_T *rty_id, real32_T *rty_iq)
{
  real32_T frac;
  real32_T uVarTmp;
  real32_T uVarTmp_tmp;
  real32_T yVarTmp;
  uint32_T bpIdx;
  boolean_T negFlag;
  static const real32_T tableData_c[16] = { 0.0F, 0.104528464F, 0.207911685F,
    0.309017F, 0.406736642F, 0.5F, 0.587785244F, 0.669130623F, 0.74314481F,
    0.809017F, 0.866025388F, 0.91354543F, 0.95105654F, 0.978147626F,
    0.994521916F, 1.0F };

  /* Trigonometry: '<S11>/Cos' incorporates:
   *  Trigonometry: '<S11>/Sin'
   */
  uVarTmp_tmp = rtu_theta / 6.28318548F;
  if (uVarTmp_tmp < 0.0F) {
    yVarTmp = uVarTmp_tmp + 1.0F;
    uVarTmp = uVarTmp_tmp + 1.0F;
  } else {
    yVarTmp = uVarTmp_tmp;
    uVarTmp = uVarTmp_tmp;
  }

  uVarTmp += 0.25F;
  if (yVarTmp + 0.25F >= 1.0F) {
    uVarTmp = (yVarTmp + 0.25F) - 1.0F;
  }

  if (uVarTmp > 0.5F) {
    uVarTmp -= 0.5F;
    negFlag = true;
  } else {
    negFlag = false;
  }

  if (uVarTmp > 0.25F) {
    uVarTmp = 0.5F - uVarTmp;
  }

  bpIdx = plook_u32ff_evencg(uVarTmp, 0.0F, 0.0166666675F, 15U, &frac);
  yVarTmp = intrp1d_fu32fl(bpIdx, frac, tableData_c);
  if (negFlag) {
    yVarTmp = -yVarTmp;
  }

  /* End of Trigonometry: '<S11>/Cos' */

  /* Trigonometry: '<S11>/Sin' */
  uVarTmp = uVarTmp_tmp;
  if (uVarTmp_tmp < 0.0F) {
    uVarTmp = uVarTmp_tmp + 1.0F;
  }

  if (uVarTmp > 0.5F) {
    uVarTmp -= 0.5F;
    negFlag = true;
  } else {
    negFlag = false;
  }

  if (uVarTmp > 0.25F) {
    uVarTmp = 0.5F - uVarTmp;
  }

  bpIdx = plook_u32ff_evencg(uVarTmp, 0.0F, 0.0166666675F, 15U, &frac);
  uVarTmp = intrp1d_fu32fl(bpIdx, frac, tableData_c);
  if (negFlag) {
    uVarTmp = -uVarTmp;
  }

  *rty_iq = uVarTmp;

  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   */
  *rty_id = rtu_ialpha * yVarTmp + rtu_ibeta * *rty_iq;

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   */
  *rty_iq = rtu_ibeta * yVarTmp - rtu_ialpha * *rty_iq;
}

/* Output and update for atomic system: '<S13>/Anti_Park_Trans' */
static void Anti_Park_Trans(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta,
  real32_T *rty_ualpha, real32_T *rty_ubeta)
{
  real32_T rtb_Cos_m;

  /* Trigonometry: '<S163>/Cos' */
  rtb_Cos_m = cosf(rtu_theta);

  /* Trigonometry: '<S163>/Sin' */
  *rty_ubeta = sinf(rtu_theta);

  /* Sum: '<S163>/Add' incorporates:
   *  Product: '<S163>/Product'
   *  Product: '<S163>/Product1'
   */
  *rty_ualpha = rtu_ud * rtb_Cos_m - rtu_uq * *rty_ubeta;

  /* Sum: '<S163>/Add1' incorporates:
   *  Product: '<S163>/Product2'
   *  Product: '<S163>/Product3'
   */
  *rty_ubeta = rtu_ud * *rty_ubeta + rtu_uq * rtb_Cos_m;
}

real32_T rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (rtIsNaNF(u0) || rtIsNaNF(u1) || rtIsInfF(u0)) {
    y = (rtNaNF);
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else if (rtIsInfF(u1)) {
    if ((u1 < 0.0F) != (u0 < 0.0F)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmodf(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > floorf(u1))) {
      real32_T q;
      q = fabsf(u0 / u1);
      yEq = !(fabsf(q - floorf(q + 0.5F)) > FLT_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void FOC_Model_step(void)
{
  int32_T rtb_Motor_state;
  real32_T T1;
  real32_T rtb_Gain1_j;
  real32_T rtb_Integrator_d;
  real32_T rtb_Integrator_m;
  real32_T rtb_Saturation;
  real32_T rtb_Sum1;
  real32_T rtb_Sum7;
  real32_T rtb_real;
  real32_T rtb_soure;
  real32_T ta;

  /* Chart: '<S2>/Chart1' incorporates:
   *  Inport: '<Root>/MotorSwitch'
   */
  if (rtDW.temporalCounter_i1 < 1023U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c2_FOC_Model == 0U) {
    rtDW.is_active_c2_FOC_Model = 1U;
    rtDW.is_c2_FOC_Model = IN_IDLE;
    rtb_Motor_state = 1;
    rtb_soure = 0.0F;
  } else {
    switch (rtDW.is_c2_FOC_Model) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000U) {
        rtDW.is_c2_FOC_Model = IN_RunStage;
        rtb_Motor_state = 3;
        rtb_soure = 1.0F;
      } else if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c2_FOC_Model = IN_IDLE;
        rtb_Motor_state = 1;
        rtb_soure = 0.0F;
      } else {
        rtb_Motor_state = 2;
        rtb_soure = 0.0F;
      }
      break;

     case IN_IDLE:
      if (rtU.MotorSwitch == 1.0F) {
        rtDW.is_c2_FOC_Model = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
        rtb_Motor_state = 2;
        rtb_soure = 0.0F;
      } else {
        rtb_Motor_state = 1;
        rtb_soure = 0.0F;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c2_FOC_Model = IN_IDLE;
        rtb_Motor_state = 1;
        rtb_soure = 0.0F;
      } else {
        rtb_Motor_state = 3;
        rtb_soure = 1.0F;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* RateTransition: '<S1>/Rate Transition3' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition3 = rtb_soure;

    /* RateTransition: '<S1>/Rate Transition2' incorporates:
     *  Inport: '<Root>/Spd_ref'
     */
    if (rtM->Timing.TaskCounters.TID[1] == 0) {
      foc.spd_ref = rtU.Spd_ref;
    }

    /* End of RateTransition: '<S1>/Rate Transition2' */

    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.RateTransition4 = rtDW.RateTransition4_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* Math: '<S112>/Mod' incorporates:
   *  Constant: '<S112>/Constant2'
   *  DiscreteIntegrator: '<S112>/Discrete-Time Integrator'
   */
  foc.flux_theta = rt_modf_snf(rtDW.DiscreteTimeIntegrator_DSTATE, 6.28318548F);

  /* Math: '<S3>/Mod' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Sum: '<S3>/Add1'
   */
  rtb_soure = rt_modf_snf(foc.flux_theta, 6.28318548F);

  /* SwitchCase: '<S2>/Switch Case1' */
  switch (rtb_Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Constant: '<S6>/Constant'
     */
    foc.theta_real = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    foc.iq_ref = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Constant: '<S7>/Constant'
     */
    foc.theta_real = 0.0F;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    foc.iq_ref = 0.0F;

    /* Merge: '<S2>/Merge2' incorporates:
     *  Constant: '<S7>/Constant2'
     */
    rtDW.Merge2 = 2.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Inport: '<S8>/theta_Close'
     */
    foc.theta_real = rtb_soure;

    /* Merge: '<S2>/Merge1' incorporates:
     *  Inport: '<S8>/iq_CloseRef'
     */
    foc.iq_ref = rtDW.RateTransition4;

    /* Merge: '<S2>/Merge2' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    rtDW.Merge2 = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case1' */

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/id_ref'
   */
  foc.id_ref = rtDW.Merge2 + rtU.id_ref;

  /* Outputs for Atomic SubSystem: '<S3>/Clark_Trans' */
  /* SignalConversion generated from: '<S3>/Clark_Trans' incorporates:
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   */
  Clark_Trans(rtU.ia, rtU.ib, rtU.ic, &(foc.i_alpha), &(foc.i_beta));

  /* End of Outputs for SubSystem: '<S3>/Clark_Trans' */

  /* Outputs for Atomic SubSystem: '<S3>/Park_Trans' */
  /* SignalConversion generated from: '<S3>/Park_Trans' */
  Park_Trans(foc.i_alpha, foc.i_beta, foc.theta_real, &(foc.id), &(foc.iq));

  /* End of Outputs for SubSystem: '<S3>/Park_Trans' */

  /* Sum: '<S10>/Sum1' */
  rtb_Sum1 = foc.id_ref - foc.id;

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  rtb_Integrator_m = 200.0F * motor.Ls;

  /* Sum: '<S56>/Sum' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Product: '<S52>/PProd Out'
   */
  rtb_real = rtb_Sum1 * rtb_Integrator_m + rtDW.Integrator_DSTATE;

  /* Saturate: '<S54>/Saturation' */
  if (rtb_real > 6.23538303F) {
    /* Saturate: '<S54>/Saturation' */
    foc.ud = 6.23538303F;
  } else if (rtb_real < -6.23538303F) {
    /* Saturate: '<S54>/Saturation' */
    foc.ud = -6.23538303F;
  } else {
    /* Saturate: '<S54>/Saturation' */
    foc.ud = rtb_real;
  }

  /* End of Saturate: '<S54>/Saturation' */

  /* Sum: '<S10>/Sum7' */
  rtb_Sum7 = foc.iq_ref - foc.iq;

  /* Sum: '<S104>/Sum' incorporates:
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Product: '<S100>/PProd Out'
   */
  rtb_real = rtb_Sum7 * rtb_Integrator_m + rtDW.Integrator_DSTATE_o;

  /* Saturate: '<S102>/Saturation' */
  if (rtb_real > 6.23538303F) {
    /* Saturate: '<S102>/Saturation' */
    foc.uq = 6.23538303F;
  } else if (rtb_real < -6.23538303F) {
    /* Saturate: '<S102>/Saturation' */
    foc.uq = -6.23538303F;
  } else {
    /* Saturate: '<S102>/Saturation' */
    foc.uq = rtb_real;
  }

  /* End of Saturate: '<S102>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S13>/Anti_Park_Trans' */
  /* SignalConversion generated from: '<S13>/Anti_Park_Trans' */
  Anti_Park_Trans(foc.ud, foc.uq, foc.theta_real, &(foc.u_alpha), &(foc.u_beta));

  /* End of Outputs for SubSystem: '<S13>/Anti_Park_Trans' */

  /* Gain: '<S113>/Gain1' incorporates:
   *  Gain: '<S113>/Gain3'
   */
  rtb_Saturation = motor.Ls * foc.i_alpha;

  /* Sum: '<S113>/Sum' incorporates:
   *  Gain: '<S113>/Gain1'
   *  UnitDelay: '<S113>/Unit Delay'
   */
  rtb_real = rtDW.UnitDelay_DSTATE - rtb_Saturation;

  /* Gain: '<S113>/Gain5' incorporates:
   *  Gain: '<S113>/Gain8'
   */
  T1 = motor.Ls * foc.i_beta;

  /* Sum: '<S113>/Sum1' incorporates:
   *  Gain: '<S113>/Gain5'
   *  UnitDelay: '<S113>/Unit Delay1'
   */
  rtb_Integrator_d = rtDW.UnitDelay1_DSTATE - T1;

  /* Sum: '<S113>/Add2' incorporates:
   *  Constant: '<S113>/Constant1'
   *  Math: '<S113>/Magnitude Squared'
   *  Math: '<S113>/Magnitude Squared1'
   *  Math: '<S113>/Magnitude Squared2'
   *  Sum: '<S113>/Add1'
   *
   * About '<S113>/Magnitude Squared':
   *  Operator: magnitude^2
   *
   * About '<S113>/Magnitude Squared1':
   *  Operator: magnitude^2
   *
   * About '<S113>/Magnitude Squared2':
   *  Operator: magnitude^2
   */
  rtb_Gain1_j = motor.Flux * motor.Flux - (rtb_real * rtb_real +
    rtb_Integrator_d * rtb_Integrator_d);

  /* Sum: '<S113>/Add4' incorporates:
   *  Constant: '<S113>/Constant'
   *  Gain: '<S113>/Gain'
   *  Gain: '<S113>/Gain2'
   *  Product: '<S113>/Product'
   *  Sum: '<S113>/Add'
   *  Sum: '<S113>/Add3'
   *  UnitDelay: '<S113>/Unit Delay'
   */
  rtb_Integrator_m = ((foc.u_alpha - motor.Rs * foc.i_alpha) + 800000.0F *
                      rtb_real * rtb_Gain1_j) * 0.0001F + rtDW.UnitDelay_DSTATE;

  /* Gain: '<S113>/Gain4' incorporates:
   *  Sum: '<S113>/Add5'
   */
  observer_flux.theta_cos = (rtb_Integrator_m - rtb_Saturation) * (1.0F /
    motor.Flux);

  /* Sum: '<S113>/Add8' incorporates:
   *  Constant: '<S113>/Constant2'
   *  Gain: '<S113>/Gain6'
   *  Gain: '<S113>/Gain7'
   *  Product: '<S113>/Product1'
   *  Sum: '<S113>/Add6'
   *  Sum: '<S113>/Add7'
   *  UnitDelay: '<S113>/Unit Delay1'
   */
  rtb_Integrator_d = (rtb_Gain1_j * 800000.0F * rtb_Integrator_d + (foc.u_beta -
    motor.Rs * foc.i_beta)) * 0.0001F + rtDW.UnitDelay1_DSTATE;

  /* Gain: '<S113>/Gain9' incorporates:
   *  Sum: '<S113>/Add9'
   */
  observer_flux.theta_sin = (rtb_Integrator_d - T1) * (1.0F / motor.Flux);

  /* Sum: '<S112>/Add' incorporates:
   *  Product: '<S112>/Product'
   *  Product: '<S112>/Product1'
   *  Trigonometry: '<S112>/Sin'
   *  Trigonometry: '<S112>/Sin1'
   */
  rtb_Gain1_j = observer_flux.theta_sin * cosf(foc.flux_theta) -
    observer_flux.theta_cos * sinf(foc.flux_theta);

  /* Sum: '<S155>/Sum' incorporates:
   *  DiscreteIntegrator: '<S146>/Integrator'
   *  Gain: '<S151>/Proportional Gain'
   */
  rtb_Saturation = 22.0F * rtb_Gain1_j + rtDW.Integrator_DSTATE_j;

  /* Saturate: '<S153>/Saturation' */
  if (rtb_Saturation > 3000.0F) {
    rtb_Saturation = 3000.0F;
  } else if (rtb_Saturation < -3000.0F) {
    rtb_Saturation = -3000.0F;
  }

  /* End of Saturate: '<S153>/Saturation' */

  /* Gain: '<S12>/wm->Nr2' */
  rtb_real = 1.36418521F * rtb_Saturation;

  /* RateTransition: '<S1>/Rate Transition1' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    foc.spd_fdbk = rtb_real;

    /* S-Function (fcgen): '<S1>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S1>/speed_loop'
     */
    speed_loop();

    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator2' */
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* Outport: '<Root>/Outport3' */
  rtY.Outport3 = rtb_real;

  /* Gain: '<S143>/Integral Gain' */
  rtb_real = 400.0F * rtb_Gain1_j;

  /* MATLAB Function: '<S13>/foc' */
  rtb_Motor_state = 0;

  /* Outport: '<Root>/Tcmp1' incorporates:
   *  MATLAB Function: '<S13>/foc'
   */
  rtY.Tcmp1 = 0.0F;

  /* Outport: '<Root>/Tcmp2' incorporates:
   *  MATLAB Function: '<S13>/foc'
   */
  rtY.Tcmp2 = 0.0F;

  /* Outport: '<Root>/Tcmp3' incorporates:
   *  MATLAB Function: '<S13>/foc'
   */
  rtY.Tcmp3 = 0.0F;

  /* MATLAB Function: '<S13>/foc' incorporates:
   *  Constant: '<S13>/Constant4'
   *  Inport: '<Root>/Ubus'
   */
  if (foc.u_beta > 0.0F) {
    rtb_Motor_state = 1;
  }

  if ((1.73205078F * foc.u_alpha - foc.u_beta) / 2.0F > 0.0F) {
    rtb_Motor_state += 2;
  }

  if ((-1.73205078F * foc.u_alpha - foc.u_beta) / 2.0F > 0.0F) {
    rtb_Motor_state += 4;
  }

  switch (rtb_Motor_state) {
   case 1:
    T1 = (-1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F /
      rtU.Ubus);
    rtb_Gain1_j = (1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F /
      rtU.Ubus);
    break;

   case 2:
    T1 = (1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F / rtU.Ubus);
    rtb_Gain1_j = -(1.73205078F * foc.u_beta * 16000.0F / rtU.Ubus);
    break;

   case 3:
    T1 = -((-1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F /
            rtU.Ubus));
    rtb_Gain1_j = 1.73205078F * foc.u_beta * 16000.0F / rtU.Ubus;
    break;

   case 4:
    T1 = -(1.73205078F * foc.u_beta * 16000.0F / rtU.Ubus);
    rtb_Gain1_j = (-1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F /
      rtU.Ubus);
    break;

   case 5:
    T1 = 1.73205078F * foc.u_beta * 16000.0F / rtU.Ubus;
    rtb_Gain1_j = -((1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F
      / rtU.Ubus));
    break;

   default:
    T1 = -((1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) * (16000.0F /
            rtU.Ubus));
    rtb_Gain1_j = -((-1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) *
                    (16000.0F / rtU.Ubus));
    break;
  }

  ta = T1 + rtb_Gain1_j;
  if (ta > 16000.0F) {
    T1 /= ta;
    rtb_Gain1_j /= T1 + rtb_Gain1_j;
  }

  ta = (16000.0F - (T1 + rtb_Gain1_j)) / 4.0F;
  T1 = T1 / 2.0F + ta;
  switch (rtb_Motor_state) {
   case 1:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = ta;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Gain1_j / 2.0F + T1;
    break;

   case 2:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = ta;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Gain1_j / 2.0F + T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = T1;
    break;

   case 3:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = ta;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Gain1_j / 2.0F + T1;
    break;

   case 4:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Gain1_j / 2.0F + T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = ta;
    break;

   case 5:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Gain1_j / 2.0F + T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = ta;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = T1;
    break;

   case 6:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Gain1_j / 2.0F + T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = ta;
    break;
  }

  /* Outport: '<Root>/Sector' incorporates:
   *  MATLAB Function: '<S13>/foc'
   */
  rtY.Sector = (real32_T)rtb_Motor_state;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  rtb_Gain1_j = 200.0F * motor.Rs;

  /* Outport: '<Root>/Outport4' */
  rtY.Outport4 = rtb_soure;

  /* Update for RateTransition: '<S1>/Rate Transition4' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition4_Buffer0 = rtDW.Saturation;
  }

  /* End of Update for RateTransition: '<S1>/Rate Transition4' */

  /* Update for UnitDelay: '<S113>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Integrator_m;

  /* Update for DiscreteIntegrator: '<S112>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.0001F * rtb_Saturation;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Product: '<S44>/IProd Out'
   */
  rtDW.Integrator_DSTATE += rtb_Sum1 * rtb_Gain1_j * 0.0001F;

  /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Product: '<S92>/IProd Out'
   */
  rtDW.Integrator_DSTATE_o += rtb_Sum7 * rtb_Gain1_j * 0.0001F;

  /* Update for UnitDelay: '<S113>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_Integrator_d;

  /* Update for DiscreteIntegrator: '<S146>/Integrator' */
  rtDW.Integrator_DSTATE_j += 0.0001F * rtb_real;
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void FOC_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S1>/speed_loop'
   */
  speed_loop_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator2' */

  /* Enable for S-Function (fcgen): '<S1>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S1>/speed_loop'
   */
  speed_loop_Enable();

  /* End of Enable for S-Function (fcgen): '<S1>/Function-Call Generator2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
