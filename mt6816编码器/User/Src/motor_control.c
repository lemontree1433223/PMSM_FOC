#include "motor_control.h"
#include "FOC_Model.h"

void Motor_start(void)
{
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_4);
}
void Motor_stop(void)
{
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_4);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == KEY_4_Pin)
	{
		if(motor_switch==0)
		{
			Motor_start();
			motor_switch = 1;
		}else
		{
			Motor_stop();
			motor_switch = 0;
		}
		
		
	}

}