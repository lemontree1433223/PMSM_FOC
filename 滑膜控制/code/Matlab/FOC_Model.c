/*
 * File: FOC_Model.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.26
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Sun Apr  7 14:31:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "FOC_Model.h"
#include "main.h"
/* Named constants for Chart: '<S2>/Chart1' */
#define IN_AlignStage                  ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

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
static void fourth_SMO_Init(DW_fourth_SMO *localDW);
static void fourth_SMO(real32_T rtu_Ualpha, real32_T rtu_U_beta, real32_T
  rtu_Ialpha, real32_T rtu_Ibeta, real32_T *rty_Obe_Theta, real32_T *rty_omega_e,
  DW_fourth_SMO *localDW);
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
  rtb_IProdOut = rtDW.RateTransition2 - rtDW.RateTransition1;

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

  /* Sum: '<S215>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S211>/PProd Out'
   */
  rtb_Sum = rtb_IProdOut * 0.0144F + Integrator;

  /* DeadZone: '<S199>/DeadZone' incorporates:
   *  Saturate: '<S213>/Saturation'
   */
  if (rtb_Sum > 5.0F) {
    rtb_SignPreIntegrator = rtb_Sum - 5.0F;

    /* Saturate: '<S213>/Saturation' */
    rtDW.Saturation = 5.0F;
  } else {
    if (rtb_Sum >= -5.0F) {
      rtb_SignPreIntegrator = 0.0F;
    } else {
      rtb_SignPreIntegrator = rtb_Sum - -5.0F;
    }

    if (rtb_Sum < -5.0F) {
      /* Saturate: '<S213>/Saturation' */
      rtDW.Saturation = -5.0F;
    } else {
      /* Saturate: '<S213>/Saturation' */
      rtDW.Saturation = rtb_Sum;
    }
  }

  /* End of DeadZone: '<S199>/DeadZone' */

  /* Product: '<S203>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_IProdOut *= 0.6389F;

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

  /* Signum: '<S197>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    Integrator = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    Integrator = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    Integrator = 0.0F;
  } else {
    Integrator = (rtNaNF);
  }

  /* End of Signum: '<S197>/SignPreSat' */

  /* Signum: '<S197>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut_0 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut_0 = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut_0 = 0.0F;
  } else {
    rtb_IProdOut_0 = (rtNaNF);
  }

  /* End of Signum: '<S197>/SignPreIntegrator' */

  /* Switch: '<S197>/Switch' incorporates:
   *  DataTypeConversion: '<S197>/DataTypeConv1'
   *  DataTypeConversion: '<S197>/DataTypeConv2'
   *  Gain: '<S197>/ZeroGain'
   *  Logic: '<S197>/AND3'
   *  RelationalOperator: '<S197>/Equal1'
   *  RelationalOperator: '<S197>/NotEqual'
   */
  if ((0.0F * rtb_Sum != rtb_SignPreIntegrator) && ((int8_T)Integrator ==
       (int8_T)rtb_IProdOut_0)) {
    /* Update for DiscreteIntegrator: '<S206>/Integrator' incorporates:
     *  Constant: '<S197>/Constant1'
     */
    rtDW.Integrator_PREV_U = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S206>/Integrator' */
    rtDW.Integrator_PREV_U = rtb_IProdOut;
  }

  /* End of Switch: '<S197>/Switch' */
}

/* Output and update for atomic system: '<S3>/Clark_Trans' */
static void Clark_Trans(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic,
  real32_T *rty_ialpha, real32_T *rty_ibeta)
{
  /* Sum: '<S10>/Add1' incorporates:
   *  Gain: '<S10>/Gain'
   *  Gain: '<S10>/Gain1'
   *  Sum: '<S10>/Add'
   */
  *rty_ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) * 0.333333343F;

  /* Gain: '<S10>/Gain2' incorporates:
   *  Sum: '<S10>/Add2'
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

  /* Trigonometry: '<S12>/Cos' incorporates:
   *  Trigonometry: '<S12>/Sin'
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

  /* End of Trigonometry: '<S12>/Cos' */

  /* Trigonometry: '<S12>/Sin' */
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

  /* Sum: '<S12>/Add' incorporates:
   *  Product: '<S12>/Product'
   *  Product: '<S12>/Product1'
   */
  *rty_id = rtu_ialpha * yVarTmp + rtu_ibeta * *rty_iq;

  /* Sum: '<S12>/Add1' incorporates:
   *  Product: '<S12>/Product2'
   *  Product: '<S12>/Product3'
   */
  *rty_iq = rtu_ibeta * yVarTmp - rtu_ialpha * *rty_iq;
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

/* System initialize for atomic system: '<S13>/fourth_SMO' */
static void fourth_SMO_Init(DW_fourth_SMO *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S153>/Integrator' */
  localDW->Integrator_DSTATE = 50.0F;
}

/* Output and update for atomic system: '<S13>/fourth_SMO' */
static void fourth_SMO(real32_T rtu_Ualpha, real32_T rtu_U_beta, real32_T
  rtu_Ialpha, real32_T rtu_Ibeta, real32_T *rty_Obe_Theta, real32_T *rty_omega_e,
  DW_fourth_SMO *localDW)
{
  real32_T rtb_Divide2;
  real32_T rtb_Divide2_f;
  real32_T rtb_Divide3_d;
  real32_T rtb_Divide4;
  real32_T rtb_Product1_j;
  real32_T rtb_Product2_c;
  real32_T rtb_Product3_h;
  real32_T rtb_Product_a;
  real32_T rtb_Sign1;
  real32_T rtb_UnitDelay1;
  real32_T rtb_UnitDelay_p;

  /* Math: '<S114>/Mod' incorporates:
   *  Constant: '<S114>/Constant2'
   *  DiscreteIntegrator: '<S114>/Discrete-Time Integrator'
   */
  *rty_Obe_Theta = rt_modf_snf(localDW->DiscreteTimeIntegrator_DSTATE,
    6.28318548F);

  /* Signum: '<S114>/Sign' incorporates:
   *  UnitDelay: '<S114>/Unit Delay'
   */
  if (localDW->UnitDelay_DSTATE < 0.0F) {
    rtb_UnitDelay1 = -1.0F;
  } else if (localDW->UnitDelay_DSTATE > 0.0F) {
    rtb_UnitDelay1 = 1.0F;
  } else if (localDW->UnitDelay_DSTATE == 0.0F) {
    rtb_UnitDelay1 = 0.0F;
  } else {
    rtb_UnitDelay1 = (rtNaNF);
  }

  /* End of Signum: '<S114>/Sign' */

  /* Product: '<S114>/Product' incorporates:
   *  Product: '<S114>/Product1'
   *  Product: '<S114>/Product2'
   *  Sum: '<S114>/Sum'
   *  Trigonometry: '<S114>/Cos1'
   *  Trigonometry: '<S114>/Sin1'
   *  UnitDelay: '<S115>/Unit Delay2'
   *  UnitDelay: '<S116>/Unit Delay3'
   */
  rtb_UnitDelay1 *= (0.0F - localDW->UnitDelay2_DSTATE * cosf(*rty_Obe_Theta)) -
    sinf(*rty_Obe_Theta) * localDW->UnitDelay3_DSTATE;

  /* Sum: '<S162>/Sum' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S114>/Constant1'
   *  DiscreteIntegrator: '<S153>/Integrator'
   *  Gain: '<S114>/Gain'
   *  Product: '<S114>/Product3'
   *  Product: '<S158>/PProd Out'
   */
  *rty_omega_e = rtb_UnitDelay1 * 203.616013F + localDW->Integrator_DSTATE;

  /* DeadZone: '<S146>/DeadZone' */
  if (*rty_omega_e > 3000.0F) {
    rtb_UnitDelay_p = *rty_omega_e - 3000.0F;
  } else if (*rty_omega_e >= -3000.0F) {
    rtb_UnitDelay_p = 0.0F;
  } else {
    rtb_UnitDelay_p = *rty_omega_e - -3000.0F;
  }

  /* End of DeadZone: '<S146>/DeadZone' */

  /* Product: '<S150>/IProd Out' incorporates:
   *  Constant: '<S114>/Constant1'
   *  Math: '<S114>/Square'
   */
  rtb_UnitDelay1 *= 8100.0F;

  /* Signum: '<S144>/SignPreSat' */
  if (rtb_UnitDelay_p < 0.0F) {
    rtb_Product2_c = -1.0F;
  } else if (rtb_UnitDelay_p > 0.0F) {
    rtb_Product2_c = 1.0F;
  } else if (rtb_UnitDelay_p == 0.0F) {
    rtb_Product2_c = 0.0F;
  } else {
    rtb_Product2_c = (rtNaNF);
  }

  /* End of Signum: '<S144>/SignPreSat' */

  /* Signum: '<S144>/SignPreIntegrator' */
  if (rtb_UnitDelay1 < 0.0F) {
    rtb_Divide4 = -1.0F;
  } else if (rtb_UnitDelay1 > 0.0F) {
    rtb_Divide4 = 1.0F;
  } else if (rtb_UnitDelay1 == 0.0F) {
    rtb_Divide4 = 0.0F;
  } else {
    rtb_Divide4 = (rtNaNF);
  }

  /* End of Signum: '<S144>/SignPreIntegrator' */

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S144>/Constant1'
   *  DataTypeConversion: '<S144>/DataTypeConv1'
   *  DataTypeConversion: '<S144>/DataTypeConv2'
   *  Gain: '<S144>/ZeroGain'
   *  Logic: '<S144>/AND3'
   *  RelationalOperator: '<S144>/Equal1'
   *  RelationalOperator: '<S144>/NotEqual'
   */
  if ((0.0F * *rty_omega_e != rtb_UnitDelay_p) && ((int8_T)rtb_Product2_c ==
       (int8_T)rtb_Divide4)) {
    rtb_UnitDelay_p = 0.0F;
  } else {
    rtb_UnitDelay_p = rtb_UnitDelay1;
  }

  /* End of Switch: '<S144>/Switch' */

  /* Saturate: '<S160>/Saturation' */
  if (*rty_omega_e > 3000.0F) {
    *rty_omega_e = 3000.0F;
  } else if (*rty_omega_e < -3000.0F) {
    *rty_omega_e = -3000.0F;
  }

  /* End of Saturate: '<S160>/Saturation' */

  /* Product: '<S115>/Product2' incorporates:
   *  UnitDelay: '<S116>/Unit Delay3'
   */
  rtb_Product2_c = *rty_omega_e * localDW->UnitDelay3_DSTATE;

  /* Sum: '<S113>/Sum2' incorporates:
   *  UnitDelay: '<S117>/Unit Delay'
   */
  rtb_Sign1 = localDW->UnitDelay_DSTATE_p - rtu_Ialpha;

  /* Signum: '<S113>/Sign' */
  if (rtb_Sign1 < 0.0F) {
    rtb_UnitDelay1 = -1.0F;
  } else if (rtb_Sign1 > 0.0F) {
    rtb_UnitDelay1 = 1.0F;
  } else if (rtb_Sign1 == 0.0F) {
    rtb_UnitDelay1 = 0.0F;
  } else {
    rtb_UnitDelay1 = (rtNaNF);
  }

  /* End of Signum: '<S113>/Sign' */

  /* Product: '<S117>/Divide4' incorporates:
   *  Constant: '<S117>/Constant'
   *  Gain: '<S117>/Gain'
   *  UnitDelay: '<S117>/Unit Delay'
   */
  rtb_Divide4 = 0.112F * localDW->UnitDelay_DSTATE_p / 2.235E-5F;

  /* Product: '<S117>/Product' incorporates:
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  rtb_Product_a = localDW->UnitDelay1_DSTATE * *rty_omega_e;

  /* Product: '<S117>/Divide2' incorporates:
   *  Constant: '<S117>/Constant'
   *  UnitDelay: '<S115>/Unit Delay2'
   */
  rtb_Divide2 = localDW->UnitDelay2_DSTATE / 2.235E-5F;

  /* Sum: '<S113>/Sum6' incorporates:
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  rtb_Sign1 = localDW->UnitDelay1_DSTATE - rtu_Ibeta;

  /* Signum: '<S113>/Sign1' */
  if (rtb_Sign1 < 0.0F) {
    rtb_Sign1 = -1.0F;
  } else if (rtb_Sign1 > 0.0F) {
    rtb_Sign1 = 1.0F;
  } else if (rtb_Sign1 == 0.0F) {
    rtb_Sign1 = 0.0F;
  } else {
    rtb_Sign1 = (rtNaNF);
  }

  /* End of Signum: '<S113>/Sign1' */

  /* Product: '<S116>/Product3' incorporates:
   *  UnitDelay: '<S115>/Unit Delay2'
   */
  rtb_Product3_h = *rty_omega_e * localDW->UnitDelay2_DSTATE;

  /* Product: '<S118>/Product1' incorporates:
   *  UnitDelay: '<S117>/Unit Delay'
   */
  rtb_Product1_j = localDW->UnitDelay_DSTATE_p * *rty_omega_e;

  /* Product: '<S118>/Divide3' incorporates:
   *  Constant: '<S118>/Constant'
   *  Gain: '<S118>/Gain8'
   *  UnitDelay: '<S118>/Unit Delay1'
   */
  rtb_Divide3_d = 0.112F * localDW->UnitDelay1_DSTATE / 2.235E-5F;

  /* Product: '<S118>/Divide2' incorporates:
   *  Constant: '<S118>/Constant'
   *  UnitDelay: '<S116>/Unit Delay3'
   */
  rtb_Divide2_f = localDW->UnitDelay3_DSTATE / 2.235E-5F;

  /* Update for DiscreteIntegrator: '<S114>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE += 0.0001F * *rty_omega_e;

  /* Update for UnitDelay: '<S115>/Unit Delay2' incorporates:
   *  DiscreteIntegrator: '<S115>/Discrete-Time Integrator'
   */
  localDW->UnitDelay2_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_i;

  /* Update for UnitDelay: '<S116>/Unit Delay3' incorporates:
   *  DiscreteIntegrator: '<S116>/Discrete-Time Integrator'
   */
  localDW->UnitDelay3_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_p;

  /* Update for UnitDelay: '<S114>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_omega_e;

  /* Update for DiscreteIntegrator: '<S153>/Integrator' */
  localDW->Integrator_DSTATE += 0.0001F * rtb_UnitDelay_p;

  /* Update for UnitDelay: '<S117>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S117>/Discrete-Time Integrator'
   */
  localDW->UnitDelay_DSTATE_p = localDW->DiscreteTimeIntegrator_DSTATE_c;

  /* Update for UnitDelay: '<S118>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S118>/Discrete-Time Integrator'
   */
  localDW->UnitDelay1_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_m;

  /* Update for DiscreteIntegrator: '<S115>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S115>/Constant'
   *  Gain: '<S115>/Gain3'
   *  Product: '<S115>/Divide'
   *  Sum: '<S115>/Add2'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_i += (0.001F * rtb_UnitDelay1 /
    2.235E-5F - rtb_Product2_c) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S116>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S116>/Constant'
   *  Gain: '<S116>/Gain1'
   *  Product: '<S116>/Divide'
   *  Sum: '<S116>/Add3'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_p += (0.001F * rtb_Sign1 / 2.235E-5F +
    rtb_Product3_h) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S117>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S117>/Constant'
   *  Gain: '<S117>/Gain3'
   *  Product: '<S117>/Divide1'
   *  Product: '<S117>/Divide3'
   *  Product: '<S117>/Product1'
   *  Product: '<S117>/Product2'
   *  Sum: '<S117>/Add'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_c += ((((rtu_Ualpha / 2.235E-5F -
    rtb_Divide4) - -3.32000127E-6F * rtb_Product_a / 2.235E-5F) - rtb_Divide2) -
    0.1F * rtb_UnitDelay1 * 44742.7305F) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S118>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S118>/Constant'
   *  Gain: '<S118>/Gain1'
   *  Product: '<S118>/Divide'
   *  Product: '<S118>/Divide1'
   *  Product: '<S118>/Divide4'
   *  Product: '<S118>/Product'
   *  Sum: '<S118>/Add1'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_m += ((((-3.32000127E-6F *
    rtb_Product1_j / 2.235E-5F - rtb_Divide3_d) - rtb_Divide2_f) + rtu_U_beta /
    2.235E-5F) - 0.1F * rtb_Sign1 / 2.235E-5F) * 0.0001F;
}

/* Output and update for atomic system: '<S14>/Anti_Park_Trans' */
static void Anti_Park_Trans(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta,
  real32_T *rty_ualpha, real32_T *rty_ubeta)
{
  real32_T rtb_Cos_m;

  /* Trigonometry: '<S170>/Cos' */
  rtb_Cos_m = cosf(rtu_theta);

  /* Trigonometry: '<S170>/Sin' */
  *rty_ubeta = sinf(rtu_theta);

  /* Sum: '<S170>/Add' incorporates:
   *  Product: '<S170>/Product'
   *  Product: '<S170>/Product1'
   */
  *rty_ualpha = rtu_ud * rtb_Cos_m - rtu_uq * *rty_ubeta;

  /* Sum: '<S170>/Add1' incorporates:
   *  Product: '<S170>/Product2'
   *  Product: '<S170>/Product3'
   */
  *rty_ubeta = rtu_ud * *rty_ubeta + rtu_uq * rtb_Cos_m;
}

/* Model step function */
void FOC_Model_step(void)
{
  int32_T rtb_Motor_state;
  int32_T rtb_soure;
  real32_T T1;
  real32_T rtb_Add1;
  real32_T rtb_Gain1;
  real32_T rtb_Gain2;
  real32_T rtb_Saturation_l;
  real32_T rtb_Sum1;
  real32_T rtb_Sum7;
  real32_T rtb_real;
  real32_T ta;

  /* Outputs for Atomic SubSystem: '<S3>/Clark_Trans' */
  /* Inport: '<Root>/ia' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   */
  Clark_Trans(rtU.ia, rtU.ib, rtU.ic, &rtb_Add1, &rtb_Gain2);

  /* End of Outputs for SubSystem: '<S3>/Clark_Trans' */

  /* Chart: '<S2>/Chart1' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Inport: '<Root>/MotorSwitch'
   */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c7_FOC_Model == 0U) {
    rtDW.is_active_c7_FOC_Model = 1U;
    rtDW.is_c7_FOC_Model = IN_IDLE;
    rtb_Motor_state = 1;
    rtb_soure = 0;
  } else {
    switch (rtDW.is_c7_FOC_Model) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000U) {
        rtDW.is_c7_FOC_Model = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
        rtb_Motor_state = 3;
        rtb_soure = 0;
      } else if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
        rtb_Motor_state = 1;
        rtb_soure = 0;
      } else {
        rtb_Motor_state = 2;
        rtb_soure = 0;
      }
      break;

     case IN_IDLE:
      if (rtU.MotorSwitch == 1.0F) {
        rtDW.is_c7_FOC_Model = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
        rtb_Motor_state = 2;
        rtb_soure = 0;
      } else {
        rtb_Motor_state = 1;
        rtb_soure = 0;
      }
      break;

     case IN_OpenStage:
      if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
        rtb_Motor_state = 1;
        rtb_soure = 0;
      } else if (rtDW.temporalCounter_i1 >= 30000U) {
        rtDW.is_c7_FOC_Model = IN_RunStage;
        rtb_Motor_state = 4;
        rtb_soure = 1;
      } else {
        rtb_Motor_state = 3;
        rtb_soure = 0;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
        rtb_Motor_state = 1;
        rtb_soure = 0;
      } else {
        rtb_Motor_state = 4;
        rtb_soure = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* RateTransition: '<S1>/Rate Transition4' */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.RateTransition4 = rtDW.RateTransition4_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition4' */

  /* SwitchCase: '<S2>/Switch Case1' */
  switch (rtb_Motor_state) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Constant: '<S6>/Constant'
     */
    rtDW.theat_Extern = 0.0F;

    /* Merge: '<S2>/Merge4' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    rtDW.id_ExternRef = 0.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtDW.theat_Extern = 0.0F;

    /* Merge: '<S2>/Merge4' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    rtDW.id_ExternRef = 2.0F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Constant: '<S8>/Constant'
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
     *  Math: '<S8>/Mod'
     *  SignalConversion generated from: '<S8>/theta_fd'
     */
    rtDW.theat_Extern = rt_modf_snf(rtDW.DiscreteTimeIntegrator1_DSTATE,
      6.28318548F);

    /* Merge: '<S2>/Merge4' incorporates:
     *  Constant: '<S2>/Constant14'
     *  Inport: '<S8>/OPL_iqref'
     */
    rtDW.id_ExternRef = 5.0F;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' incorporates:
     *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
     */
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F *
      rtDW.DiscreteTimeIntegrator_DSTATE;

    /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S2>/Constant12'
     *  Constant: '<S8>/Constant1'
     *  Product: '<S8>/Divide'
     *  Product: '<S8>/Product'
     */
    rtDW.DiscreteTimeIntegrator_DSTATE += 0.00977384299F;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Merge: '<S2>/Merge3' incorporates:
     *  Inport: '<S9>/theta_Close'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    rtDW.theat_Extern = normalize_angle(rtDW.UnitDelay_DSTATE + 4.6);//rtDW.UnitDelay_DSTATE;

    /* Merge: '<S2>/Merge4' incorporates:
     *  Inport: '<S9>/iq_CloseRef'
     */
    rtDW.id_ExternRef = rtDW.RateTransition4;

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case1' */

  /* Outputs for Atomic SubSystem: '<S3>/Park_Trans' */
  Park_Trans(rtb_Add1, rtb_Gain2, rtDW.theat_Extern, &rtb_Saturation_l,
             &rtb_Gain1);

  /* End of Outputs for SubSystem: '<S3>/Park_Trans' */

  /* Sum: '<S11>/Sum1' incorporates:
   *  Inport: '<Root>/id_ref'
   */
  rtb_Sum1 = rtU.id_ref - rtb_Saturation_l;

  /* Sum: '<S11>/Sum7' */
  rtb_Sum7 = rtDW.id_ExternRef - rtb_Gain1;

  /* Sum: '<S105>/Sum' incorporates:
   *  DiscreteIntegrator: '<S96>/Integrator'
   *  Product: '<S101>/PProd Out'
   */
  rtb_real = rtb_Sum7 * 0.00447F + rtDW.Integrator_DSTATE_o;

  /* Sum: '<S57>/Sum' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Product: '<S53>/PProd Out'
   */
  rtb_Saturation_l = rtb_Sum1 * 0.00447F + rtDW.Integrator_DSTATE;

  /* Saturate: '<S55>/Saturation' */
  if (rtb_Saturation_l > 6.23538303F) {
    rtb_Saturation_l = 6.23538303F;
  } else if (rtb_Saturation_l < -6.23538303F) {
    rtb_Saturation_l = -6.23538303F;
  }

  /* End of Saturate: '<S55>/Saturation' */

  /* Saturate: '<S103>/Saturation' */
  if (rtb_real > 6.23538303F) {
    T1 = 6.23538303F;
  } else if (rtb_real < -6.23538303F) {
    T1 = -6.23538303F;
  } else {
    T1 = rtb_real;
  }

  /* End of Saturate: '<S103>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S14>/Anti_Park_Trans' */
  Anti_Park_Trans(rtb_Saturation_l, T1, rtDW.theat_Extern, &rtb_Gain1, &rtb_real);

  /* End of Outputs for SubSystem: '<S14>/Anti_Park_Trans' */

  /* MATLAB Function: '<S14>/foc' */
  rtb_Motor_state = 0;

  /* Outport: '<Root>/Tcmp1' incorporates:
   *  MATLAB Function: '<S14>/foc'
   */
  rtY.Tcmp1 = 0.0F;

  /* Outport: '<Root>/Tcmp2' incorporates:
   *  MATLAB Function: '<S14>/foc'
   */
  rtY.Tcmp2 = 0.0F;

  /* Outport: '<Root>/Tcmp3' incorporates:
   *  MATLAB Function: '<S14>/foc'
   */
  rtY.Tcmp3 = 0.0F;

  /* MATLAB Function: '<S14>/foc' incorporates:
   *  Constant: '<S14>/Constant4'
   *  Inport: '<Root>/Ubus'
   */
  if (rtb_real > 0.0F) {
    rtb_Motor_state = 1;
  }

  if ((1.73205078F * rtb_Gain1 - rtb_real) / 2.0F > 0.0F) {
    rtb_Motor_state += 2;
  }

  if ((-1.73205078F * rtb_Gain1 - rtb_real) / 2.0F > 0.0F) {
    rtb_Motor_state += 4;
  }

  switch (rtb_Motor_state) {
   case 1:
    T1 = (-1.5F * rtb_Gain1 + 0.866025388F * rtb_real) * (16000.0F / rtU.Ubus);
    rtb_Saturation_l = (1.5F * rtb_Gain1 + 0.866025388F * rtb_real) * (16000.0F /
      rtU.Ubus);
    break;

   case 2:
    T1 = (1.5F * rtb_Gain1 + 0.866025388F * rtb_real) * (16000.0F / rtU.Ubus);
    rtb_Saturation_l = -(1.73205078F * rtb_real * 16000.0F / rtU.Ubus);
    break;

   case 3:
    T1 = -((-1.5F * rtb_Gain1 + 0.866025388F * rtb_real) * (16000.0F / rtU.Ubus));
    rtb_Saturation_l = 1.73205078F * rtb_real * 16000.0F / rtU.Ubus;
    break;

   case 4:
    T1 = -(1.73205078F * rtb_real * 16000.0F / rtU.Ubus);
    rtb_Saturation_l = (-1.5F * rtb_Gain1 + 0.866025388F * rtb_real) * (16000.0F
      / rtU.Ubus);
    break;

   case 5:
    T1 = 1.73205078F * rtb_real * 16000.0F / rtU.Ubus;
    rtb_Saturation_l = -((1.5F * rtb_Gain1 + 0.866025388F * rtb_real) *
                         (16000.0F / rtU.Ubus));
    break;

   default:
    T1 = -((1.5F * rtb_Gain1 + 0.866025388F * rtb_real) * (16000.0F / rtU.Ubus));
    rtb_Saturation_l = -((-1.5F * rtb_Gain1 + 0.866025388F * rtb_real) *
                         (16000.0F / rtU.Ubus));
    break;
  }

  ta = T1 + rtb_Saturation_l;
  if (ta > 16000.0F) {
    T1 /= ta;
    rtb_Saturation_l /= T1 + rtb_Saturation_l;
  }

  ta = (16000.0F - (T1 + rtb_Saturation_l)) / 4.0F;
  T1 = T1 / 2.0F + ta;
  switch (rtb_Motor_state) {
   case 1:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = ta;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Saturation_l / 2.0F + T1;
    break;

   case 2:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = ta;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Saturation_l / 2.0F + T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = T1;
    break;

   case 3:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = ta;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Saturation_l / 2.0F + T1;
    break;

   case 4:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Saturation_l / 2.0F + T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = ta;
    break;

   case 5:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Saturation_l / 2.0F + T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = ta;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = T1;
    break;

   case 6:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Saturation_l / 2.0F + T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = ta;
    break;
  }

  /* Outport: '<Root>/Sector' incorporates:
   *  MATLAB Function: '<S14>/foc'
   */
  rtY.Sector = (real32_T)rtb_Motor_state;

  /* Outputs for Atomic SubSystem: '<S13>/fourth_SMO' */
  fourth_SMO(rtb_Gain1, rtb_real, rtb_Add1, rtb_Gain2, &ta, &rtb_Saturation_l,
             &rtDW.fourth_SMO_h);

  /* End of Outputs for SubSystem: '<S13>/fourth_SMO' */

  /* Gain: '<S13>/wm->Nr2' */
  rtb_real = 1.36418521F * rtb_Saturation_l;

  /* RateTransition: '<S1>/Rate Transition1' incorporates:
   *  RateTransition: '<S1>/Rate Transition4'
   */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtDW.RateTransition1 = rtb_real;

    /* RateTransition: '<S1>/Rate Transition2' incorporates:
     *  Inport: '<Root>/Spd_ref'
     */
    rtDW.RateTransition2 = rtU.Spd_ref;

    /* RateTransition: '<S1>/Rate Transition3' */
    rtDW.RateTransition3 = (real32_T)rtb_soure;

    /* S-Function (fcgen): '<S1>/Function-Call Generator2' incorporates:
     *  SubSystem: '<S1>/speed_loop'
     */
    speed_loop();

    /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator2' */
    rtDW.RateTransition4_Buffer0 = rtDW.Saturation;
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* Outport: '<Root>/Outport3' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtY.Outport3 = rtDW.UnitDelay_DSTATE;

  /* Outport: '<Root>/Outport4' */
  rtY.Outport4 = rtb_real;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = ta;

  /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
   *  Product: '<S45>/IProd Out'
   */
  rtDW.Integrator_DSTATE += rtb_Sum1 * 22.4000015F * 0.0001F;

  /* Update for DiscreteIntegrator: '<S96>/Integrator' incorporates:
   *  Product: '<S93>/IProd Out'
   */
  rtDW.Integrator_DSTATE_o += rtb_Sum7 * 22.4000015F * 0.0001F;
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

  /* SystemInitialize for Atomic SubSystem: '<S13>/fourth_SMO' */
  fourth_SMO_Init(&rtDW.fourth_SMO_h);

  /* End of SystemInitialize for SubSystem: '<S13>/fourth_SMO' */

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
