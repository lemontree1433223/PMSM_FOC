/*
 * File: FOC_Model.h
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

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T RateTransition3;            /* '<S1>/Rate Transition3' */
  real32_T RateTransition4;            /* '<S1>/Rate Transition4' */
  real32_T Merge2;                     /* '<S2>/Merge2' */
  real32_T Saturation;                 /* '<S206>/Saturation' */
  real32_T UnitDelay_DSTATE;           /* '<S113>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S112>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE;          /* '<S47>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S95>/Integrator' */
  real32_T UnitDelay1_DSTATE;          /* '<S113>/Unit Delay1' */
  real32_T Integrator_DSTATE_j;        /* '<S146>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S199>/Integrator' */
  real32_T RateTransition4_Buffer0;    /* '<S1>/Rate Transition4' */
  real32_T Integrator_PREV_U;          /* '<S199>/Integrator' */
  uint32_T speed_loop_PREV_T;          /* '<S1>/speed_loop' */
  uint16_T temporalCounter_i1;         /* '<S2>/Chart1' */
  int8_T Integrator_PrevResetState;    /* '<S199>/Integrator' */
  uint8_T is_active_c2_FOC_Model;      /* '<S2>/Chart1' */
  uint8_T is_c2_FOC_Model;             /* '<S2>/Chart1' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S199>/Integrator' */
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

/* Type definition for custom storage class: Struct */
typedef struct foc_tag {
  real32_T spd_ref;                    /* '<S1>/Rate Transition2' */
  real32_T flux_theta;                 /* '<S112>/Mod' */
  real32_T theta_real;                 /* '<S2>/Merge3' */
  real32_T id_ref;                     /* '<S1>/Add' */
  real32_T i_alpha;                    /* '<S3>/Clark_Trans' */
  real32_T i_beta;                     /* '<S3>/Clark_Trans' */
  real32_T id;                         /* '<S3>/Park_Trans' */
  real32_T ud;                         /* '<S54>/Saturation' */
  real32_T iq_ref;                     /* '<S2>/Merge1' */
  real32_T iq;                         /* '<S3>/Park_Trans' */
  real32_T uq;                         /* '<S102>/Saturation' */
  real32_T u_alpha;                    /* '<S13>/Anti_Park_Trans' */
  real32_T u_beta;                     /* '<S13>/Anti_Park_Trans' */
  real32_T spd_fdbk;                   /* '<S1>/Rate Transition1' */
} foc_type;

typedef struct motor_tag {
  real32_T Flux;                       /* Referenced by:
                                        * '<S113>/Constant1'
                                        * '<S113>/Gain4'
                                        * '<S113>/Gain9'
                                        */
  real32_T Ls;                         /* Referenced by:
                                        * '<S10>/Constant3'
                                        * '<S113>/Gain1'
                                        * '<S113>/Gain3'
                                        * '<S113>/Gain5'
                                        * '<S113>/Gain8'
                                        */
  real32_T Rs;                         /* Referenced by:
                                        * '<S10>/Constant4'
                                        * '<S113>/Gain'
                                        * '<S113>/Gain6'
                                        */
} motor_type;

typedef struct observer_flux_tag {
  real32_T theta_cos;                  /* '<S113>/Gain4' */
  real32_T theta_sin;                  /* '<S113>/Gain9' */
} observer_flux_type;

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

/* Exported data declaration */

/* Declaration for custom storage class: Struct */
extern foc_type foc;
extern motor_type motor;
extern observer_flux_type observer_flux;

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/Scope2' : Unused code path elimination
 * Block '<S3>/Add' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope2' : Unused code path elimination
 * Block '<S112>/Scope' : Unused code path elimination
 * Block '<S112>/Scope1' : Unused code path elimination
 * Block '<S113>/Add10' : Unused code path elimination
 * Block '<S113>/Scope' : Unused code path elimination
 * Block '<S113>/Scope1' : Unused code path elimination
 * Block '<S113>/Scope11' : Unused code path elimination
 * Block '<S113>/Scope2' : Unused code path elimination
 * Block '<S113>/Scope3' : Unused code path elimination
 * Block '<S113>/Scope4' : Unused code path elimination
 * Block '<S113>/Scope5' : Unused code path elimination
 * Block '<S113>/Square' : Unused code path elimination
 * Block '<S113>/Square Root' : Unused code path elimination
 * Block '<S113>/Square1' : Unused code path elimination
 * Block '<S163>/Scope' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
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
 * '<S2>'   : 'foc/FOC_Model/Subsystem'
 * '<S3>'   : 'foc/FOC_Model/currloop'
 * '<S4>'   : 'foc/FOC_Model/speed_loop'
 * '<S5>'   : 'foc/FOC_Model/Subsystem/Chart1'
 * '<S6>'   : 'foc/FOC_Model/Subsystem/If Action Subsystem'
 * '<S7>'   : 'foc/FOC_Model/Subsystem/If Action Subsystem1'
 * '<S8>'   : 'foc/FOC_Model/Subsystem/If Action Subsystem3'
 * '<S9>'   : 'foc/FOC_Model/currloop/Clark_Trans'
 * '<S10>'  : 'foc/FOC_Model/currloop/Current_PI_Control'
 * '<S11>'  : 'foc/FOC_Model/currloop/Park_Trans'
 * '<S12>'  : 'foc/FOC_Model/currloop/Subsystem2'
 * '<S13>'  : 'foc/FOC_Model/currloop/svpwm'
 * '<S14>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller'
 * '<S15>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1'
 * '<S16>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup'
 * '<S17>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain'
 * '<S18>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter'
 * '<S19>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs'
 * '<S20>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain'
 * '<S21>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain'
 * '<S22>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk'
 * '<S23>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator'
 * '<S24>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs'
 * '<S25>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy'
 * '<S26>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain'
 * '<S27>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy'
 * '<S28>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain'
 * '<S29>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal'
 * '<S30>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation'
 * '<S31>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk'
 * '<S32>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum'
 * '<S33>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk'
 * '<S34>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode'
 * '<S35>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum'
 * '<S36>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral'
 * '<S37>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain'
 * '<S38>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal'
 * '<S39>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal'
 * '<S40>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup/Passthrough'
 * '<S41>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain/Disabled'
 * '<S42>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter/Disabled'
 * '<S43>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs/Disabled'
 * '<S44>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain/External Parameters'
 * '<S45>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S46>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator/Discrete'
 * '<S48>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs/Internal IC'
 * '<S49>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain/Disabled'
 * '<S51>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy/Disabled'
 * '<S52>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain/External Parameters'
 * '<S53>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal/Disabled'
 * '<S54>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation/Enabled'
 * '<S55>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S56>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum/Sum_PI'
 * '<S57>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk/Disabled'
 * '<S58>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode/Disabled'
 * '<S59>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal/Forward_Path'
 * '<S63>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal/Forward_Path'
 * '<S64>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup'
 * '<S65>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain'
 * '<S66>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter'
 * '<S67>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs'
 * '<S68>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain'
 * '<S69>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain'
 * '<S70>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk'
 * '<S71>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator'
 * '<S72>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs'
 * '<S73>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy'
 * '<S74>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain'
 * '<S75>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy'
 * '<S76>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain'
 * '<S77>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal'
 * '<S78>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation'
 * '<S79>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk'
 * '<S80>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum'
 * '<S81>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk'
 * '<S82>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode'
 * '<S83>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum'
 * '<S84>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral'
 * '<S85>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain'
 * '<S86>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal'
 * '<S87>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal'
 * '<S88>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup/Passthrough'
 * '<S89>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain/Disabled'
 * '<S90>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter/Disabled'
 * '<S91>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs/Disabled'
 * '<S92>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain/External Parameters'
 * '<S93>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator/Discrete'
 * '<S96>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs/Internal IC'
 * '<S97>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S98>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain/Disabled'
 * '<S99>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy/Disabled'
 * '<S100>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain/External Parameters'
 * '<S101>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal/Disabled'
 * '<S102>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation/Enabled'
 * '<S103>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S104>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum/Sum_PI'
 * '<S105>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk/Disabled'
 * '<S106>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode/Disabled'
 * '<S107>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S109>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal/Forward_Path'
 * '<S111>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal/Forward_Path'
 * '<S112>' : 'foc/FOC_Model/currloop/Subsystem2/PLL'
 * '<S113>' : 'foc/FOC_Model/currloop/Subsystem2/noliner'
 * '<S114>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller'
 * '<S115>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Anti-windup'
 * '<S116>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/D Gain'
 * '<S117>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Filter'
 * '<S118>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Filter ICs'
 * '<S119>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/I Gain'
 * '<S120>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Ideal P Gain'
 * '<S121>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S122>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Integrator'
 * '<S123>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Integrator ICs'
 * '<S124>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/N Copy'
 * '<S125>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/N Gain'
 * '<S126>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/P Copy'
 * '<S127>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Parallel P Gain'
 * '<S128>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Reset Signal'
 * '<S129>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Saturation'
 * '<S130>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Saturation Fdbk'
 * '<S131>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Sum'
 * '<S132>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Sum Fdbk'
 * '<S133>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tracking Mode'
 * '<S134>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tracking Mode Sum'
 * '<S135>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tsamp - Integral'
 * '<S136>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tsamp - Ngain'
 * '<S137>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/postSat Signal'
 * '<S138>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/preSat Signal'
 * '<S139>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S140>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/D Gain/Disabled'
 * '<S141>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Filter/Disabled'
 * '<S142>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Filter ICs/Disabled'
 * '<S143>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S144>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S145>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S146>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Integrator/Discrete'
 * '<S147>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S148>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S149>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/N Gain/Disabled'
 * '<S150>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/P Copy/Disabled'
 * '<S151>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S152>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Reset Signal/Disabled'
 * '<S153>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Saturation/Enabled'
 * '<S154>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S155>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Sum/Sum_PI'
 * '<S156>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S157>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S158>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S159>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tsamp - Integral/Passthrough'
 * '<S160>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S161>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S162>' : 'foc/FOC_Model/currloop/Subsystem2/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S163>' : 'foc/FOC_Model/currloop/svpwm/Anti_Park_Trans'
 * '<S164>' : 'foc/FOC_Model/currloop/svpwm/foc'
 * '<S165>' : 'foc/FOC_Model/speed_loop/PID Controller3'
 * '<S166>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup'
 * '<S167>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain'
 * '<S168>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter'
 * '<S169>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs'
 * '<S170>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain'
 * '<S171>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain'
 * '<S172>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S173>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator'
 * '<S174>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs'
 * '<S175>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy'
 * '<S176>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain'
 * '<S177>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy'
 * '<S178>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain'
 * '<S179>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal'
 * '<S180>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation'
 * '<S181>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk'
 * '<S182>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum'
 * '<S183>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk'
 * '<S184>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode'
 * '<S185>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S186>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral'
 * '<S187>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S188>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal'
 * '<S189>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal'
 * '<S190>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S191>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S192>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S193>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain/Disabled'
 * '<S194>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter/Disabled'
 * '<S195>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs/Disabled'
 * '<S196>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain/External Parameters'
 * '<S197>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain/Passthrough'
 * '<S198>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S199>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator/Discrete'
 * '<S200>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs/Internal IC'
 * '<S201>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S202>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain/Disabled'
 * '<S203>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy/Disabled'
 * '<S204>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain/External Parameters'
 * '<S205>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal/External Reset'
 * '<S206>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation/Enabled'
 * '<S207>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S208>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S209>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S210>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S211>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S212>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S213>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S214>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S215>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
