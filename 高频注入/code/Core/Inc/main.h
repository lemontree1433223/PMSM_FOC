/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWM_UL_Pin_Pin GPIO_PIN_13
#define PWM_UL_Pin_GPIO_Port GPIOB
#define PWM_VL_Pin_Pin GPIO_PIN_14
#define PWM_VL_Pin_GPIO_Port GPIOB
#define PWM_WL_Pin_Pin GPIO_PIN_15
#define PWM_WL_Pin_GPIO_Port GPIOB
#define KEY_4_Pin GPIO_PIN_6
#define KEY_4_GPIO_Port GPIOC
#define KEY_4_EXTI_IRQn EXTI9_5_IRQn
#define KEY_3_Pin GPIO_PIN_7
#define KEY_3_GPIO_Port GPIOC
#define KEY_3_EXTI_IRQn EXTI9_5_IRQn
#define KEY_2_Pin GPIO_PIN_8
#define KEY_2_GPIO_Port GPIOC
#define KEY_2_EXTI_IRQn EXTI9_5_IRQn
#define KEY_1_Pin GPIO_PIN_9
#define KEY_1_GPIO_Port GPIOC
#define KEY_1_EXTI_IRQn EXTI9_5_IRQn
#define PWM_UH_Pin_Pin GPIO_PIN_8
#define PWM_UH_Pin_GPIO_Port GPIOA
#define PWM_VH_Pin_Pin GPIO_PIN_9
#define PWM_VH_Pin_GPIO_Port GPIOA
#define PWM_WH_Pin_Pin GPIO_PIN_10
#define PWM_WH_Pin_GPIO_Port GPIOA
#define SPI_CS_Pin GPIO_PIN_2
#define SPI_CS_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
float normalize_angle(float angle);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
