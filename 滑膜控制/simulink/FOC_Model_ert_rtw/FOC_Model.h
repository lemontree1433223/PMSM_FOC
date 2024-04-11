/*
 * File: FOC_Model.h
 *
 * Code generated for Simulink model 'FOC_Model'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Mon Apr  8 08:54:09 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOC_Model_h_
#define RTW_HEADER_FOC_Model_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_Model_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S13>/fourth_SMO' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S114>/Discrete-Time Integrator' */
  real32_T UnitDelay2_DSTATE;          /* '<S115>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE;          /* '<S116>/Unit Delay3' */
  real32_T UnitDelay_DSTATE;           /* '<S114>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S153>/Integrator' */
  real32_T UnitDelay_DSTATE_p;         /* '<S117>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S118>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S115>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S116>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S117>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S118>/Discrete-Time Integrator' */
} DW_fourth_SMO;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_fourth_SMO fourth_SMO_h;          /* '<S13>/fourth_SMO' */
  real32_T RateTransition4;            /* '<S1>/Rate Transition4' */
  real32_T theat_Extern;               /* '<S2>/Merge3' */
  real32_T id_ExternRef;               /* '<S2>/Merge4' */
  real32_T RateTransition1;            /* '<S1>/Rate Transition1' */
  real32_T RateTransition2;            /* '<S1>/Rate Transition2' */
  real32_T RateTransition3;            /* '<S1>/Rate Transition3' */
  real32_T Saturation;                 /* '<S213>/Saturation' */
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S48>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S96>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S8>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S206>/Integrator' */
  real32_T RateTransition4_Buffer0;    /* '<S1>/Rate Transition4' */
  real32_T Integrator_PREV_U;          /* '<S206>/Integrator' */
  uint32_T temporalCounter_i1;         /* '<S2>/Chart1' */
  uint32_T speed_loop_PREV_T;          /* '<S1>/speed_loop' */
  int8_T Integrator_PrevResetState;    /* '<S206>/Integrator' */
  uint8_T is_active_c7_FOC_Model;      /* '<S2>/Chart1' */
  uint8_T is_c7_FOC_Model;             /* '<S2>/Chart1' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S206>/Integrator' */
  boolean_T speed_loop_RESET_ELAPS_T;  /* '<S1>/speed_loop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T id_ref;                     /* '<Root>/id_ref' */
  real32_T Ubus;                       /* '<Root>/Ubus' */
  real32_T Spd_ref;                    /* '<Root>/Spd_ref' */
  real32_T MotorSwitch;                /* '<Root>/MotorSwitch' */
  real32_T Inport1;                    /* '<Root>/Inport1' */
  real32_T Inport2;                    /* '<Root>/Inport2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Tcmp1;                      /* '<Root>/Tcmp1' */
  real32_T Tcmp2;                      /* '<Root>/Tcmp2' */
  real32_T Tcmp3;                      /* '<Root>/Tcmp3' */
  real32_T Sector;                     /* '<Root>/Sector' */
  real32_T Outport3;                   /* '<Root>/Outport3' */
  real32_T Outport4;                   /* '<Root>/Outport4' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S2>/Scope6' : Unused code path elimination
 * Block '<S2>/Scope8' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S13>/Constant2' : Unused code path elimination
 * Block '<S13>/Data Type Conversion4' : Unused code path elimination
 * Block '<S13>/Gain2' : Unused code path elimination
 * Block '<S13>/Mod1' : Unused code path elimination
 * Block '<S13>/Scope5' : Unused code path elimination
 * Block '<S113>/Atan2' : Unused code path elimination
 * Block '<S113>/Constant' : Unused code path elimination
 * Block '<S113>/Gain' : Unused code path elimination
 * Block '<S113>/Mod' : Unused code path elimination
 * Block '<S114>/Add' : Unused code path elimination
 * Block '<S114>/Atan' : Unused code path elimination
 * Block '<S114>/Constant3' : Unused code path elimination
 * Block '<S114>/Constant5' : Unused code path elimination
 * Block '<S114>/Divide' : Unused code path elimination
 * Block '<S114>/Mod1' : Unused code path elimination
 * Block '<S114>/Scope' : Unused code path elimination
 * Block '<S113>/Scope' : Unused code path elimination
 * Block '<S113>/Scope1' : Unused code path elimination
 * Block '<S113>/Scope2' : Unused code path elimination
 * Block '<S170>/Scope' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('foc/FOC_Model')    - opens subsystem foc/FOC_Model
 * hilite_system('foc/FOC_Model/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'foc'
 * '<S1>'   : 'foc/FOC_Model'
 * '<S2>'   : 'foc/FOC_Model/Motor_State'
 * '<S3>'   : 'foc/FOC_Model/currloop'
 * '<S4>'   : 'foc/FOC_Model/speed_loop'
 * '<S5>'   : 'foc/FOC_Model/Motor_State/Chart1'
 * '<S6>'   : 'foc/FOC_Model/Motor_State/If Action Subsystem'
 * '<S7>'   : 'foc/FOC_Model/Motor_State/If Action Subsystem1'
 * '<S8>'   : 'foc/FOC_Model/Motor_State/If Action Subsystem2'
 * '<S9>'   : 'foc/FOC_Model/Motor_State/If Action Subsystem3'
 * '<S10>'  : 'foc/FOC_Model/currloop/Clark_Trans'
 * '<S11>'  : 'foc/FOC_Model/currloop/Current_PI_Control'
 * '<S12>'  : 'foc/FOC_Model/currloop/Park_Trans'
 * '<S13>'  : 'foc/FOC_Model/currloop/observer'
 * '<S14>'  : 'foc/FOC_Model/currloop/svpwm'
 * '<S15>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller'
 * '<S16>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1'
 * '<S17>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup'
 * '<S18>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain'
 * '<S19>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter'
 * '<S20>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs'
 * '<S21>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain'
 * '<S22>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain'
 * '<S23>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk'
 * '<S24>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator'
 * '<S25>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs'
 * '<S26>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy'
 * '<S27>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain'
 * '<S28>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy'
 * '<S29>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain'
 * '<S30>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal'
 * '<S31>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation'
 * '<S32>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk'
 * '<S33>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum'
 * '<S34>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk'
 * '<S35>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode'
 * '<S36>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum'
 * '<S37>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral'
 * '<S38>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain'
 * '<S39>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal'
 * '<S40>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal'
 * '<S41>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup/Passthrough'
 * '<S42>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain/Disabled'
 * '<S43>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter/Disabled'
 * '<S44>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs/Disabled'
 * '<S45>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain/External Parameters'
 * '<S46>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S47>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator/Discrete'
 * '<S49>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs/Internal IC'
 * '<S50>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S51>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain/Disabled'
 * '<S52>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy/Disabled'
 * '<S53>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain/External Parameters'
 * '<S54>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal/Disabled'
 * '<S55>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation/Enabled'
 * '<S56>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S57>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum/Sum_PI'
 * '<S58>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk/Disabled'
 * '<S59>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode/Disabled'
 * '<S60>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral/Passthrough'
 * '<S62>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal/Forward_Path'
 * '<S64>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal/Forward_Path'
 * '<S65>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup'
 * '<S66>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain'
 * '<S67>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter'
 * '<S68>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs'
 * '<S69>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain'
 * '<S70>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain'
 * '<S71>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk'
 * '<S72>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator'
 * '<S73>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs'
 * '<S74>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy'
 * '<S75>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain'
 * '<S76>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy'
 * '<S77>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain'
 * '<S78>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal'
 * '<S79>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation'
 * '<S80>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk'
 * '<S81>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum'
 * '<S82>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk'
 * '<S83>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode'
 * '<S84>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum'
 * '<S85>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral'
 * '<S86>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain'
 * '<S87>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal'
 * '<S88>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal'
 * '<S89>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup/Passthrough'
 * '<S90>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain/Disabled'
 * '<S91>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter/Disabled'
 * '<S92>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs/Disabled'
 * '<S93>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain/External Parameters'
 * '<S94>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S95>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator/Discrete'
 * '<S97>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs/Internal IC'
 * '<S98>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S99>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain/Disabled'
 * '<S100>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy/Disabled'
 * '<S101>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain/External Parameters'
 * '<S102>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal/Disabled'
 * '<S103>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation/Enabled'
 * '<S104>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S105>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum/Sum_PI'
 * '<S106>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk/Disabled'
 * '<S107>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode/Disabled'
 * '<S108>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S110>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal/Forward_Path'
 * '<S112>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal/Forward_Path'
 * '<S113>' : 'foc/FOC_Model/currloop/observer/fourth_SMO'
 * '<S114>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL'
 * '<S115>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/e_alpha'
 * '<S116>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/e_beta'
 * '<S117>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/i_alpha'
 * '<S118>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/i_beta'
 * '<S119>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl'
 * '<S120>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup'
 * '<S121>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/D Gain'
 * '<S122>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter'
 * '<S123>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter ICs'
 * '<S124>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/I Gain'
 * '<S125>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain'
 * '<S126>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain Fdbk'
 * '<S127>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator'
 * '<S128>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator ICs'
 * '<S129>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Copy'
 * '<S130>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Gain'
 * '<S131>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/P Copy'
 * '<S132>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Parallel P Gain'
 * '<S133>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Reset Signal'
 * '<S134>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation'
 * '<S135>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation Fdbk'
 * '<S136>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum'
 * '<S137>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum Fdbk'
 * '<S138>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode'
 * '<S139>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode Sum'
 * '<S140>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Integral'
 * '<S141>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Ngain'
 * '<S142>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/postSat Signal'
 * '<S143>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/preSat Signal'
 * '<S144>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel'
 * '<S145>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S146>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S147>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/D Gain/Disabled'
 * '<S148>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter/Disabled'
 * '<S149>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter ICs/Disabled'
 * '<S150>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/I Gain/External Parameters'
 * '<S151>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain/Passthrough'
 * '<S152>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain Fdbk/Disabled'
 * '<S153>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator/Discrete'
 * '<S154>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator ICs/Internal IC'
 * '<S155>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Copy/Disabled wSignal Specification'
 * '<S156>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Gain/Disabled'
 * '<S157>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/P Copy/Disabled'
 * '<S158>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Parallel P Gain/External Parameters'
 * '<S159>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Reset Signal/Disabled'
 * '<S160>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation/Enabled'
 * '<S161>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation Fdbk/Disabled'
 * '<S162>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum/Sum_PI'
 * '<S163>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum Fdbk/Disabled'
 * '<S164>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode/Disabled'
 * '<S165>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode Sum/Passthrough'
 * '<S166>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Integral/Passthrough'
 * '<S167>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Ngain/Passthrough'
 * '<S168>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/postSat Signal/Forward_Path'
 * '<S169>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/preSat Signal/Forward_Path'
 * '<S170>' : 'foc/FOC_Model/currloop/svpwm/Anti_Park_Trans'
 * '<S171>' : 'foc/FOC_Model/currloop/svpwm/foc'
 * '<S172>' : 'foc/FOC_Model/speed_loop/PID Controller3'
 * '<S173>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup'
 * '<S174>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain'
 * '<S175>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter'
 * '<S176>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs'
 * '<S177>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain'
 * '<S178>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain'
 * '<S179>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S180>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator'
 * '<S181>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs'
 * '<S182>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy'
 * '<S183>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain'
 * '<S184>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy'
 * '<S185>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain'
 * '<S186>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal'
 * '<S187>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation'
 * '<S188>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk'
 * '<S189>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum'
 * '<S190>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk'
 * '<S191>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode'
 * '<S192>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S193>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral'
 * '<S194>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S195>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal'
 * '<S196>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal'
 * '<S197>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S198>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S199>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S200>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain/Disabled'
 * '<S201>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter/Disabled'
 * '<S202>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S203>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain/External Parameters'
 * '<S204>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S205>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S206>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator/Discrete'
 * '<S207>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S208>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S209>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain/Disabled'
 * '<S210>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy/Disabled'
 * '<S211>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain/External Parameters'
 * '<S212>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S213>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation/Enabled'
 * '<S214>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S215>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S216>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S217>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S218>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S219>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S220>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S221>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S222>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
