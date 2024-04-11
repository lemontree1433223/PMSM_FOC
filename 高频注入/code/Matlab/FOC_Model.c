/*
 * File: FOC_Model.c
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Tue Apr  9 17:54:09 2024
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
#define IN_OpenStage                   ((uint8_T)3U)
#define IN_RunStage                    ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define IN_HFI_NS                      ((uint8_T)1U)
#define IN_HFI_OVER1                   ((uint8_T)2U)
#define IN_HFI_START                   ((uint8_T)3U)
#define IN_IDLE_h                      ((uint8_T)4U)
#define IN_INJECT_NEGAT                ((uint8_T)5U)
#define IN_INJECT_POSIT                ((uint8_T)6U)
#define NumBitsPerChar                 8U
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

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

/* Exported block signals */
real32_T hfi_theta;                    /* '<S3>/Merge2' */
real32_T ud;                           /* '<S3>/Add' */
real32_T uq;                           /* '<S115>/Saturation' */
real32_T ns_single;                    /* '<S17>/Merge' */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

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
static void IfActionSubsystem5(real32_T *rty_Out1);
static void Park_Trans(real32_T rtu_ialpha, real32_T rtu_ibeta, real32_T
  rtu_theta, real32_T *rty_id, real32_T *rty_iq);
static void fourth_SMO_Init(DW_fourth_SMO *localDW);
static void fourth_SMO(real32_T rtu_Ualpha, real32_T rtu_U_beta, real32_T
  rtu_Ialpha, real32_T rtu_Ibeta, real32_T *rty_Obe_Theta, real32_T *rty_omega_e,
  DW_fourth_SMO *localDW);
static void Anti_Park_Trans(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta,
  real32_T *rty_ualpha, real32_T *rty_ubeta);
static void speed_loop_Enable(void);
static void speed_loop(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
static ZCEventType rt_R32ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real32_T
  currValue);
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

/* Detect zero crossings events. */
static ZCEventType rt_R32ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, real32_T
  currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc)) &
    (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_R32ZCFcn */

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

/* Enable for function-call system: '<S1>/speed_loop' */
static void speed_loop_Enable(void)
{
  rtDW.speed_loop_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S270>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE_b = 1U;
}

/* Output and update for function-call system: '<S1>/speed_loop' */
static void speed_loop(void)
{
  real32_T Integrator_e;
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

  /* DiscreteIntegrator: '<S270>/Integrator' */
  if (rtDW.Integrator_SYSTEM_ENABLE_b != 0) {
    /* DiscreteIntegrator: '<S270>/Integrator' */
    Integrator_e = rtDW.Integrator_DSTATE_d;
  } else {
    /* DiscreteIntegrator: '<S270>/Integrator' */
    Integrator_e = 0.001F * (real32_T)speed_loop_ELAPS_T
      * rtDW.Integrator_PREV_U_c + rtDW.Integrator_DSTATE_d;
  }

  /* End of DiscreteIntegrator: '<S270>/Integrator' */

  /* Sum: '<S279>/Sum' incorporates:
   *  Constant: '<S4>/Constant'
   *  Product: '<S275>/PProd Out'
   */
  rtb_Sum = rtb_IProdOut * 0.0144F + Integrator_e;

  /* DeadZone: '<S263>/DeadZone' incorporates:
   *  Saturate: '<S277>/Saturation'
   */
  if (rtb_Sum > 5.0F) {
    rtb_SignPreIntegrator = rtb_Sum - 5.0F;

    /* Saturate: '<S277>/Saturation' */
    rtDW.Saturation = 5.0F;
  } else {
    if (rtb_Sum >= -5.0F) {
      rtb_SignPreIntegrator = 0.0F;
    } else {
      rtb_SignPreIntegrator = rtb_Sum - -5.0F;
    }

    if (rtb_Sum < -5.0F) {
      /* Saturate: '<S277>/Saturation' */
      rtDW.Saturation = -5.0F;
    } else {
      /* Saturate: '<S277>/Saturation' */
      rtDW.Saturation = rtb_Sum;
    }
  }

  /* End of DeadZone: '<S263>/DeadZone' */

  /* Product: '<S267>/IProd Out' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  rtb_IProdOut *= 0.6389F;

  /* Update for DiscreteIntegrator: '<S270>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE_b = 0U;
  rtDW.Integrator_DSTATE_d = Integrator_e;

  /* Signum: '<S261>/SignPreSat' */
  if (rtb_SignPreIntegrator < 0.0F) {
    Integrator_e = -1.0F;
  } else if (rtb_SignPreIntegrator > 0.0F) {
    Integrator_e = 1.0F;
  } else if (rtb_SignPreIntegrator == 0.0F) {
    Integrator_e = 0.0F;
  } else {
    Integrator_e = (rtNaNF);
  }

  /* End of Signum: '<S261>/SignPreSat' */

  /* Signum: '<S261>/SignPreIntegrator' */
  if (rtb_IProdOut < 0.0F) {
    rtb_IProdOut_0 = -1.0F;
  } else if (rtb_IProdOut > 0.0F) {
    rtb_IProdOut_0 = 1.0F;
  } else if (rtb_IProdOut == 0.0F) {
    rtb_IProdOut_0 = 0.0F;
  } else {
    rtb_IProdOut_0 = (rtNaNF);
  }

  /* End of Signum: '<S261>/SignPreIntegrator' */

  /* Switch: '<S261>/Switch' incorporates:
   *  DataTypeConversion: '<S261>/DataTypeConv1'
   *  DataTypeConversion: '<S261>/DataTypeConv2'
   *  Gain: '<S261>/ZeroGain'
   *  Logic: '<S261>/AND3'
   *  RelationalOperator: '<S261>/Equal1'
   *  RelationalOperator: '<S261>/NotEqual'
   */
  if ((0.0F * rtb_Sum != rtb_SignPreIntegrator) && ((int8_T)Integrator_e ==
       (int8_T)rtb_IProdOut_0)) {
    /* Update for DiscreteIntegrator: '<S270>/Integrator' incorporates:
     *  Constant: '<S261>/Constant1'
     */
    rtDW.Integrator_PREV_U_c = 0.0F;
  } else {
    /* Update for DiscreteIntegrator: '<S270>/Integrator' */
    rtDW.Integrator_PREV_U_c = rtb_IProdOut;
  }

  /* End of Switch: '<S261>/Switch' */
}

/* Output and update for atomic system: '<S3>/Clark_Trans' */
static void Clark_Trans(real32_T rtu_ia, real32_T rtu_ib, real32_T rtu_ic,
  real32_T *rty_ialpha, real32_T *rty_ibeta)
{
  /* Sum: '<S11>/Add1' incorporates:
   *  Gain: '<S11>/Gain'
   *  Gain: '<S11>/Gain1'
   *  Sum: '<S11>/Add'
   */
  *rty_ialpha = 0.666666687F * rtu_ia - (rtu_ib + rtu_ic) * 0.333333343F;

  /* Gain: '<S11>/Gain2' incorporates:
   *  Sum: '<S11>/Add2'
   */
  *rty_ibeta = (rtu_ib - rtu_ic) * 0.577350259F;
}

/*
 * Output and update for action system:
 *    '<S3>/If Action Subsystem5'
 *    '<S3>/If Action Subsystem10'
 *    '<S17>/If Action Subsystem'
 */
static void IfActionSubsystem5(real32_T *rty_Out1)
{
  /* SignalConversion generated from: '<S20>/Out1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  *rty_Out1 = 0.0F;
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

  /* Trigonometry: '<S23>/Cos' incorporates:
   *  Trigonometry: '<S23>/Sin'
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

  /* End of Trigonometry: '<S23>/Cos' */

  /* Trigonometry: '<S23>/Sin' */
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

  /* Sum: '<S23>/Add' incorporates:
   *  Product: '<S23>/Product'
   *  Product: '<S23>/Product1'
   */
  *rty_id = rtu_ialpha * yVarTmp + rtu_ibeta * *rty_iq;

  /* Sum: '<S23>/Add1' incorporates:
   *  Product: '<S23>/Product2'
   *  Product: '<S23>/Product3'
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

/* System initialize for atomic system: '<S25>/fourth_SMO' */
static void fourth_SMO_Init(DW_fourth_SMO *localDW)
{
  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  localDW->Integrator_DSTATE = 50.0F;
}

/* Output and update for atomic system: '<S25>/fourth_SMO' */
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
  real32_T rtb_UnitDelay1_e;
  real32_T rtb_UnitDelay_p;

  /* Math: '<S178>/Mod' incorporates:
   *  Constant: '<S178>/Constant2'
   *  DiscreteIntegrator: '<S178>/Discrete-Time Integrator'
   */
  *rty_Obe_Theta = rt_modf_snf(localDW->DiscreteTimeIntegrator_DSTATE,
    6.28318548F);

  /* Signum: '<S178>/Sign' incorporates:
   *  UnitDelay: '<S178>/Unit Delay'
   */
  if (localDW->UnitDelay_DSTATE < 0.0F) {
    rtb_UnitDelay1_e = -1.0F;
  } else if (localDW->UnitDelay_DSTATE > 0.0F) {
    rtb_UnitDelay1_e = 1.0F;
  } else if (localDW->UnitDelay_DSTATE == 0.0F) {
    rtb_UnitDelay1_e = 0.0F;
  } else {
    rtb_UnitDelay1_e = (rtNaNF);
  }

  /* End of Signum: '<S178>/Sign' */

  /* Product: '<S178>/Product' incorporates:
   *  Product: '<S178>/Product1'
   *  Product: '<S178>/Product2'
   *  Sum: '<S178>/Sum'
   *  Trigonometry: '<S178>/Cos1'
   *  Trigonometry: '<S178>/Sin1'
   *  UnitDelay: '<S179>/Unit Delay2'
   *  UnitDelay: '<S180>/Unit Delay3'
   */
  rtb_UnitDelay1_e *= (0.0F - localDW->UnitDelay2_DSTATE * cosf(*rty_Obe_Theta))
    - sinf(*rty_Obe_Theta) * localDW->UnitDelay3_DSTATE;

  /* Sum: '<S226>/Sum' incorporates:
   *  Constant: '<S178>/Constant'
   *  Constant: '<S178>/Constant1'
   *  DiscreteIntegrator: '<S217>/Integrator'
   *  Gain: '<S178>/Gain'
   *  Product: '<S178>/Product3'
   *  Product: '<S222>/PProd Out'
   */
  *rty_omega_e = rtb_UnitDelay1_e * 203.616013F + localDW->Integrator_DSTATE;

  /* DeadZone: '<S210>/DeadZone' */
  if (*rty_omega_e > 3000.0F) {
    rtb_UnitDelay_p = *rty_omega_e - 3000.0F;
  } else if (*rty_omega_e >= -3000.0F) {
    rtb_UnitDelay_p = 0.0F;
  } else {
    rtb_UnitDelay_p = *rty_omega_e - -3000.0F;
  }

  /* End of DeadZone: '<S210>/DeadZone' */

  /* Product: '<S214>/IProd Out' incorporates:
   *  Constant: '<S178>/Constant1'
   *  Math: '<S178>/Square'
   */
  rtb_UnitDelay1_e *= 8100.0F;

  /* Signum: '<S208>/SignPreSat' */
  if (rtb_UnitDelay_p < 0.0F) {
    rtb_Product2_c = -1.0F;
  } else if (rtb_UnitDelay_p > 0.0F) {
    rtb_Product2_c = 1.0F;
  } else if (rtb_UnitDelay_p == 0.0F) {
    rtb_Product2_c = 0.0F;
  } else {
    rtb_Product2_c = (rtNaNF);
  }

  /* End of Signum: '<S208>/SignPreSat' */

  /* Signum: '<S208>/SignPreIntegrator' */
  if (rtb_UnitDelay1_e < 0.0F) {
    rtb_Divide4 = -1.0F;
  } else if (rtb_UnitDelay1_e > 0.0F) {
    rtb_Divide4 = 1.0F;
  } else if (rtb_UnitDelay1_e == 0.0F) {
    rtb_Divide4 = 0.0F;
  } else {
    rtb_Divide4 = (rtNaNF);
  }

  /* End of Signum: '<S208>/SignPreIntegrator' */

  /* Switch: '<S208>/Switch' incorporates:
   *  Constant: '<S208>/Constant1'
   *  DataTypeConversion: '<S208>/DataTypeConv1'
   *  DataTypeConversion: '<S208>/DataTypeConv2'
   *  Gain: '<S208>/ZeroGain'
   *  Logic: '<S208>/AND3'
   *  RelationalOperator: '<S208>/Equal1'
   *  RelationalOperator: '<S208>/NotEqual'
   */
  if ((0.0F * *rty_omega_e != rtb_UnitDelay_p) && ((int8_T)rtb_Product2_c ==
       (int8_T)rtb_Divide4)) {
    rtb_UnitDelay_p = 0.0F;
  } else {
    rtb_UnitDelay_p = rtb_UnitDelay1_e;
  }

  /* End of Switch: '<S208>/Switch' */

  /* Saturate: '<S224>/Saturation' */
  if (*rty_omega_e > 3000.0F) {
    *rty_omega_e = 3000.0F;
  } else if (*rty_omega_e < -3000.0F) {
    *rty_omega_e = -3000.0F;
  }

  /* End of Saturate: '<S224>/Saturation' */

  /* Product: '<S179>/Product2' incorporates:
   *  UnitDelay: '<S180>/Unit Delay3'
   */
  rtb_Product2_c = *rty_omega_e * localDW->UnitDelay3_DSTATE;

  /* Sum: '<S177>/Sum2' incorporates:
   *  UnitDelay: '<S181>/Unit Delay'
   */
  rtb_Sign1 = localDW->UnitDelay_DSTATE_p - rtu_Ialpha;

  /* Signum: '<S177>/Sign' */
  if (rtb_Sign1 < 0.0F) {
    rtb_UnitDelay1_e = -1.0F;
  } else if (rtb_Sign1 > 0.0F) {
    rtb_UnitDelay1_e = 1.0F;
  } else if (rtb_Sign1 == 0.0F) {
    rtb_UnitDelay1_e = 0.0F;
  } else {
    rtb_UnitDelay1_e = (rtNaNF);
  }

  /* End of Signum: '<S177>/Sign' */

  /* Product: '<S181>/Divide4' incorporates:
   *  Constant: '<S181>/Constant'
   *  Gain: '<S181>/Gain'
   *  UnitDelay: '<S181>/Unit Delay'
   */
  rtb_Divide4 = 0.112F * localDW->UnitDelay_DSTATE_p / 2.235E-5F;

  /* Product: '<S181>/Product' incorporates:
   *  UnitDelay: '<S182>/Unit Delay1'
   */
  rtb_Product_a = localDW->UnitDelay1_DSTATE * *rty_omega_e;

  /* Product: '<S181>/Divide2' incorporates:
   *  Constant: '<S181>/Constant'
   *  UnitDelay: '<S179>/Unit Delay2'
   */
  rtb_Divide2 = localDW->UnitDelay2_DSTATE / 2.235E-5F;

  /* Sum: '<S177>/Sum6' incorporates:
   *  UnitDelay: '<S182>/Unit Delay1'
   */
  rtb_Sign1 = localDW->UnitDelay1_DSTATE - rtu_Ibeta;

  /* Signum: '<S177>/Sign1' */
  if (rtb_Sign1 < 0.0F) {
    rtb_Sign1 = -1.0F;
  } else if (rtb_Sign1 > 0.0F) {
    rtb_Sign1 = 1.0F;
  } else if (rtb_Sign1 == 0.0F) {
    rtb_Sign1 = 0.0F;
  } else {
    rtb_Sign1 = (rtNaNF);
  }

  /* End of Signum: '<S177>/Sign1' */

  /* Product: '<S180>/Product3' incorporates:
   *  UnitDelay: '<S179>/Unit Delay2'
   */
  rtb_Product3_h = *rty_omega_e * localDW->UnitDelay2_DSTATE;

  /* Product: '<S182>/Product1' incorporates:
   *  UnitDelay: '<S181>/Unit Delay'
   */
  rtb_Product1_j = localDW->UnitDelay_DSTATE_p * *rty_omega_e;

  /* Product: '<S182>/Divide3' incorporates:
   *  Constant: '<S182>/Constant'
   *  Gain: '<S182>/Gain8'
   *  UnitDelay: '<S182>/Unit Delay1'
   */
  rtb_Divide3_d = 0.112F * localDW->UnitDelay1_DSTATE / 2.235E-5F;

  /* Product: '<S182>/Divide2' incorporates:
   *  Constant: '<S182>/Constant'
   *  UnitDelay: '<S180>/Unit Delay3'
   */
  rtb_Divide2_f = localDW->UnitDelay3_DSTATE / 2.235E-5F;

  /* Update for DiscreteIntegrator: '<S178>/Discrete-Time Integrator' */
  localDW->DiscreteTimeIntegrator_DSTATE += 0.0001F * *rty_omega_e;

  /* Update for UnitDelay: '<S179>/Unit Delay2' incorporates:
   *  DiscreteIntegrator: '<S179>/Discrete-Time Integrator'
   */
  localDW->UnitDelay2_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_i;

  /* Update for UnitDelay: '<S180>/Unit Delay3' incorporates:
   *  DiscreteIntegrator: '<S180>/Discrete-Time Integrator'
   */
  localDW->UnitDelay3_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_p;

  /* Update for UnitDelay: '<S178>/Unit Delay' */
  localDW->UnitDelay_DSTATE = *rty_omega_e;

  /* Update for DiscreteIntegrator: '<S217>/Integrator' */
  localDW->Integrator_DSTATE += 0.0001F * rtb_UnitDelay_p;

  /* Update for UnitDelay: '<S181>/Unit Delay' incorporates:
   *  DiscreteIntegrator: '<S181>/Discrete-Time Integrator'
   */
  localDW->UnitDelay_DSTATE_p = localDW->DiscreteTimeIntegrator_DSTATE_c;

  /* Update for UnitDelay: '<S182>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S182>/Discrete-Time Integrator'
   */
  localDW->UnitDelay1_DSTATE = localDW->DiscreteTimeIntegrator_DSTATE_m;

  /* Update for DiscreteIntegrator: '<S179>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S179>/Constant'
   *  Gain: '<S179>/Gain3'
   *  Product: '<S179>/Divide'
   *  Sum: '<S179>/Add2'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_i += (0.001F * rtb_UnitDelay1_e /
    2.235E-5F - rtb_Product2_c) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S180>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S180>/Constant'
   *  Gain: '<S180>/Gain1'
   *  Product: '<S180>/Divide'
   *  Sum: '<S180>/Add3'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_p += (0.001F * rtb_Sign1 / 2.235E-5F +
    rtb_Product3_h) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S181>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S181>/Constant'
   *  Gain: '<S181>/Gain3'
   *  Product: '<S181>/Divide1'
   *  Product: '<S181>/Divide3'
   *  Product: '<S181>/Product1'
   *  Product: '<S181>/Product2'
   *  Sum: '<S181>/Add'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_c += ((((rtu_Ualpha / 2.235E-5F -
    rtb_Divide4) - -3.32000127E-6F * rtb_Product_a / 2.235E-5F) - rtb_Divide2) -
    0.1F * rtb_UnitDelay1_e * 44742.7305F) * 0.0001F;

  /* Update for DiscreteIntegrator: '<S182>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S182>/Constant'
   *  Gain: '<S182>/Gain1'
   *  Product: '<S182>/Divide'
   *  Product: '<S182>/Divide1'
   *  Product: '<S182>/Divide4'
   *  Product: '<S182>/Product'
   *  Sum: '<S182>/Add1'
   */
  localDW->DiscreteTimeIntegrator_DSTATE_m += ((((-3.32000127E-6F *
    rtb_Product1_j / 2.235E-5F - rtb_Divide3_d) - rtb_Divide2_f) + rtu_U_beta /
    2.235E-5F) - 0.1F * rtb_Sign1 / 2.235E-5F) * 0.0001F;
}

/* Output and update for atomic system: '<S26>/Anti_Park_Trans' */
static void Anti_Park_Trans(real32_T rtu_ud, real32_T rtu_uq, real32_T rtu_theta,
  real32_T *rty_ualpha, real32_T *rty_ubeta)
{
  real32_T rtb_Cos_m;

  /* Trigonometry: '<S234>/Cos' */
  rtb_Cos_m = cosf(rtu_theta);

  /* Trigonometry: '<S234>/Sin' */
  *rty_ubeta = sinf(rtu_theta);

  /* Sum: '<S234>/Add' incorporates:
   *  Product: '<S234>/Product'
   *  Product: '<S234>/Product1'
   */
  *rty_ualpha = rtu_ud * rtb_Cos_m - rtu_uq * *rty_ubeta;

  /* Sum: '<S234>/Add1' incorporates:
   *  Product: '<S234>/Product2'
   *  Product: '<S234>/Product3'
   */
  *rty_ubeta = rtu_ud * *rty_ubeta + rtu_uq * rtb_Cos_m;
}

/* Model step function for TID0 */
void FOC_Model_step0(void)             /* Sample time: [0.0001s, 0.0s] */
{
  int32_T rtb_HFI_RUN;
  int32_T rtb_PulseGenerator;
  real32_T DiscreteTimeIntegrator;
  real32_T T1;
  real32_T rtb_Add;
  real32_T rtb_Add1_h;
  real32_T rtb_Add1_p5;
  real32_T rtb_Add_n;
  real32_T rtb_Gain2;
  real32_T rtb_Saturation_l;
  real32_T rtb_Sum1;
  ZCEventType zcEvent;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0001s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  (rtM->Timing.RateInteraction.TID0_1)++;
  if ((rtM->Timing.RateInteraction.TID0_1) > 9) {
    rtM->Timing.RateInteraction.TID0_1 = 0;
  }

  /* DiscretePulseGenerator: '<S24>/Pulse Generator' */
  rtb_PulseGenerator = ((rtDW.clockTickCounter < 1) && (rtDW.clockTickCounter >=
    0));
  if (rtDW.clockTickCounter >= 1) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S24>/Pulse Generator' */

  /* Sum: '<S24>/Add' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  rtb_Add = (real32_T)((real_T)rtb_PulseGenerator - 0.5);

  /* Chart: '<S3>/Chart' */
  if (rtDW.temporalCounter_i1_l < 1023U) {
    rtDW.temporalCounter_i1_l++;
  }

  if (rtDW.is_active_c3_FOC_Model == 0U) {
    rtDW.is_active_c3_FOC_Model = 1U;
    rtDW.is_c3_FOC_Model = IN_IDLE_h;
    rtb_PulseGenerator = 0;
    rtb_HFI_RUN = 0;
  } else {
    switch (rtDW.is_c3_FOC_Model) {
     case IN_HFI_NS:
      if (rtDW.temporalCounter_i1_l >= 100U) {
        rtDW.is_c3_FOC_Model = IN_HFI_OVER1;
        rtb_PulseGenerator = 5;
        rtb_HFI_RUN = 0;
      } else {
        rtb_PulseGenerator = 4;
        rtb_HFI_RUN = 0;
      }
      break;

     case IN_HFI_OVER1:
      rtb_PulseGenerator = 5;
      rtb_HFI_RUN = 0;
      break;

     case IN_HFI_START:
      if (rtDW.temporalCounter_i1_l >= 1000U) {
        rtDW.is_c3_FOC_Model = IN_INJECT_POSIT;
        rtDW.temporalCounter_i1_l = 0U;
        rtb_PulseGenerator = 2;
        rtb_HFI_RUN = 1;
      } else {
        rtb_PulseGenerator = 1;
        rtb_HFI_RUN = 0;
      }
      break;

     case IN_IDLE_h:
      rtDW.is_c3_FOC_Model = IN_HFI_START;
      rtDW.temporalCounter_i1_l = 0U;
      rtb_PulseGenerator = 1;
      rtb_HFI_RUN = 0;
      break;

     case IN_INJECT_NEGAT:
      if (rtDW.temporalCounter_i1_l >= 20U) {
        rtDW.is_c3_FOC_Model = IN_HFI_NS;
        rtDW.temporalCounter_i1_l = 0U;
        rtb_PulseGenerator = 4;
        rtb_HFI_RUN = 0;
      } else {
        rtb_PulseGenerator = 3;
        rtb_HFI_RUN = 1;
      }
      break;

     default:
      /* case IN_INJECT_POSIT: */
      if (rtDW.temporalCounter_i1_l >= 20U) {
        rtDW.is_c3_FOC_Model = IN_INJECT_NEGAT;
        rtDW.temporalCounter_i1_l = 0U;
        rtb_PulseGenerator = 3;
        rtb_HFI_RUN = 1;
      } else {
        rtb_PulseGenerator = 2;
        rtb_HFI_RUN = 1;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* Outputs for Atomic SubSystem: '<S3>/Clark_Trans' */
  /* Inport: '<Root>/ia' incorporates:
   *  Inport: '<Root>/ib'
   *  Inport: '<Root>/ic'
   */
  Clark_Trans(rtU.ia, rtU.ib, rtU.ic, &rtb_Add1_h, &rtb_Gain2);

  /* End of Outputs for SubSystem: '<S3>/Clark_Trans' */

  /* Outputs for Triggered SubSystem: '<S3>/HFI_Observer' incorporates:
   *  TriggerPort: '<S13>/Trigger'
   */
  zcEvent = rt_R32ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX.HFI_Observer_Trig_ZCE,
                        (rtb_Add));
  if (zcEvent != NO_ZCEVENT) {
    uint32_T HFI_Observer_ELAPS_T;
    if (rtDW.HFI_Observer_RESET_ELAPS_T) {
      HFI_Observer_ELAPS_T = 0U;
    } else {
      HFI_Observer_ELAPS_T = rtM->Timing.clockTick0 - rtDW.HFI_Observer_PREV_T;
    }

    rtDW.HFI_Observer_PREV_T = rtM->Timing.clockTick0;
    rtDW.HFI_Observer_RESET_ELAPS_T = false;

    /* Signum: '<S13>/Sign' */
    if (rtb_Add < 0.0F) {
      rtb_Add1_p5 = -1.0F;
    } else if (rtb_Add > 0.0F) {
      rtb_Add1_p5 = 1.0F;
    } else {
      rtb_Add1_p5 = 0.0F;
    }

    /* End of Signum: '<S13>/Sign' */

    /* Product: '<S13>/Product' incorporates:
     *  Sum: '<S13>/Add1'
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    rtb_Add_n = (rtb_Add1_h - rtDW.UnitDelay1_DSTATE) * rtb_Add1_p5;

    /* Product: '<S13>/Product1' incorporates:
     *  Sum: '<S13>/Add2'
     *  UnitDelay: '<S13>/Unit Delay2'
     */
    rtb_Add1_p5 *= rtb_Gain2 - rtDW.UnitDelay2_DSTATE;

    /* Fcn: '<S125>/Fcn2' incorporates:
     *  Fcn: '<S125>/Fcn3'
     */
    T1 = rtb_Add1_p5 * rtb_Add1_p5;
    rtb_Sum1 = rtb_Add_n * rtb_Add_n + T1;
    if (rtb_Sum1 < 0.0F) {
      rtb_Saturation_l = -sqrtf(-rtb_Sum1);
    } else {
      rtb_Saturation_l = sqrtf(rtb_Sum1);
    }

    /* DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
    if (rtDW.DiscreteTimeIntegrator_SYSTEM_E != 0) {
      /* DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
      DiscreteTimeIntegrator = rtDW.DiscreteTimeIntegrator_DSTATE;
    } else {
      /* DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
      DiscreteTimeIntegrator = 0.0001F * (real32_T)HFI_Observer_ELAPS_T
        * rtDW.DiscreteTimeIntegrator_PREV_U +
        rtDW.DiscreteTimeIntegrator_DSTATE;
    }

    /* End of DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */

    /* Fcn: '<S125>/Fcn3' */
    rtb_Sum1 = rtb_Add_n * rtb_Add_n + T1;
    if (rtb_Sum1 < 0.0F) {
      rtb_Sum1 = -sqrtf(-rtb_Sum1);
    } else {
      rtb_Sum1 = sqrtf(rtb_Sum1);
    }

    /* Sum: '<S125>/Sum9' incorporates:
     *  Fcn: '<S125>/Fcn'
     *  Fcn: '<S125>/Fcn1'
     *  Fcn: '<S125>/Fcn2'
     *  Fcn: '<S125>/Fcn3'
     *  Product: '<S125>/   '
     *  Product: '<S125>/    '
     */
    rtb_Add1_p5 = rtb_Add1_p5 / rtb_Sum1 * cosf(DiscreteTimeIntegrator) -
      rtb_Add_n / rtb_Saturation_l * sinf(DiscreteTimeIntegrator);

    /* DiscreteIntegrator: '<S158>/Integrator' */
    if (rtDW.Integrator_SYSTEM_ENABLE != 0) {
      /* DiscreteIntegrator: '<S158>/Integrator' */
      rtb_Add_n = rtDW.Integrator_DSTATE_c;
    } else {
      /* DiscreteIntegrator: '<S158>/Integrator' */
      rtb_Add_n = 0.0001F * (real32_T)HFI_Observer_ELAPS_T
        * rtDW.Integrator_PREV_U + rtDW.Integrator_DSTATE_c;
    }

    /* End of DiscreteIntegrator: '<S158>/Integrator' */

    /* Sum: '<S167>/Sum' incorporates:
     *  Gain: '<S163>/Proportional Gain'
     */
    rtb_Saturation_l = 100.0F * rtb_Add1_p5 + rtb_Add_n;

    /* Gain: '<S13>/Gain1' */
    rtDW.min = 1.36418521F * rtb_Saturation_l;

    /* Math: '<S13>/Math Function1' incorporates:
     *  Constant: '<S13>/Constant1'
     */
    rtDW.MathFunction1 = rt_modf_snf(DiscreteTimeIntegrator, 6.28318548F);

    /* Update for UnitDelay: '<S13>/Unit Delay1' */
    rtDW.UnitDelay1_DSTATE = rtb_Add1_h;

    /* Update for UnitDelay: '<S13>/Unit Delay2' */
    rtDW.UnitDelay2_DSTATE = rtb_Gain2;

    /* Update for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
    rtDW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    rtDW.DiscreteTimeIntegrator_DSTATE = DiscreteTimeIntegrator;
    rtDW.DiscreteTimeIntegrator_PREV_U = rtb_Saturation_l;

    /* Update for DiscreteIntegrator: '<S158>/Integrator' incorporates:
     *  Gain: '<S155>/Integral Gain'
     */
    rtDW.Integrator_SYSTEM_ENABLE = 0U;
    rtDW.Integrator_DSTATE_c = rtb_Add_n;
    rtDW.Integrator_PREV_U = 15000.0F * rtb_Add1_p5;
  }

  /* End of Outputs for SubSystem: '<S3>/HFI_Observer' */

  /* SwitchCase: '<S3>/Switch Case' */
  switch (rtb_PulseGenerator) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S18>/Constant'
     *  SignalConversion generated from: '<S18>/Out1'
     */
    rtDW.Merge = 0.0F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem3' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S14>/Constant'
     *  SignalConversion generated from: '<S14>/Out1'
     */
    rtDW.Merge = 1.0F;

    /* Memory: '<S14>/Memory1' */
    rtDW.Memory1 = rtDW.Memory1_PreviousInput;

    /* Update for Memory: '<S14>/Memory1' incorporates:
     *  MinMax: '<S14>/Max'
     */
    rtDW.Memory1_PreviousInput = fmaxf(rtb_Add1_h, rtDW.Memory1);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S15>/Constant'
     *  SignalConversion generated from: '<S15>/Out2'
     */
    rtDW.Merge = -1.0F;

    /* Memory: '<S15>/Memory' */
    rtDW.Memory = rtDW.Memory_PreviousInput;

    /* Update for Memory: '<S15>/Memory' incorporates:
     *  MinMax: '<S15>/Min'
     */
    rtDW.Memory_PreviousInput = fminf(rtb_Add1_h, rtDW.Memory);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* Merge: '<S3>/Merge' incorporates:
     *  Constant: '<S17>/Constant'
     *  SignalConversion generated from: '<S17>/Out2'
     */
    rtDW.Merge = 0.0F;

    /* If: '<S17>/If' incorporates:
     *  Gain: '<S17>/Gain'
     *  Sum: '<S17>/Sum'
     */
    if (rtDW.Memory1 - (-rtDW.Memory) >= 0.0F) {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
       *  ActionPort: '<S175>/Action Port'
       */
      IfActionSubsystem5(&ns_single);

      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S176>/Action Port'
       */
      /* Merge: '<S17>/Merge' incorporates:
       *  Constant: '<S176>/Constant'
       *  SignalConversion generated from: '<S176>/Out1'
       */
      ns_single = 3.14159274F;

      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
    }

    /* End of If: '<S17>/If' */
    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    break;
  }

  /* End of SwitchCase: '<S3>/Switch Case' */

  /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem9' incorporates:
   *  ActionPort: '<S22>/Action Port'
   */
  /* If: '<S3>/If2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Inport: '<S22>/In1'
   *  Math: '<S3>/Mod'
   *  Merge: '<S3>/Merge2'
   *  Sum: '<S3>/Add1'
   */
  hfi_theta = rt_modf_snf(rtDW.MathFunction1 + ns_single, 6.28318548F);

  /* End of Outputs for SubSystem: '<S3>/If Action Subsystem9' */

  /* Outputs for Atomic SubSystem: '<S3>/Park_Trans' */
  Park_Trans(rtb_Add1_h, rtb_Gain2, hfi_theta, &rtb_Add1_p5, &rtb_Add_n);

  /* End of Outputs for SubSystem: '<S3>/Park_Trans' */

  /* Sum: '<S12>/Sum1' incorporates:
   *  Inport: '<Root>/id_ref'
   */
  rtb_Sum1 = rtU.id_ref - rtb_Add1_p5;

  /* Gain: '<S12>/Gain' incorporates:
   *  Constant: '<S12>/Constant3'
   */
  rtb_Add1_p5 = 0.00447F;

  /* Sum: '<S69>/Sum' incorporates:
   *  DiscreteIntegrator: '<S60>/Integrator'
   *  Product: '<S65>/PProd Out'
   */
  DiscreteTimeIntegrator = rtb_Sum1 * 0.00447F + rtDW.Integrator_DSTATE;

  /* If: '<S3>/If' incorporates:
   *  Saturate: '<S67>/Saturation'
   */
  if (rtb_HFI_RUN == 1) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    IfActionSubsystem5(&DiscreteTimeIntegrator);

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem5' */
  } else if (DiscreteTimeIntegrator > 6.23538303F) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Saturate: '<S67>/Saturation' incorporates:
     *  Inport: '<S21>/Input'
     */
    DiscreteTimeIntegrator = 6.23538303F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem6' */
  } else if (DiscreteTimeIntegrator < -6.23538303F) {
    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Saturate: '<S67>/Saturation' incorporates:
     *  Inport: '<S21>/Input'
     */
    DiscreteTimeIntegrator = -6.23538303F;

    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem6' */
  }

  /* End of If: '<S3>/If' */

  /* Sum: '<S3>/Add' */
  ud = (rtb_Add + DiscreteTimeIntegrator) + rtDW.Merge;

  /* RateTransition: '<S1>/Rate Transition4' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    /* RateTransition: '<S1>/Rate Transition4' */
    rtDW.RateTransition4 = rtDW.RateTransition4_Buffer0;
  }

  /* End of RateTransition: '<S1>/Rate Transition4' */

  /* Sum: '<S12>/Sum7' */
  DiscreteTimeIntegrator = rtDW.RateTransition4 - rtb_Add_n;

  /* Sum: '<S117>/Sum' incorporates:
   *  DiscreteIntegrator: '<S108>/Integrator'
   *  Product: '<S113>/PProd Out'
   */
  rtb_Add = DiscreteTimeIntegrator * 0.00447F + rtDW.Integrator_DSTATE_o;

  /* Saturate: '<S115>/Saturation' */
  if (rtb_Add > 6.23538303F) {
    /* Saturate: '<S115>/Saturation' */
    uq = 6.23538303F;
  } else if (rtb_Add < -6.23538303F) {
    /* Saturate: '<S115>/Saturation' */
    uq = -6.23538303F;
  } else {
    /* Saturate: '<S115>/Saturation' */
    uq = rtb_Add;
  }

  /* End of Saturate: '<S115>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S26>/Anti_Park_Trans' */
  Anti_Park_Trans(ud, uq, hfi_theta, &rtb_Add_n, &rtb_Add1_p5);

  /* End of Outputs for SubSystem: '<S26>/Anti_Park_Trans' */

  /* MATLAB Function: '<S26>/foc' */
  rtb_PulseGenerator = 0;

  /* Outport: '<Root>/Tcmp1' incorporates:
   *  MATLAB Function: '<S26>/foc'
   */
  rtY.Tcmp1 = 0.0F;

  /* Outport: '<Root>/Tcmp2' incorporates:
   *  MATLAB Function: '<S26>/foc'
   */
  rtY.Tcmp2 = 0.0F;

  /* Outport: '<Root>/Tcmp3' incorporates:
   *  MATLAB Function: '<S26>/foc'
   */
  rtY.Tcmp3 = 0.0F;

  /* MATLAB Function: '<S26>/foc' incorporates:
   *  Constant: '<S26>/Constant4'
   *  Inport: '<Root>/Ubus'
   */
  if (rtb_Add1_p5 > 0.0F) {
    rtb_PulseGenerator = 1;
  }

  if ((1.73205078F * rtb_Add_n - rtb_Add1_p5) / 2.0F > 0.0F) {
    rtb_PulseGenerator += 2;
  }

  if ((-1.73205078F * rtb_Add_n - rtb_Add1_p5) / 2.0F > 0.0F) {
    rtb_PulseGenerator += 4;
  }

  switch (rtb_PulseGenerator) {
   case 1:
    T1 = (-1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F / rtU.Ubus);
    rtb_Add = (1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F /
      rtU.Ubus);
    break;

   case 2:
    T1 = (1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F / rtU.Ubus);
    rtb_Add = -(1.73205078F * rtb_Add1_p5 * 16000.0F / rtU.Ubus);
    break;

   case 3:
    T1 = -((-1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F /
            rtU.Ubus));
    rtb_Add = 1.73205078F * rtb_Add1_p5 * 16000.0F / rtU.Ubus;
    break;

   case 4:
    T1 = -(1.73205078F * rtb_Add1_p5 * 16000.0F / rtU.Ubus);
    rtb_Add = (-1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F /
      rtU.Ubus);
    break;

   case 5:
    T1 = 1.73205078F * rtb_Add1_p5 * 16000.0F / rtU.Ubus;
    rtb_Add = -((1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F /
      rtU.Ubus));
    break;

   default:
    T1 = -((1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F /
            rtU.Ubus));
    rtb_Add = -((-1.5F * rtb_Add_n + 0.866025388F * rtb_Add1_p5) * (16000.0F /
      rtU.Ubus));
    break;
  }

  rtb_Saturation_l = T1 + rtb_Add;
  if (rtb_Saturation_l > 16000.0F) {
    T1 /= rtb_Saturation_l;
    rtb_Add /= T1 + rtb_Add;
  }

  rtb_Saturation_l = (16000.0F - (T1 + rtb_Add)) / 4.0F;
  T1 = T1 / 2.0F + rtb_Saturation_l;
  switch (rtb_PulseGenerator) {
   case 1:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Saturation_l;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Add / 2.0F + T1;
    break;

   case 2:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Saturation_l;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Add / 2.0F + T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = T1;
    break;

   case 3:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Saturation_l;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Add / 2.0F + T1;
    break;

   case 4:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Add / 2.0F + T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Saturation_l;
    break;

   case 5:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = rtb_Add / 2.0F + T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Saturation_l;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = T1;
    break;

   case 6:
    /* Outport: '<Root>/Tcmp1' */
    rtY.Tcmp1 = T1;

    /* Outport: '<Root>/Tcmp2' */
    rtY.Tcmp2 = rtb_Add / 2.0F + T1;

    /* Outport: '<Root>/Tcmp3' */
    rtY.Tcmp3 = rtb_Saturation_l;
    break;
  }

  /* Outport: '<Root>/Sector' incorporates:
   *  MATLAB Function: '<S26>/foc'
   */
  rtY.Sector = (real32_T)rtb_PulseGenerator;

  /* RateTransition: '<S1>/Rate Transition1' */
  if (rtM->Timing.RateInteraction.TID0_1 == 1) {
    rtDW.RateTransition1_Buffer = rtDW.min;

    /* RateTransition: '<S1>/Rate Transition2' incorporates:
     *  Inport: '<Root>/Spd_ref'
     */
    rtDW.RateTransition2_Buffer = rtU.Spd_ref;
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */

  /* Gain: '<S12>/Gain1' incorporates:
   *  Constant: '<S12>/Constant4'
   */
  rtb_Saturation_l = 22.4000015F;

  /* Product: '<S57>/IProd Out' */
  rtb_Add = rtb_Sum1 * 22.4000015F;

  /* Product: '<S105>/IProd Out' */
  DiscreteTimeIntegrator *= 22.4000015F;

  /* Outputs for Atomic SubSystem: '<S25>/fourth_SMO' */
  fourth_SMO(rtb_Add_n, rtb_Add1_p5, rtb_Add1_h, rtb_Gain2, &rtb_Sum1,
             &rtb_Saturation_l, &rtDW.fourth_SMO_h);

  /* End of Outputs for SubSystem: '<S25>/fourth_SMO' */

  /* Chart: '<S2>/Chart1' */
  if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c7_FOC_Model == 0U) {
    rtDW.is_active_c7_FOC_Model = 1U;
    rtDW.is_c7_FOC_Model = IN_IDLE;
  } else {
    boolean_T guard1 = false;
    guard1 = false;
    switch (rtDW.is_c7_FOC_Model) {
     case IN_AlignStage:
      if (rtDW.temporalCounter_i1 >= 1000U) {
        rtDW.is_c7_FOC_Model = IN_OpenStage;
        rtDW.temporalCounter_i1 = 0U;
        guard1 = true;
      } else if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
      }
      break;

     case IN_IDLE:
      if (rtU.MotorSwitch == 1.0F) {
        rtDW.is_c7_FOC_Model = IN_AlignStage;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     case IN_OpenStage:
      if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
      } else if (rtDW.temporalCounter_i1 >= 30000U) {
        rtDW.is_c7_FOC_Model = IN_RunStage;
      } else {
        guard1 = true;
      }
      break;

     default:
      /* case IN_RunStage: */
      if (rtU.MotorSwitch == 0.0F) {
        rtDW.is_c7_FOC_Model = IN_IDLE;
      }
      break;
    }

    if (guard1) {
      /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S8>/Action Port'
       */
      /* SwitchCase: '<S2>/Switch Case1' incorporates:
       *  Constant: '<S2>/Constant12'
       *  Constant: '<S8>/Constant1'
       *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator'
       *  DiscreteIntegrator: '<S8>/Discrete-Time Integrator1'
       *  Product: '<S8>/Divide'
       *  Product: '<S8>/Product'
       * */
      rtDW.DiscreteTimeIntegrator1_DSTATE += 0.0001F *
        rtDW.DiscreteTimeIntegrator_DSTATE_i;
      rtDW.DiscreteTimeIntegrator_DSTATE_i += 0.00977384299F;

      /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
    }
  }

  /* End of Chart: '<S2>/Chart1' */

  /* Outport: '<Root>/Outport3' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtY.Outport3 = rtDW.UnitDelay_DSTATE;

  /* Outport: '<Root>/Outport4' incorporates:
   *  Gain: '<S25>/wm->Nr2'
   */
  rtY.Outport4 = 1.36418521F * rtb_Saturation_l;

  /* Update for DiscreteIntegrator: '<S60>/Integrator' */
  rtDW.Integrator_DSTATE += 0.0001F * rtb_Add;

  /* Update for DiscreteIntegrator: '<S108>/Integrator' */
  rtDW.Integrator_DSTATE_o += 0.0001F * DiscreteTimeIntegrator;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Sum1;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick0++;
}

/* Model step function for TID1 */
void FOC_Model_step1(void)             /* Sample time: [0.001s, 0.0s] */
{
  /* RateTransition: '<S1>/Rate Transition1' */
  rtDW.RateTransition1 = rtDW.RateTransition1_Buffer;

  /* RateTransition: '<S1>/Rate Transition2' */
  rtDW.RateTransition2 = rtDW.RateTransition2_Buffer;

  /* S-Function (fcgen): '<S1>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S1>/speed_loop'
   */
  speed_loop();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator2' */

  /* RateTransition: '<S1>/Rate Transition4' */
  rtDW.RateTransition4_Buffer0 = rtDW.Saturation;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick1++;
}

/* Model initialize function */
void FOC_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtPrevZCX.HFI_Observer_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<S25>/fourth_SMO' */
  fourth_SMO_Init(&rtDW.fourth_SMO_h);

  /* End of SystemInitialize for SubSystem: '<S25>/fourth_SMO' */

  /* Enable for Triggered SubSystem: '<S3>/HFI_Observer' */
  rtDW.HFI_Observer_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S125>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* Enable for DiscreteIntegrator: '<S158>/Integrator' */
  rtDW.Integrator_SYSTEM_ENABLE = 1U;

  /* End of Enable for SubSystem: '<S3>/HFI_Observer' */

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
