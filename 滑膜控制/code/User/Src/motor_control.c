
#include "motor_control.h"
uint8_t motor_state;
void Motor_start(void)
{
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
}
void Motor_stop(void)
{
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_3);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == KEY_4_Pin)
	{
		if(motor_state==0)
		{
			Motor_start();
			motor_state = 1;
		}else
		{
			Motor_stop();
			motor_state = 0;
		}
		
		
	}

}