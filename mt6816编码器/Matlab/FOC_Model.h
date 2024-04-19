/*
 * File: FOC_Model.h
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

/* Exported data define */

/* Definition for custom storage class: Define */
#define Flux_Ki                        2500.0F                   /* Referenced by: '<S111>/Constant1' */
#define Flux_Kp                        100.0F                    /* Referenced by: '<S111>/Constant' */
#define Gamma                          70000000.0F                 /* Referenced by:
                                                                  * '<S112>/Constant'
                                                                  * '<S112>/Constant2'
                                                                  */

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T RateTransition4;            /* '<S1>/Rate Transition4' */
  real32_T RateTransition3;            /* '<S1>/Rate Transition3' */
  real32_T Switch2;                    /* '<S214>/Switch2' */
  real32_T Integrator_DSTATE;          /* '<S43>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S92>/Integrator' */
  real32_T UnitDelay2_DSTATE;          /* '<S2>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S112>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S112>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_k;        /* '<S2>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S111>/Discrete-Time Integrator' */
  real32_T Integrator_DSTATE_j;        /* '<S148>/Integrator' */
  real32_T Integrator_DSTATE_d;        /* '<S206>/Integrator' */
  real32_T RateTransition4_Buffer0;    /* '<S1>/Rate Transition4' */
  real32_T Integrator_PREV_U;          /* '<S206>/Integrator' */
  int32_T RateTransition1;             /* '<S1>/Rate Transition1' */
  int32_T RateTransition2;             /* '<S1>/Rate Transition2' */
  uint32_T speed_loop_PREV_T;          /* '<S1>/speed_loop' */
  uint16_T temporalCounter_i1;         /* '<S3>/Chart1' */
  int8_T Integrator_PrevResetState;    /* '<S206>/Integrator' */
  uint8_T is_active_c2_FOC_Model;      /* '<S3>/Chart1' */
  uint8_T is_c2_FOC_Model;             /* '<S3>/Chart1' */
  uint8_T Integrator_SYSTEM_ENABLE;    /* '<S206>/Integrator' */
  boolean_T speed_loop_RESET_ELAPS_T;  /* '<S1>/speed_loop' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Inport1;                    /* '<Root>/Inport1' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  int32_T Outport2;                    /* '<Root>/Outport2' */
} ExtY;

/* Type definition for custom storage class: Struct */
typedef struct foc_tag {
  int32_T spd_fdbk;                    /* '<Root>/Spd_fdbk' */
  int32_T spd_ref;                     /* '<Root>/Spd_ref' */
  real32_T Ibus;                       /* Referenced by:
                                        * '<S4>/Constant2'
                                        * '<S4>/Constant3'
                                        */
  real32_T Sector;                     /* '<S9>/foc' */
  real32_T Tcmp1;                      /* '<S9>/foc' */
  real32_T Tcmp2;                      /* '<S9>/foc' */
  real32_T Tcmp3;                      /* '<S9>/foc' */
  real32_T Ts;                         /* Referenced by:
                                        * '<S112>/Gain2'
                                        * '<S112>/Gain7'
                                        */
  real32_T Ubus;                       /* '<Root>/Ubus' */
  real32_T i_alpha;                    /* '<S2>/Clark_Trans' */
  real32_T i_beta;                     /* '<S2>/Clark_Trans' */
  real32_T ia;                         /* '<Root>/ia' */
  real32_T ib;                         /* '<Root>/ib' */
  real32_T ic;                         /* '<Root>/ic' */
  real32_T id;                         /* '<S2>/Park_Trans' */
  real32_T id_align;                   /* Referenced by: '<S169>/Constant2' */
  real32_T id_gain;                    /* Referenced by: '<S170>/Constant2' */
  real32_T id_ref;                     /* '<S3>/Merge2' */
  real32_T iq;                         /* '<S2>/Park_Trans' */
  real32_T iq_ref;                     /* '<S3>/Merge1' */
  real32_T theta_input;                /* '<Root>/theta' */
  real32_T theta_real;                 /* '<S3>/Merge3' */
  real32_T u_alpha;                    /* '<S9>/Anti_Park_Trans' */
  real32_T u_beta;                     /* '<S9>/Anti_Park_Trans' */
  real32_T ud;                         /* '<S51>/Switch2' */
  real32_T uq;                         /* '<S100>/Switch2' */
  uint8_T motor_state;                 /* '<S3>/Chart1' */
} foc_type;

typedef struct motor_tag {
  real32_T Flux;                       /* Referenced by:
                                        * '<S112>/Constant1'
                                        * '<S112>/Gain4'
                                        * '<S112>/Gain9'
                                        */
  real32_T Ls;                         /* Referenced by:
                                        * '<S6>/Constant3'
                                        * '<S112>/Gain1'
                                        * '<S112>/Gain3'
                                        * '<S112>/Gain5'
                                        * '<S112>/Gain8'
                                        */
  real32_T Pn;                         /* Referenced by: '<S8>/wm->Nr2' */
  real32_T Rs;                         /* Referenced by:
                                        * '<S6>/Constant4'
                                        * '<S112>/Gain'
                                        * '<S112>/Gain6'
                                        */
} motor_type;

typedef struct observer_flux_tag {
  real32_T flux_spd;                   /* '<S115>/Add1' */
  real32_T flux_theta;                 /* '<S111>/Mod' */
  real32_T theta_cos;                  /* '<S112>/Gain4' */
  real32_T theta_sin;                  /* '<S112>/Gain9' */
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

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern uint8_T motor_switch;           /* '<Root>/MotorSwitch' */

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
 * Block '<S1>/Scope3' : Unused code path elimination
 * Block '<S1>/Scope4' : Unused code path elimination
 * Block '<S2>/Add' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Propagation' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope2' : Unused code path elimination
 * Block '<S2>/Scope5' : Unused code path elimination
 * Block '<S2>/Scope6' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S111>/Scope' : Unused code path elimination
 * Block '<S111>/Scope1' : Unused code path elimination
 * Block '<S112>/Add10' : Unused code path elimination
 * Block '<S112>/Scope' : Unused code path elimination
 * Block '<S112>/Scope1' : Unused code path elimination
 * Block '<S112>/Scope11' : Unused code path elimination
 * Block '<S112>/Scope2' : Unused code path elimination
 * Block '<S112>/Scope3' : Unused code path elimination
 * Block '<S112>/Scope4' : Unused code path elimination
 * Block '<S112>/Scope5' : Unused code path elimination
 * Block '<S112>/Scope6' : Unused code path elimination
 * Block '<S112>/Square' : Unused code path elimination
 * Block '<S112>/Square Root' : Unused code path elimination
 * Block '<S112>/Square1' : Unused code path elimination
 * Block '<S165>/Scope' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S214>/Data Type Propagation' : Unused code path elimination
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
 * '<S2>'   : 'foc/FOC_Model/currloop'
 * '<S3>'   : 'foc/FOC_Model/flux_state'
 * '<S4>'   : 'foc/FOC_Model/speed_loop'
 * '<S5>'   : 'foc/FOC_Model/currloop/Clark_Trans'
 * '<S6>'   : 'foc/FOC_Model/currloop/Current_PI_Control'
 * '<S7>'   : 'foc/FOC_Model/currloop/Park_Trans'
 * '<S8>'   : 'foc/FOC_Model/currloop/observer_flux'
 * '<S9>'   : 'foc/FOC_Model/currloop/svpwm'
 * '<S10>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller'
 * '<S11>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1'
 * '<S12>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup'
 * '<S13>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain'
 * '<S14>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter'
 * '<S15>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs'
 * '<S16>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain'
 * '<S17>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain'
 * '<S18>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk'
 * '<S19>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator'
 * '<S20>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs'
 * '<S21>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy'
 * '<S22>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain'
 * '<S23>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy'
 * '<S24>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain'
 * '<S25>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal'
 * '<S26>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation'
 * '<S27>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk'
 * '<S28>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum'
 * '<S29>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk'
 * '<S30>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode'
 * '<S31>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum'
 * '<S32>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral'
 * '<S33>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain'
 * '<S34>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal'
 * '<S35>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal'
 * '<S36>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Anti-windup/Passthrough'
 * '<S37>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/D Gain/Disabled'
 * '<S38>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter/Disabled'
 * '<S39>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Filter ICs/Disabled'
 * '<S40>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/I Gain/External Parameters'
 * '<S41>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator/Discrete'
 * '<S44>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S46>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/N Gain/Disabled'
 * '<S47>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/P Copy/Disabled'
 * '<S48>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Parallel P Gain/External Parameters'
 * '<S49>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Reset Signal/Disabled'
 * '<S50>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation/External'
 * '<S51>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation/External/Saturation Dynamic'
 * '<S52>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum/Sum_PI'
 * '<S54>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Integral/Passthrough'
 * '<S58>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller/preSat Signal/Forward_Path'
 * '<S61>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup'
 * '<S62>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain'
 * '<S63>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter'
 * '<S64>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs'
 * '<S65>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain'
 * '<S66>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain'
 * '<S67>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk'
 * '<S68>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator'
 * '<S69>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs'
 * '<S70>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy'
 * '<S71>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain'
 * '<S72>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy'
 * '<S73>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain'
 * '<S74>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal'
 * '<S75>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation'
 * '<S76>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk'
 * '<S77>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum'
 * '<S78>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk'
 * '<S79>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode'
 * '<S80>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum'
 * '<S81>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral'
 * '<S82>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain'
 * '<S83>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal'
 * '<S84>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal'
 * '<S85>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Anti-windup/Passthrough'
 * '<S86>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/D Gain/Disabled'
 * '<S87>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter/Disabled'
 * '<S88>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Filter ICs/Disabled'
 * '<S89>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/I Gain/External Parameters'
 * '<S90>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S91>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S92>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator/Discrete'
 * '<S93>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Integrator ICs/Internal IC'
 * '<S94>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S95>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/N Gain/Disabled'
 * '<S96>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/P Copy/Disabled'
 * '<S97>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Parallel P Gain/External Parameters'
 * '<S98>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Reset Signal/Disabled'
 * '<S99>'  : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation/External'
 * '<S100>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation/External/Saturation Dynamic'
 * '<S101>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S102>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum/Sum_PI'
 * '<S103>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Sum Fdbk/Disabled'
 * '<S104>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode/Disabled'
 * '<S105>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S106>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S107>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S108>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/postSat Signal/Forward_Path'
 * '<S109>' : 'foc/FOC_Model/currloop/Current_PI_Control/PID Controller1/preSat Signal/Forward_Path'
 * '<S110>' : 'foc/FOC_Model/currloop/observer_flux/IIR Filter'
 * '<S111>' : 'foc/FOC_Model/currloop/observer_flux/PLL'
 * '<S112>' : 'foc/FOC_Model/currloop/observer_flux/noliner'
 * '<S113>' : 'foc/FOC_Model/currloop/observer_flux/IIR Filter/IIR Filter'
 * '<S114>' : 'foc/FOC_Model/currloop/observer_flux/IIR Filter/IIR Filter/Low-pass'
 * '<S115>' : 'foc/FOC_Model/currloop/observer_flux/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S116>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller'
 * '<S117>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Anti-windup'
 * '<S118>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/D Gain'
 * '<S119>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Filter'
 * '<S120>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Filter ICs'
 * '<S121>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/I Gain'
 * '<S122>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Ideal P Gain'
 * '<S123>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S124>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Integrator'
 * '<S125>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Integrator ICs'
 * '<S126>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/N Copy'
 * '<S127>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/N Gain'
 * '<S128>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/P Copy'
 * '<S129>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Parallel P Gain'
 * '<S130>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Reset Signal'
 * '<S131>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Saturation'
 * '<S132>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Saturation Fdbk'
 * '<S133>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Sum'
 * '<S134>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Sum Fdbk'
 * '<S135>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tracking Mode'
 * '<S136>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tracking Mode Sum'
 * '<S137>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tsamp - Integral'
 * '<S138>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tsamp - Ngain'
 * '<S139>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/postSat Signal'
 * '<S140>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/preSat Signal'
 * '<S141>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S142>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/D Gain/Disabled'
 * '<S143>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Filter/Disabled'
 * '<S144>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Filter ICs/Disabled'
 * '<S145>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/I Gain/External Parameters'
 * '<S146>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S147>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S148>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Integrator/Discrete'
 * '<S149>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S150>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S151>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/N Gain/Disabled'
 * '<S152>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/P Copy/Disabled'
 * '<S153>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Parallel P Gain/External Parameters'
 * '<S154>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Reset Signal/Disabled'
 * '<S155>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Saturation/Enabled'
 * '<S156>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S157>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Sum/Sum_PI'
 * '<S158>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S159>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S160>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S161>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tsamp - Integral/Passthrough'
 * '<S162>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S163>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S164>' : 'foc/FOC_Model/currloop/observer_flux/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S165>' : 'foc/FOC_Model/currloop/svpwm/Anti_Park_Trans'
 * '<S166>' : 'foc/FOC_Model/currloop/svpwm/foc'
 * '<S167>' : 'foc/FOC_Model/flux_state/Chart1'
 * '<S168>' : 'foc/FOC_Model/flux_state/If Action Subsystem'
 * '<S169>' : 'foc/FOC_Model/flux_state/If Action Subsystem1'
 * '<S170>' : 'foc/FOC_Model/flux_state/If Action Subsystem3'
 * '<S171>' : 'foc/FOC_Model/speed_loop/PID Controller3'
 * '<S172>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup'
 * '<S173>' : 'foc/FOC_Model/speed_loop/PID Controller3/D Gain'
 * '<S174>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter'
 * '<S175>' : 'foc/FOC_Model/speed_loop/PID Controller3/Filter ICs'
 * '<S176>' : 'foc/FOC_Model/speed_loop/PID Controller3/I Gain'
 * '<S177>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain'
 * '<S178>' : 'foc/FOC_Model/speed_loop/PID Controller3/Ideal P Gain Fdbk'
 * '<S179>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator'
 * '<S180>' : 'foc/FOC_Model/speed_loop/PID Controller3/Integrator ICs'
 * '<S181>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Copy'
 * '<S182>' : 'foc/FOC_Model/speed_loop/PID Controller3/N Gain'
 * '<S183>' : 'foc/FOC_Model/speed_loop/PID Controller3/P Copy'
 * '<S184>' : 'foc/FOC_Model/speed_loop/PID Controller3/Parallel P Gain'
 * '<S185>' : 'foc/FOC_Model/speed_loop/PID Controller3/Reset Signal'
 * '<S186>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation'
 * '<S187>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk'
 * '<S188>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum'
 * '<S189>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk'
 * '<S190>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode'
 * '<S191>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum'
 * '<S192>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral'
 * '<S193>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain'
 * '<S194>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal'
 * '<S195>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal'
 * '<S196>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel'
 * '<S197>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S198>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/External'
 * '<S199>' : 'foc/FOC_Model/speed_loop/PID Controller3/Anti-windup/Disc. Clamping Parallel/Dead Zone/External/Dead Zone Dynamic'
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
 * '<S213>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation/External'
 * '<S214>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation/External/Saturation Dynamic'
 * '<S215>' : 'foc/FOC_Model/speed_loop/PID Controller3/Saturation Fdbk/Disabled'
 * '<S216>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum/Sum_PI'
 * '<S217>' : 'foc/FOC_Model/speed_loop/PID Controller3/Sum Fdbk/Disabled'
 * '<S218>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode/Disabled'
 * '<S219>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S220>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S221>' : 'foc/FOC_Model/speed_loop/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S222>' : 'foc/FOC_Model/speed_loop/PID Controller3/postSat Signal/Forward_Path'
 * '<S223>' : 'foc/FOC_Model/speed_loop/PID Controller3/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
