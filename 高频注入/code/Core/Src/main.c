/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FOC_Model.h"
#include "usart_vofa.h"
#include "stdio.h"
#include "mt6816.h"
#include "motor_control.h"

uint16_T adc1_in3,adc2_in1,Udc;
extern uint8_t aRxBuffer;
float theta;
uint32_t time;
#define M_PI (3.14159265358f)         // 圆周率
float normalize_angle(float angle);
float angle= 0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_TIM1_Init();
  MX_USART3_UART_Init();
  MX_SPI1_Init();
  MX_USB_Device_Init();
  /* USER CODE BEGIN 2 */
	HAL_ADCEx_Calibration_Start( &hadc1, ADC_SINGLE_ENDED);
	HAL_ADCEx_Calibration_Start( &hadc2, ADC_SINGLE_ENDED);
	__HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_JEOC);
//	__HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_EOC);
	__HAL_ADC_CLEAR_FLAG( &hadc2, ADC_FLAG_JEOC);
		__HAL_ADC_CLEAR_FLAG( &hadc2, ADC_FLAG_EOC);
	HAL_ADCEx_InjectedStart_IT( &hadc1);
	HAL_ADCEx_InjectedStart( &hadc2);
	TIM1->CCR4 = 8000-2;
	TIM1->ARR = 8000-1;
	HAL_TIM_Base_Start( &htim1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_4);
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	FOC_Model_initialize();

		rtU.id_ref = 0;
		rtU.Ubus = 12;
		rtU.Spd_ref = 20;
		rtU.MotorSwitch = 0;
		
//		currloop_U.theta = 6.28 * REIN_MT6816_Get_AngleData()/16348;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//	HAL_ADC_Start(&hadc2);
//	Udc= hadc2.Instance->DR;
//	HAL_ADCEx_RegularStop(&hadc2);
//	rtU.Ubus = Udc*3.3f/4096 *26;
//		theta = 6.28 * REIN_MT6816_Get_AngleData()/16348 +0.085098;
//FOC_Model_U.ia,FOC_Model_U.ib,FOC_Model_U.ic,
//		printf("%f,%f,%f,%f\n",rtU.theta,rtY.smo_theta,rtU.Obs_spd,rtY.smo_we);
			printf("%f,%f,%f,%f\n",ud,uq,hfi_theta,ns_single);
//		printf("%f,%f,%f,%f,%f,%f,%f,%f\n",rtU.ia,rtU.ib,rtU.ic,uq,rtY.we,rtY.Tcmp1,rtY.Tcmp2,rtY.Tcmp3);
//		if (HAL_GetTick() - time > 1)
//		{
////		CDC_Transmit_FS((uint8_t *)"USB CDC Hello!\n",15);
////			ano_send(100, 200);
//			time = HAL_GetTick();
//			vofa_send_data(0, FOC_Model_U.ia);
//			vofa_send_data(1, FOC_Model_U.ib);
//			vofa_send_data(2, FOC_Model_U.ic);
//			vofa_send_data(3, FOC_Model_U.theta);
//			vofa_send_data(4, FOC_Model_Y.smo_theta);
//			vofa_send_data(5, FOC_Model_Y.smo_we);
//			vofa_send_data(6, FOC_Model_U.Obs_spd);
//			vofa_sendframetail();
//			
//		}
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
float normalize_angle(float angle)
{
	float a = fmod(angle, 2 * M_PI); // 取余运算可以用于归一化
	return a >= 0 ? a : (a + 2 * M_PI);
}

void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
	adc1_in3 = hadc1.Instance->JDR1;
	adc2_in1 = hadc2.Instance->JDR1;
//	rtU.ia = (adc1_in3 - 2042)*0.02197f;0.01611
//	rtU.ic = (adc2_in1 - 2030)*0.02197f;
	
	rtU.ia = (adc1_in3 - 2042)*0.04028f;
	rtU.ib = (adc2_in1 - 2030)*0.04028f;
	rtU.ic = -rtU.ia - rtU.ib;
	

//	currloop_U.theta+=0.006;
	//15098       5.790462
	theta = 2 * M_PI * (REIN_MT6816_Get_AngleData())/16348;
	mt6816.mec_angle = theta;
//	theta = theta % (float)6.28;
//2.878321
	theta = normalize_angle(theta * 7) - 5.790462;
	
//	if(currloop_U.theta > 6.28)
//			currloop_U.theta = 0;
//	rtU.theta = theta;
//		currloop_U.theta =0;
	
//	rtU.Obs_spd = get_speed_M(2);
	if(motor_state==1)
	{
		rtU.MotorSwitch = 1;
//		rtDW.MathFunction1 = normalize_angle(rtDW.MathFunction1 + angle);
		
		FOC_Model_step0();
		FOC_Model_step1();
		htim1.Instance->CCR1 = rtY.Tcmp1;
		htim1.Instance->CCR2 = rtY.Tcmp2;
		htim1.Instance->CCR3 = rtY.Tcmp3;

	}else
	{
		rtU.MotorSwitch = 0;
//		FOC_Model_step();
	}
	


  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADCEx_InjectedConvCpltCallback must be implemented in the user file.
  */
}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
