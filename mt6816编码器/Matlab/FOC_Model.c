/*
 * File: FOC_Model.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.54
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 19 13:27:27 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Model.h"

/* Named constants for Chart: '<S3>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_RunStage                    ((uint8_T)3U)
#define NumBitsPerChar                 8U

/* Exported block signals */
uint8_T motor_switch;                  /* '<Root>/MotorSwitch' */

/* Exported data definition */

/* Definition for custom storage class: Struct */
foc_type foc = {
  /* spd_fdbk */
  0,

  /* spd_ref */
  0,

  /* Ibus */
  15.0F,

  /* Sector */
  0.0F,

  /* Tcmp1 */
  0.0F,

  /* Tcmp2 */
  0.0F,

  /* Tcmp3 */
  0.0F,

  /* Ts */
  0.0000625F,

  /* Ubus */
  0.0F,

  /* i_alpha */
  0.0F,

  /* i_beta */
  0.0F,

  /* ia */
  0.0F,

  /* ib */
  0.0F,

  /* ic */
  0.0F,

  /* id */
  0.0F,

  /* id_align */
  2.0F,

  /* id_gain */
  2.0F,

  /* id_ref */
  0.0F,

  /* iq */
  0.0F,

  /* iq_ref */
  0.0F,

  /* theta_input */
  0.0F,

  /* theta_real */
  0.0F,

  /* u_alpha */
  0.0F,

  /* u_beta */
  0.0F,

  /* ud */
  0.0F,

  /* uq */
  0.0F,

  /* motor_state */
  0U
};

motor_type motor = {
  /* Flux */
  0.00103001F,

  /* Ls */
  2.235E-5F,

  /* Pn */
  7.0F,

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
  /* InitializeConditions for DiscreteIntegrator: '<S206>/Integrator' */
  rtDW.Integrator_PrevResetState = 2;
}

/* Enable for function-call system: '<S1>/speed_loop' */
static void speed_loop_Enable(void)
{
  rtDW.speed_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S206>/Integrator' */
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
  rtb_IProdOut = (real32_T)rtDW.RateTransition2 - (real32_T)rtDW.RateTransition1;

  /* DiscreteIntegrator: '<S206>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S206>/Integrator' */
    Integrator = rtDW.Integrator_DSTATE_d;
  } else if ((rtDW.RateTransition3 > 0.0F) && (rtDW.Integrator_PrevResetState <=
              0)) {
    rtDW.Integrator_DSTATE_d = 0.0F;

    /* DiscreteIntegrator: '<S206>/Integrator' */
    Integrator = rtDW.Integrator_DSTATE_d;
  } else {
    /* DiscreteIntegrator: '<S206>/Integrator' */
    Integrator = 0.001F * (real32_T)speed_loop_ELAPS_T * rtDW.Integrator_PREV_U
      + rtDW.Integrator_DSTATE_d;
  }

  /* End of DiscreteIntegrator: '<S206>/Integrator' */

  /* Sum: '<S216>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S211>/PProd Out'
   */
  rtb_Sum = rtb_IProdOut * 0.214F + Integrator;

  /* Switch: '<S199>/Switch' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  RelationalOperator: '<S199>/u_GTE_up'
   *  RelationalOperator: '<S199>/u_GT_lo'
   *  Switch: '<S199>/Switch1'
   */
  if (rtb_Sum >= foc.Ibus) {
    rtb_SignPreIntegrator = foc.Ibus;
  } else if (rtb_Sum > -foc.Ibus) {
    /* Switch: '<S199>/Switch1' */
    rtb_SignPreIntegrator = rtb_Sum;
  } else {
    rtb_SignPreIntegrator = -foc.Ibus;
  }

  /* End of Switch: '<S199>/Switch' */

  /* Sum: '<S199>/Diff' */
  rtb_SignPreIntegrator = rtb_Sum - rtb_SignPreIntegrator;

  /* Product: '<S203>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_IProdOut *= 0.8F;

  /* Switch: '<S214>/Switch2' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant3'
   *  RelationalOperator: '<S214>/LowerRelop1'
   *  RelationalOperator: '<S214>/UpperRelop'
   *  Switch: '<S214>/Switch'
   */
  if (rtb_Sum > foc.Ibus) {
    /* Switch: '<S214>/Switch2' */
    rtDW.Switch2 = foc.Ibus;
  } else if (rtb_Sum < -foc.Ibus) {
    /* Switch: '<S214>/Switch' incorporates:
     *  Constant: '<S4>/Constant3'
     *  Switch: '<S214>/Switch2'
     */
    rtDW.Switch2 = -foc.Ibus;
  } else {
    /* Switch: '<S214>/Switch2' incorporates:
     *  Switch: '<S214>/Switch'
     */
    rtDW.Switch2 = rtb_Sum;
  }

  /* End of Switch: '<S214>/Switch2' */

  /* Update for DiscreteIntegrator: '<S206>/Integrator' */
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

  /* Signum: '<S196>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    Integrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    Integrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    Integrator = 0.0F;
  } else {
    Integrator = (rtNaNF);
  }

  /* End of Signum: '<S196>/SignPreSat' */

  /* Signum: '<S196>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut_0 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut_0 = 1.0F;
  } else {
    rtb_IProdOut_0 = 0.0F;
  }

  /* End of Signum: '<S196>/SignPreIntegrator' */

  /* Switch: '<S196>/Switch' incorporates:
   *  DataTypeConversion: '<S196>/DataTypeConv1'
   *  DataTypeConversion: '<S196>/DataTypeConv2'
   *  Gain: '<S196>/ZeroGain'
   *  Logic: '<S196>/AND3'
   *  RelationalOperator: '<S196>/Equal1'
   *  RelationalOperator: '<S196>/NotEqual'
   */
  if ((0.0F * rtb_Sum != rtb_SignPreIntegrator) && ((int8_T)Integrator ==
       (int32_T)rtb_IProdOut_0)) {
    /* Update for DiscreteIntegrator: '<S206>/Integrator' incorporates:
     *  Constant: '<S196>/Constant1'
     */
    rtDW.Integrator_PREV_U = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S206>/Integrator' */
    rtDW.Integrator_PREV_U = rtb_IProdOut;
  }

  /* End of Switch: '<S196>/Switch' */
}

/* Output and update for atomic system: '<S2>/Clark_Trans' */
static void Clark_Trans(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic,
  real32_T *rty_ialpha, real32_T *rty_ibeta)
{
  /* Sum: '<S5>/Add1' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Sum: '<S5>/Add'
   */
  *rty_ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) * 0.333333343F;

  /* Gain: '<S5>/Gain2' incorporates:
   *  Sum: '<S5>/Add2'
   */
  *rty_ibeta = (rtu_ib - rtu_ic) * 0.577350259F;
}

/* Output and update for atomic system: '<S2>/Park_Trans' */
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

  /* Trigonometry: '<S7>/Cos' incorporates:
   *  Trigonometry: '<S7>/Sin'
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

  /* End of Trigonometry: '<S7>/Cos' */

  /* Trigonometry: '<S7>/Sin' */
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

  /* Sum: '<S7>/Add' incorporates:
   *  Product: '<S7>/Product'
   *  Product: '<S7>/Product1'
   */
  *rty_id = rtu_ialpha * yVarTmp + rtu_ibeta * *rty_iq;

  /* Sum: '<S7>/Add1' incorporates:
   *  Product: '<S7>/Product2'
   *  Product: '<S7>/Product3'
   */
  *rty_iq = rtu_ibeta * yVarTmp - rtu_ialpha * *rty_iq;
}

/* Output and update for atomic system: '<S9>/Anti_Park_Trans' */
static void Anti_Park_Trans(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta,
  real32_T *rty_ualpha, real32_T *rty_ubeta)
{
  real32_T rtb_Cos_m;

  /* Trigonometry: '<S165>/Cos' */
  rtb_Cos_m = cosf(rtu_theta);

  /* Trigonometry: '<S165>/Sin' */
  *rty_ubeta = sinf(rtu_theta);

  /* Sum: '<S165>/Add' incorporates:
   *  Product: '<S165>/Product'
   *  Product: '<S165>/Product1'
   */
  *rty_ualpha = rtu_ud * rtb_Cos_m - rtu_uq * *rty_ubeta;

  /* Sum: '<S165>/Add1' incorporates:
   *  Product: '<S165>/Product2'
   *  Product: '<S165>/Product3'
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
  int32_T rtb_soure;
  int32_T sector;
  real32_T rtb_DiscreteTimeIntegrator;
  real32_T rtb_DiscreteTimeIntegrator_tmp;
  real32_T rtb_Gain3;
  real32_T rtb_Integrator_d;
  real32_T rtb_Integrator_m;
  real32_T rtb_Integrator_p_tmp;
  real32_T rtb_Sum;
  real32_T rtb_Sum1;
  real32_T rtb_UnitDelay2;

  /* Gain: '<S6>/Gain2' incorporates:
   *  Inport: '<Root>/Ubus'
   */
  rtb_DiscreteTimeIntegrator = 0.519615233F * foc.Ubus;

  /* Chart: '<S3>/Chart1' incorporates:
   *  Inport: '<Root>/MotorSwitch'
   */
  if (rtDW.temporalCounter_i1 < 16383U) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c2_FOC_Model == 0U) {
    rtDW.is_active_c2_FOC_Model = 1U;
    rtDW.is_c2_FOC_Model = IN_IDLE;
    foc.motor_state = 1U;
    rtb_soure = 0;
  } else {
    switch (rtDW.is_c2_FOC_Model) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 10000U) {
        rtDW.is_c2_FOC_Model = IN_RunStage;
        foc.motor_state = 3U;
        rtb_soure = 1;
      } else if (motor_switch == 0) {
        rtDW.is_c2_FOC_Model = IN_IDLE;
        foc.motor_state = 1U;
        rtb_soure = 0;
      } else {
        foc.motor_state = 2U;
        rtb_soure = 0;
      }
      break;

     case IN_IDLE:
      if (motor_switch == 1) {
        rtDW.is_c2_FOC_Model = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
        foc.motor_state = 2U;
        rtb_soure = 0;
      } else {
        foc.motor_state = 1U;
        rtb_soure = 0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (motor_switch == 0) {
        rtDW.is_c2_FOC_Model = IN_IDLE;
        foc.motor_state = 1U;
        rtb_soure = 0;
      } else {
        foc.motor_state = 3U;
        rtb_soure = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* RateTransition: '<S1>/Rate Transition4' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.RateTransition4 = rtDW.RateTransition4_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition4' */

  /* SwitchCase: '<S3>/Switch Case1' */
  switch (foc.motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    /* Merge: '<S3>/Merge3' incorporates:
     *  Constant: '<S168>/Constant'
     */
    foc.theta_real = 0.0F;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S168>/Constant1'
     */
    foc.iq_ref = 0.0F;

    /* Merge: '<S3>/Merge2' incorporates:
     *  Constant: '<S168>/Constant2'
     */
    foc.id_ref = 0.0F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    /* Merge: '<S3>/Merge3' incorporates:
     *  Constant: '<S169>/Constant'
     */
    foc.theta_real = 0.0F;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Constant: '<S169>/Constant1'
     */
    foc.iq_ref = 0.0F;

    /* Merge: '<S3>/Merge2' incorporates:
     *  Constant: '<S169>/Constant2'
     */
    foc.id_ref = foc.id_align;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    /* Merge: '<S3>/Merge3' incorporates:
     *  Inport: '<Root>/theta'
     *  Inport: '<S170>/theta_Close'
     */
    foc.theta_real = foc.theta_input;

    /* Merge: '<S3>/Merge1' incorporates:
     *  Inport: '<S170>/iq_CloseRef'
     */
    foc.iq_ref = rtDW.RateTransition4;

    /* Merge: '<S3>/Merge2' incorporates:
     *  Constant: '<S170>/Constant2'
     */
    foc.id_ref = foc.id_gain;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S2>/Clark_Trans' */
  /* SignalConversion generated from: '<S2>/Clark_Trans' incorporates:
   *  Inport: '<Root>/ia'
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   */
  Clark_Trans(foc.ia, foc.ib, foc.ic, &(foc.i_alpha), &(foc.i_beta));

  /* End of Outputs for SubSystem: '<S2>/Clark_Trans' */

  /* Outputs for Atomic SubSystem: '<S2>/Park_Trans' */
  /* SignalConversion generated from: '<S2>/Park_Trans' */
  Park_Trans(foc.i_alpha, foc.i_beta, foc.theta_real, &(foc.id), &(foc.iq));

  /* End of Outputs for SubSystem: '<S2>/Park_Trans' */

  /* Sum: '<S6>/Sum1' */
  rtb_Sum1 = foc.id_ref - foc.id;

  /* Gain: '<S6>/Gain' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  rtb_Integrator_m = 200.0F * motor.Ls;

  /* Sum: '<S53>/Sum' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Product: '<S48>/PProd Out'
   */
  rtb_Sum = rtb_Sum1 * rtb_Integrator_m + rtDW.Integrator_DSTATE;

  /* Gain: '<S6>/Gain3' incorporates:
   *  Inport: '<Root>/Ubus'
   */
  rtb_Gain3 = -0.519615233F * foc.Ubus;

  /* Switch: '<S51>/Switch2' incorporates:
   *  RelationalOperator: '<S51>/LowerRelop1'
   *  RelationalOperator: '<S51>/UpperRelop'
   *  Switch: '<S51>/Switch'
   */
  if (rtb_Sum > rtb_DiscreteTimeIntegrator) {
    /* Switch: '<S51>/Switch2' */
    foc.ud = rtb_DiscreteTimeIntegrator;
  } else if (rtb_Sum < rtb_Gain3) {
    /* Switch: '<S51>/Switch' incorporates:
     *  Switch: '<S51>/Switch2'
     */
    foc.ud = rtb_Gain3;
  } else {
    /* Switch: '<S51>/Switch2' incorporates:
     *  Switch: '<S51>/Switch'
     */
    foc.ud = rtb_Sum;
  }

  /* End of Switch: '<S51>/Switch2' */

  /* Sum: '<S6>/Sum7' */
  rtb_Sum = foc.iq_ref - foc.iq;

  /* Sum: '<S102>/Sum' incorporates:
   *  DiscreteIntegrator: '<S92>/Integrator'
   *  Product: '<S97>/PProd Out'
   */
  rtb_Integrator_m = rtb_Sum * rtb_Integrator_m + rtDW.Integrator_DSTATE_o;

  /* Switch: '<S100>/Switch2' incorporates:
   *  RelationalOperator: '<S100>/LowerRelop1'
   *  RelationalOperator: '<S100>/UpperRelop'
   *  Switch: '<S100>/Switch'
   */
  if (rtb_Integrator_m > rtb_DiscreteTimeIntegrator) {
    /* Switch: '<S100>/Switch2' */
    foc.uq = rtb_DiscreteTimeIntegrator;
  } else if (rtb_Integrator_m < rtb_Gain3) {
    /* Switch: '<S100>/Switch' incorporates:
     *  Switch: '<S100>/Switch2'
     */
    foc.uq = rtb_Gain3;
  } else {
    /* Switch: '<S100>/Switch2' incorporates:
     *  Switch: '<S100>/Switch'
     */
    foc.uq = rtb_Integrator_m;
  }

  /* End of Switch: '<S100>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S9>/Anti_Park_Trans' */
  /* SignalConversion generated from: '<S9>/Anti_Park_Trans' */
  Anti_Park_Trans(foc.ud, foc.uq, foc.theta_real, &(foc.u_alpha), &(foc.u_beta));

  /* End of Outputs for SubSystem: '<S9>/Anti_Park_Trans' */

  /* MATLAB Function: '<S9>/foc' incorporates:
   *  Constant: '<S9>/Constant4'
   *  Inport: '<Root>/Ubus'
   */
  sector = 0;
  foc.Tcmp1 = 0.0F;
  foc.Tcmp2 = 0.0F;
  foc.Tcmp3 = 0.0F;
  if (foc.u_beta > 0.0F) {
    sector = 1;
  }

  if ((1.73205078F * foc.u_alpha - foc.u_beta) / 2.0F > 0.0F) {
    sector += 2;
  }

  if ((-1.73205078F * foc.u_alpha - foc.u_beta) / 2.0F > 0.0F) {
    sector += 4;
  }

  switch (sector) {
   case 1:
    rtb_Integrator_m = (-1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) *
      (16000.0F / foc.Ubus);
    rtb_DiscreteTimeIntegrator = (1.5F * foc.u_alpha + 0.866025388F * foc.u_beta)
      * (16000.0F / foc.Ubus);
    break;

   case 2:
    rtb_Integrator_m = (1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) *
      (16000.0F / foc.Ubus);
    rtb_DiscreteTimeIntegrator = -(1.73205078F * foc.u_beta * 16000.0F /
      foc.Ubus);
    break;

   case 3:
    rtb_Integrator_m = -((-1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) *
                         (16000.0F / foc.Ubus));
    rtb_DiscreteTimeIntegrator = 1.73205078F * foc.u_beta * 16000.0F / foc.Ubus;
    break;

   case 4:
    rtb_Integrator_m = -(1.73205078F * foc.u_beta * 16000.0F / foc.Ubus);
    rtb_DiscreteTimeIntegrator = (-1.5F * foc.u_alpha + 0.866025388F *
      foc.u_beta) * (16000.0F / foc.Ubus);
    break;

   case 5:
    rtb_Integrator_m = 1.73205078F * foc.u_beta * 16000.0F / foc.Ubus;
    rtb_DiscreteTimeIntegrator = -((1.5F * foc.u_alpha + 0.866025388F *
      foc.u_beta) * (16000.0F / foc.Ubus));
    break;

   default:
    rtb_Integrator_m = -((1.5F * foc.u_alpha + 0.866025388F * foc.u_beta) *
                         (16000.0F / foc.Ubus));
    rtb_DiscreteTimeIntegrator = -((-1.5F * foc.u_alpha + 0.866025388F *
      foc.u_beta) * (16000.0F / foc.Ubus));
    break;
  }

  rtb_Gain3 = rtb_Integrator_m + rtb_DiscreteTimeIntegrator;
  if (rtb_Gain3 > 16000.0F) {
    rtb_Integrator_m /= rtb_Gain3;
    rtb_DiscreteTimeIntegrator /= rtb_Integrator_m + rtb_DiscreteTimeIntegrator;
  }

  rtb_Gain3 = (16000.0F - (rtb_Integrator_m + rtb_DiscreteTimeIntegrator)) /
    4.0F;
  rtb_Integrator_m = rtb_Integrator_m / 2.0F + rtb_Gain3;
  switch (sector) {
   case 1:
    foc.Tcmp1 = rtb_Integrator_m;
    foc.Tcmp2 = rtb_Gain3;
    foc.Tcmp3 = rtb_DiscreteTimeIntegrator / 2.0F + rtb_Integrator_m;
    break;

   case 2:
    foc.Tcmp1 = rtb_Gain3;
    foc.Tcmp2 = rtb_DiscreteTimeIntegrator / 2.0F + rtb_Integrator_m;
    foc.Tcmp3 = rtb_Integrator_m;
    break;

   case 3:
    foc.Tcmp1 = rtb_Gain3;
    foc.Tcmp2 = rtb_Integrator_m;
    foc.Tcmp3 = rtb_DiscreteTimeIntegrator / 2.0F + rtb_Integrator_m;
    break;

   case 4:
    foc.Tcmp1 = rtb_DiscreteTimeIntegrator / 2.0F + rtb_Integrator_m;
    foc.Tcmp2 = rtb_Integrator_m;
    foc.Tcmp3 = rtb_Gain3;
    break;

   case 5:
    foc.Tcmp1 = rtb_DiscreteTimeIntegrator / 2.0F + rtb_Integrator_m;
    foc.Tcmp2 = rtb_Gain3;
    foc.Tcmp3 = rtb_Integrator_m;
    break;

   case 6:
    foc.Tcmp1 = rtb_Integrator_m;
    foc.Tcmp2 = rtb_DiscreteTimeIntegrator / 2.0F + rtb_Integrator_m;
    foc.Tcmp3 = rtb_Gain3;
    break;
  }

  foc.Sector = (real32_T)sector;

  /* End of MATLAB Function: '<S9>/foc' */

  /* UnitDelay: '<S2>/Unit Delay2' */
  rtb_UnitDelay2 = rtDW.UnitDelay2_DSTATE;

  /* Gain: '<S112>/Gain5' incorporates:
   *  Gain: '<S112>/Gain8'
   */
  rtb_DiscreteTimeIntegrator_tmp = motor.Ls * rtb_UnitDelay2;

  /* Sum: '<S112>/Sum1' incorporates:
   *  Gain: '<S112>/Gain5'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  rtb_DiscreteTimeIntegrator = rtDW.UnitDelay1_DSTATE -
    rtb_DiscreteTimeIntegrator_tmp;

  /* UnitDelay: '<S2>/Unit Delay1' */
  rtb_Integrator_m = rtDW.UnitDelay1_DSTATE_k;

  /* Gain: '<S112>/Gain1' incorporates:
   *  Gain: '<S112>/Gain3'
   */
  rtb_Integrator_p_tmp = motor.Ls * rtb_Integrator_m;

  /* Sum: '<S112>/Sum' incorporates:
   *  Gain: '<S112>/Gain1'
   *  UnitDelay: '<S112>/Unit Delay'
   */
  rtb_Integrator_d = rtDW.UnitDelay_DSTATE - rtb_Integrator_p_tmp;

  /* Sum: '<S112>/Add2' incorporates:
   *  Constant: '<S112>/Constant1'
   *  Math: '<S112>/Magnitude Squared'
   *  Math: '<S112>/Magnitude Squared1'
   *  Math: '<S112>/Magnitude Squared2'
   *  Sum: '<S112>/Add1'
   *
   * About '<S112>/Magnitude Squared':
   *  Operator: magnitude^2
   *
   * About '<S112>/Magnitude Squared1':
   *  Operator: magnitude^2
   *
   * About '<S112>/Magnitude Squared2':
   *  Operator: magnitude^2
   */
  rtb_Gain3 = motor.Flux * motor.Flux - (rtb_Integrator_d * rtb_Integrator_d +
    rtb_DiscreteTimeIntegrator * rtb_DiscreteTimeIntegrator);

  /* Sum: '<S112>/Add8' incorporates:
   *  Constant: '<S112>/Constant2'
   *  Gain: '<S112>/Gain6'
   *  Gain: '<S112>/Gain7'
   *  Product: '<S112>/Product1'
   *  Sum: '<S112>/Add6'
   *  Sum: '<S112>/Add7'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  rtb_DiscreteTimeIntegrator = (rtb_Gain3 * Gamma * rtb_DiscreteTimeIntegrator +
    (foc.u_beta - motor.Rs * rtb_UnitDelay2)) * foc.Ts + rtDW.UnitDelay1_DSTATE;

  /* Gain: '<S112>/Gain9' incorporates:
   *  Sum: '<S112>/Add9'
   */
  observer_flux.theta_sin = (rtb_DiscreteTimeIntegrator -
    rtb_DiscreteTimeIntegrator_tmp) * (1.0F / motor.Flux);

  /* Math: '<S111>/Mod' incorporates:
   *  Constant: '<S111>/Constant2'
   *  DiscreteIntegrator: '<S111>/Discrete-Time Integrator'
   */
  observer_flux.flux_theta = rt_modf_snf(rtDW.DiscreteTimeIntegrator_DSTATE,
    6.28318548F);

  /* Sum: '<S112>/Add4' incorporates:
   *  Constant: '<S112>/Constant'
   *  Gain: '<S112>/Gain'
   *  Gain: '<S112>/Gain2'
   *  Product: '<S112>/Product'
   *  Sum: '<S112>/Add'
   *  Sum: '<S112>/Add3'
   *  UnitDelay: '<S112>/Unit Delay'
   */
  rtb_UnitDelay2 = ((foc.u_alpha - motor.Rs * rtb_Integrator_m) + Gamma *
                    rtb_Integrator_d * rtb_Gain3) * foc.Ts +
    rtDW.UnitDelay_DSTATE;

  /* Gain: '<S112>/Gain4' incorporates:
   *  Sum: '<S112>/Add5'
   */
  observer_flux.theta_cos = (rtb_UnitDelay2 - rtb_Integrator_p_tmp) * (1.0F /
    motor.Flux);

  /* Sum: '<S111>/Add' incorporates:
   *  Product: '<S111>/Product'
   *  Product: '<S111>/Product1'
   *  Trigonometry: '<S111>/Sin'
   *  Trigonometry: '<S111>/Sin1'
   */
  rtb_Gain3 = observer_flux.theta_sin * cosf(observer_flux.flux_theta) -
    observer_flux.theta_cos * sinf(observer_flux.flux_theta);

  /* Sum: '<S157>/Sum' incorporates:
   *  Constant: '<S111>/Constant'
   *  DiscreteIntegrator: '<S148>/Integrator'
   *  Product: '<S153>/PProd Out'
   */
  rtb_Integrator_m = rtb_Gain3 * Flux_Kp + rtDW.Integrator_DSTATE_j;

  /* Saturate: '<S155>/Saturation' */
  if (rtb_Integrator_m > 3000.0F) {
    rtb_Integrator_m = 3000.0F;
  } else if (rtb_Integrator_m < -3000.0F) {
    rtb_Integrator_m = -3000.0F;
  }

  /* End of Saturate: '<S155>/Saturation' */

  /* Sum: '<S115>/Add1' incorporates:
   *  Constant: '<S115>/Filter_Constant'
   *  Constant: '<S115>/One'
   *  Gain: '<S8>/wm->Nr2'
   *  Product: '<S115>/Product'
   *  Product: '<S115>/Product1'
   *  UnitDelay: '<S115>/Unit Delay'
   */
  observer_flux.flux_spd = 30.0F / (3.14159274F * motor.Pn) * rtb_Integrator_m *
    0.031F + 0.969F * observer_flux.flux_spd;

  /* Outport: '<Root>/Outport2' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  rtY.Outport2 = (int32_T)floorf(observer_flux.flux_spd);

  /* Gain: '<S6>/Gain1' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  rtb_Integrator_d = 200.0F * motor.Rs;

  /* RateTransition: '<S1>/Rate Transition3' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition3 = (real32_T)rtb_soure;

    /* RateTransition: '<S1>/Rate Transition1' incorporates:
     *  Inport: '<Root>/Spd_fdbk'
     */
    rtDW.RateTransition1 = foc.spd_fdbk;

    /* RateTransition: '<S1>/Rate Transition2' incorporates:
     *  Inport: '<Root>/Spd_ref'
     */
    rtDW.RateTransition2 = foc.spd_ref;

    /* S-Function (fcgen): '<S1>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S1>/speed_loop'
     */
    speed_loop();

    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator2' */

    /* Update for RateTransition: '<S1>/Rate Transition4' */
    rtDW.RateTransition4_Buffer0 = rtDW.Switch2;
  }

  /* End of RateTransition: '<S1>/Rate Transition3' */

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Product: '<S40>/IProd Out'
   */
  rtDW.Integrator_DSTATE += rtb_Sum1 * rtb_Integrator_d * 0.0001F;

  /* Update for DiscreteIntegrator: '<S92>/Integrator' incorporates:
   *  Product: '<S89>/IProd Out'
   */
  rtDW.Integrator_DSTATE_o += rtb_Sum * rtb_Integrator_d * 0.0001F;

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = foc.i_beta;

  /* Update for UnitDelay: '<S112>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = rtb_DiscreteTimeIntegrator;

  /* Update for UnitDelay: '<S112>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_UnitDelay2;

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE_k = foc.i_alpha;

  /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_DSTATE += 0.0001F * rtb_Integrator_m;

  /* Update for DiscreteIntegrator: '<S148>/Integrator' incorporates:
   *  Constant: '<S111>/Constant1'
   *  Product: '<S145>/IProd Out'
   */
  rtDW.Integrator_DSTATE_j += rtb_Gain3 * Flux_Ki * 0.0001F;
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
