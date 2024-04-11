/*
 * File: FOC_Model.h
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

#ifndef RTW_HEADER_FOC_Model_h_
#define RTW_HEADER_FOC_Model_h_
#include <stddef.h>
#include <float.h>
#include <math.h>
#ifndef FOC_Model_COMMON_INCLUDES_
#define FOC_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
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

/* Block signals and states (default storage) for system '<S25>/fourth_SMO' */
typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S178>/Discrete-Time Integrator' */
  real32_T UnitDelay2_DSTATE;          /* '<S179>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE;          /* '<S180>/Unit Delay3' */
  real32_T UnitDelay_DSTATE;           /* '<S178>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S217>/Integrator' */
  real32_T UnitDelay_DSTATE_p;         /* '<S181>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S182>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S179>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S180>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S181>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_m;/* '<S182>/Discrete-Time Integrator' */
} DW_fourth_SMO;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_fourth_SMO fourth_SMO_h;          /* '<S25>/fourth_SMO' */
  real32_T Merge;                      /* '<S3>/Merge' */
  real32_T RateTransition4;            /* '<S1>/Rate Transition4' */
  real32_T RateTransition1;            /* '<S1>/Rate Transition1' */
  real32_T RateTransition2;            /* '<S1>/Rate Transition2' */
  real32_T Memory;                     /* '<S15>/Memory' */
  real32_T Memory1;                    /* '<S14>/Memory1' */
  real32_T min;                        /* '<S13>/Gain1' */
  real32_T MathFunction1;              /* '<S13>/Math Function1' */
  real32_T Saturation;                 /* '<S277>/Saturation' */
  real32_T Integrator_DSTATE;          /* '<S60>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S108>/Integrator' */
  real32_T UnitDelay_DSTATE;           /* '<S3>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S13>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S13>/Unit Delay2' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S125>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_c;        /* '<S158>/Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S8>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE_i;/* '<S8>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S270>/Integrator' */
  real32_T RateTransition4_Buffer0;    /* '<S1>/Rate Transition4' */
  real32_T RateTransition1_Buffer;     /* '<S1>/Rate Transition1' */
  real32_T RateTransition2_Buffer;     /* '<S1>/Rate Transition2' */
  real32_T Memory_PreviousInput;       /* '<S15>/Memory' */
  real32_T Memory1_PreviousInput;      /* '<S14>/Memory1' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S125>/Discrete-Time Integrator' */
  real32_T Integrator_PREV_U;          /* '<S158>/Integrator' */
  real32_T Integrator_PREV_U_c;        /* '<S270>/Integrator' */
  int32_T clockTickCounter;            /* '<S24>/Pulse Generator' */
  uint32_T HFI_Observer_PREV_T;        /* '<S3>/HFI_Observer' */
  uint32_T temporalCounter_i1;         /* '<S2>/Chart1' */
  uint32_T speed_loop_PREV_T;          /* '<S1>/speed_loop' */
  uint16_T temporalCounter_i1_l;       /* '<S3>/Chart' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S125>/Discrete-Time Integrator' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S158>/Integrator' */
  uint8_T is_active_c3_FOC_Model;      /* '<S3>/Chart' */
  uint8_T is_c3_FOC_Model;             /* '<S3>/Chart' */
  uint8_T is_active_c7_FOC_Model;      /* '<S2>/Chart1' */
  uint8_T is_c7_FOC_Model;             /* '<S2>/Chart1' */
  uint8_T Integrator_SYSTEM_ENABLE_b;  /* '<S270>/Integrator' */
  boolean_T HFI_Observer_RESET_ELAPS_T;/* '<S3>/HFI_Observer' */
  boolean_T speed_loop_RESET_ELAPS_T;  /* '<S1>/speed_loop' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState HFI_Observer_Trig_ZCE;    /* '<S3>/HFI_Observer' */
} PrevZCX;

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
    uint32_T clockTick0;
    uint32_T clockTick1;
    struct {
      uint8_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T hfi_theta;             /* '<S3>/Merge2' */
extern real32_T ud;                    /* '<S3>/Add' */
extern real32_T uq;                    /* '<S115>/Saturation' */
extern real32_T ns_single;             /* '<S17>/Merge' */

/* Model entry point functions */
extern void FOC_Model_initialize(void);
extern void FOC_Model_step0(void);
extern void FOC_Model_step1(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Scope2' : Unused code path elimination
 * Block '<S2>/Scope6' : Unused code path elimination
 * Block '<S2>/Scope8' : Unused code path elimination
 * Block '<S1>/Rate Transition3' : Unused code path elimination
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S3>/Constant3' : Unused code path elimination
 * Block '<S13>/Fcn2' : Unused code path elimination
 * Block '<S13>/Math Function' : Unused code path elimination
 * Block '<S13>/Scope5' : Unused code path elimination
 * Block '<S13>/Scope6' : Unused code path elimination
 * Block '<S13>/Scope7' : Unused code path elimination
 * Block '<S13>/Scope8' : Unused code path elimination
 * Block '<S125>/Scope' : Unused code path elimination
 * Block '<S125>/Scope1' : Unused code path elimination
 * Block '<S14>/Scope1' : Unused code path elimination
 * Block '<S15>/Scope' : Unused code path elimination
 * Block '<S17>/Scope' : Unused code path elimination
 * Block '<S17>/Scope1' : Unused code path elimination
 * Block '<S18>/Constant1' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope10' : Unused code path elimination
 * Block '<S3>/Scope11' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S3>/Scope5' : Unused code path elimination
 * Block '<S3>/Scope6' : Unused code path elimination
 * Block '<S3>/Scope7' : Unused code path elimination
 * Block '<S3>/Scope8' : Unused code path elimination
 * Block '<S3>/Scope9' : Unused code path elimination
 * Block '<S25>/Constant2' : Unused code path elimination
 * Block '<S25>/Data Type Conversion4' : Unused code path elimination
 * Block '<S25>/Gain2' : Unused code path elimination
 * Block '<S25>/Mod1' : Unused code path elimination
 * Block '<S25>/Scope5' : Unused code path elimination
 * Block '<S177>/Atan2' : Unused code path elimination
 * Block '<S177>/Constant' : Unused code path elimination
 * Block '<S177>/Gain' : Unused code path elimination
 * Block '<S177>/Mod' : Unused code path elimination
 * Block '<S178>/Add' : Unused code path elimination
 * Block '<S178>/Atan' : Unused code path elimination
 * Block '<S178>/Constant3' : Unused code path elimination
 * Block '<S178>/Constant5' : Unused code path elimination
 * Block '<S178>/Divide' : Unused code path elimination
 * Block '<S178>/Mod1' : Unused code path elimination
 * Block '<S178>/Scope' : Unused code path elimination
 * Block '<S177>/Scope' : Unused code path elimination
 * Block '<S177>/Scope1' : Unused code path elimination
 * Block '<S177>/Scope2' : Unused code path elimination
 * Block '<S234>/Scope' : Unused code path elimination
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
 * '<S10>'  : 'foc/FOC_Model/currloop/Chart'
 * '<S11>'  : 'foc/FOC_Model/currloop/Clark_Trans'
 * '<S12>'  : 'foc/FOC_Model/currloop/Current_PI_Control'
 * '<S13>'  : 'foc/FOC_Model/currloop/HFI_Observer'
 * '<S14>'  : 'foc/FOC_Model/currloop/If Action Subsystem'
 * '<S15>'  : 'foc/FOC_Model/currloop/If Action Subsystem1'
 * '<S16>'  : 'foc/FOC_Model/currloop/If Action Subsystem10'
 * '<S17>'  : 'foc/FOC_Model/currloop/If Action Subsystem2'
 * '<S18>'  : 'foc/FOC_Model/currloop/If Action Subsystem3'
 * '<S19>'  : 'foc/FOC_Model/currloop/If Action Subsystem4'
 * '<S20>'  : 'foc/FOC_Model/currloop/If Action Subsystem5'
 * '<S21>'  : 'foc/FOC_Model/currloop/If Action Subsystem6'
 * '<S22>'  : 'foc/FOC_Model/currloop/If Action Subsystem9'
 * '<S23>'  : 'foc/FOC_Model/currloop/Park_Trans'
 * '<S24>'  : 'foc/FOC_Model/currloop/hfi_uq'
 * '<S25>'  : 'foc/FOC_Model/currloop/observer'
 * '<S26>'  : 'foc/FOC_Model/currloop/svpwm'
 * '<S27>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller'
 * '<S28>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1'
 * '<S29>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup'
 * '<S30>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain'
 * '<S31>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter'
 * '<S32>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs'
 * '<S33>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain'
 * '<S34>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain'
 * '<S35>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk'
 * '<S36>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator'
 * '<S37>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs'
 * '<S38>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy'
 * '<S39>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain'
 * '<S40>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy'
 * '<S41>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain'
 * '<S42>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal'
 * '<S43>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation'
 * '<S44>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk'
 * '<S45>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum'
 * '<S46>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk'
 * '<S47>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode'
 * '<S48>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum'
 * '<S49>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral'
 * '<S50>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain'
 * '<S51>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal'
 * '<S52>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal'
 * '<S53>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup/Passthrough'
 * '<S54>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain/Disabled'
 * '<S55>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter/Disabled'
 * '<S56>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs/Disabled'
 * '<S57>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain/External Parameters'
 * '<S58>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S59>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S60>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator/Discrete'
 * '<S61>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs/Internal IC'
 * '<S62>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S63>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain/Disabled'
 * '<S64>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy/Disabled'
 * '<S65>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain/External Parameters'
 * '<S66>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal/Disabled'
 * '<S67>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation/Enabled'
 * '<S68>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S69>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum/Sum_PI'
 * '<S70>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk/Disabled'
 * '<S71>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode/Disabled'
 * '<S72>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S73>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral/Passthrough'
 * '<S74>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S75>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal/Forward_Path'
 * '<S76>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal/Forward_Path'
 * '<S77>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup'
 * '<S78>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain'
 * '<S79>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter'
 * '<S80>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs'
 * '<S81>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain'
 * '<S82>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain'
 * '<S83>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk'
 * '<S84>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator'
 * '<S85>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs'
 * '<S86>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy'
 * '<S87>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain'
 * '<S88>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy'
 * '<S89>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain'
 * '<S90>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal'
 * '<S91>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation'
 * '<S92>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk'
 * '<S93>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum'
 * '<S94>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk'
 * '<S95>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode'
 * '<S96>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum'
 * '<S97>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral'
 * '<S98>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain'
 * '<S99>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal'
 * '<S100>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal'
 * '<S101>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup/Passthrough'
 * '<S102>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain/Disabled'
 * '<S103>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter/Disabled'
 * '<S104>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs/Disabled'
 * '<S105>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain/External Parameters'
 * '<S106>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S107>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S108>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator/Discrete'
 * '<S109>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs/Internal IC'
 * '<S110>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S111>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain/Disabled'
 * '<S112>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy/Disabled'
 * '<S113>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain/External Parameters'
 * '<S114>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal/Disabled'
 * '<S115>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation/Enabled'
 * '<S116>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S117>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum/Sum_PI'
 * '<S118>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk/Disabled'
 * '<S119>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode/Disabled'
 * '<S120>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S121>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S122>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S123>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal/Forward_Path'
 * '<S124>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal/Forward_Path'
 * '<S125>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa'
 * '<S126>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller'
 * '<S127>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Anti-windup'
 * '<S128>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/D Gain'
 * '<S129>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Filter'
 * '<S130>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Filter ICs'
 * '<S131>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/I Gain'
 * '<S132>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Ideal P Gain'
 * '<S133>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S134>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Integrator'
 * '<S135>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Integrator ICs'
 * '<S136>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/N Copy'
 * '<S137>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/N Gain'
 * '<S138>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/P Copy'
 * '<S139>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Parallel P Gain'
 * '<S140>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Reset Signal'
 * '<S141>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Saturation'
 * '<S142>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Saturation Fdbk'
 * '<S143>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Sum'
 * '<S144>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Sum Fdbk'
 * '<S145>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tracking Mode'
 * '<S146>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tracking Mode Sum'
 * '<S147>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tsamp - Integral'
 * '<S148>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tsamp - Ngain'
 * '<S149>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/postSat Signal'
 * '<S150>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/preSat Signal'
 * '<S151>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S152>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/D Gain/Disabled'
 * '<S153>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Filter/Disabled'
 * '<S154>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Filter ICs/Disabled'
 * '<S155>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S156>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S157>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S158>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Integrator/Discrete'
 * '<S159>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S160>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S161>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/N Gain/Disabled'
 * '<S162>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/P Copy/Disabled'
 * '<S163>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S164>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Reset Signal/Disabled'
 * '<S165>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Saturation/Passthrough'
 * '<S166>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S167>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Sum/Sum_PI'
 * '<S168>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S169>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S170>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S171>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S172>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S173>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S174>' : 'foc/FOC_Model/currloop/HFI_Observer/waichafa/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S175>' : 'foc/FOC_Model/currloop/If Action Subsystem2/If Action Subsystem'
 * '<S176>' : 'foc/FOC_Model/currloop/If Action Subsystem2/If Action Subsystem1'
 * '<S177>' : 'foc/FOC_Model/currloop/observer/fourth_SMO'
 * '<S178>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL'
 * '<S179>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/e_alpha'
 * '<S180>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/e_beta'
 * '<S181>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/i_alpha'
 * '<S182>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/i_beta'
 * '<S183>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl'
 * '<S184>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup'
 * '<S185>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/D Gain'
 * '<S186>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter'
 * '<S187>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter ICs'
 * '<S188>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/I Gain'
 * '<S189>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain'
 * '<S190>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain Fdbk'
 * '<S191>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator'
 * '<S192>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator ICs'
 * '<S193>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Copy'
 * '<S194>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Gain'
 * '<S195>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/P Copy'
 * '<S196>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Parallel P Gain'
 * '<S197>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Reset Signal'
 * '<S198>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation'
 * '<S199>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation Fdbk'
 * '<S200>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum'
 * '<S201>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum Fdbk'
 * '<S202>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode'
 * '<S203>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode Sum'
 * '<S204>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Integral'
 * '<S205>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Ngain'
 * '<S206>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/postSat Signal'
 * '<S207>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/preSat Signal'
 * '<S208>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel'
 * '<S209>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S210>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S211>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/D Gain/Disabled'
 * '<S212>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter/Disabled'
 * '<S213>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Filter ICs/Disabled'
 * '<S214>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/I Gain/External Parameters'
 * '<S215>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain/Passthrough'
 * '<S216>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Ideal P Gain Fdbk/Disabled'
 * '<S217>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator/Discrete'
 * '<S218>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Integrator ICs/Internal IC'
 * '<S219>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Copy/Disabled wSignal Specification'
 * '<S220>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/N Gain/Disabled'
 * '<S221>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/P Copy/Disabled'
 * '<S222>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Parallel P Gain/External Parameters'
 * '<S223>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Reset Signal/Disabled'
 * '<S224>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation/Enabled'
 * '<S225>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Saturation Fdbk/Disabled'
 * '<S226>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum/Sum_PI'
 * '<S227>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Sum Fdbk/Disabled'
 * '<S228>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode/Disabled'
 * '<S229>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tracking Mode Sum/Passthrough'
 * '<S230>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Integral/Passthrough'
 * '<S231>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/Tsamp - Ngain/Passthrough'
 * '<S232>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/postSat Signal/Forward_Path'
 * '<S233>' : 'foc/FOC_Model/currloop/observer/fourth_SMO/PLL/PIDTheta_Ctrl/preSat Signal/Forward_Path'
 * '<S234>' : 'foc/FOC_Model/currloop/svpwm/Anti_Park_Trans'
 * '<S235>' : 'foc/FOC_Model/currloop/svpwm/foc'
 * '<S236>' : 'foc/FOC_Model/speed_loop/PID Controller3'
 * '<S237>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup'
 * '<S238>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain'
 * '<S239>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter'
 * '<S240>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs'
 * '<S241>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain'
 * '<S242>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain'
 * '<S243>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S244>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator'
 * '<S245>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs'
 * '<S246>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy'
 * '<S247>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain'
 * '<S248>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy'
 * '<S249>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain'
 * '<S250>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal'
 * '<S251>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation'
 * '<S252>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk'
 * '<S253>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum'
 * '<S254>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk'
 * '<S255>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode'
 * '<S256>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S257>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral'
 * '<S258>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S259>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal'
 * '<S260>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal'
 * '<S261>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S262>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S263>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S264>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain/Disabled'
 * '<S265>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter/Disabled'
 * '<S266>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S267>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain/External Parameters'
 * '<S268>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S269>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S270>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator/Discrete'
 * '<S271>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S272>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S273>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain/Disabled'
 * '<S274>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy/Disabled'
 * '<S275>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain/External Parameters'
 * '<S276>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S277>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation/Enabled'
 * '<S278>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S279>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S280>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S281>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S282>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S283>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S284>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S285>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S286>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
