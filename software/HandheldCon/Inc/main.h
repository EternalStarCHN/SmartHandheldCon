/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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
#define Menu_Pin GPIO_PIN_1
#define Menu_GPIO_Port GPIOF
#define Menu_EXTI_IRQn EXTI1_IRQn
#define DC_Pin GPIO_PIN_4
#define DC_GPIO_Port GPIOA
#define RST_Pin GPIO_PIN_4
#define RST_GPIO_Port GPIOC
#define CS_Pin GPIO_PIN_5
#define CS_GPIO_Port GPIOC
#define LED_Pin GPIO_PIN_0
#define LED_GPIO_Port GPIOB
#define Return_Pin GPIO_PIN_11
#define Return_GPIO_Port GPIOC
#define Return_EXTI_IRQn EXTI15_10_IRQn
#define LightControl_Pin GPIO_PIN_12
#define LightControl_GPIO_Port GPIOC
#define LightControl_EXTI_IRQn EXTI15_10_IRQn
#define Confirm_Pin GPIO_PIN_0
#define Confirm_GPIO_Port GPIOD
#define Confirm_EXTI_IRQn EXTI0_IRQn
#define Up_Pin GPIO_PIN_2
#define Up_GPIO_Port GPIOD
#define Up_EXTI_IRQn EXTI2_IRQn
#define Left_Pin GPIO_PIN_4
#define Left_GPIO_Port GPIOD
#define Left_EXTI_IRQn EXTI4_IRQn
#define Right_Pin GPIO_PIN_5
#define Right_GPIO_Port GPIOD
#define Right_EXTI_IRQn EXTI9_5_IRQn
#define Led_Red_Pin GPIO_PIN_10
#define Led_Red_GPIO_Port GPIOG
#define Led_Yellow_Pin GPIO_PIN_11
#define Led_Yellow_GPIO_Port GPIOG
#define Led_Blue_Pin GPIO_PIN_12
#define Led_Blue_GPIO_Port GPIOG
#define Led_Green_Pin GPIO_PIN_13
#define Led_Green_GPIO_Port GPIOG
#define Buzzer_Pin GPIO_PIN_14
#define Buzzer_GPIO_Port GPIOG
#define Down_Pin GPIO_PIN_3
#define Down_GPIO_Port GPIOB
#define Down_EXTI_IRQn EXTI3_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
