#ifndef __MOTOR_CONTROL_H
#define __MOTOR_CONTROL_H
#include "tim.h"
extern uint8_t motor_state;
void Motor_start(void);
void Motor_stop(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
#endif

