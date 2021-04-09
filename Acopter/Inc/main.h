/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define tim3_ch1_rc1_Pin GPIO_PIN_6
#define tim3_ch1_rc1_GPIO_Port GPIOA
#define tim3_ch2_rc2_Pin GPIO_PIN_7
#define tim3_ch2_rc2_GPIO_Port GPIOA
#define tim3_ch3_rc3_Pin GPIO_PIN_0
#define tim3_ch3_rc3_GPIO_Port GPIOB
#define tim3_ch4_rc4_Pin GPIO_PIN_1
#define tim3_ch4_rc4_GPIO_Port GPIOB
#define tim1_ch1_out5_Pin GPIO_PIN_9
#define tim1_ch1_out5_GPIO_Port GPIOE
#define tim1_ch2_out6_Pin GPIO_PIN_11
#define tim1_ch2_out6_GPIO_Port GPIOE
#define tim1_ch3_out7_Pin GPIO_PIN_13
#define tim1_ch3_out7_GPIO_Port GPIOE
#define tim1_ch4_out8_Pin GPIO_PIN_14
#define tim1_ch4_out8_GPIO_Port GPIOE
#define tim2_ch3_rc5_Pin GPIO_PIN_10
#define tim2_ch3_rc5_GPIO_Port GPIOB
#define tim2_ch4_rc6_Pin GPIO_PIN_11
#define tim2_ch4_rc6_GPIO_Port GPIOB
#define tim12_ch1_rc7_Pin GPIO_PIN_14
#define tim12_ch1_rc7_GPIO_Port GPIOB
#define tim12_ch2_rc8_Pin GPIO_PIN_15
#define tim12_ch2_rc8_GPIO_Port GPIOB
#define tim4_ch1_out1_Pin GPIO_PIN_12
#define tim4_ch1_out1_GPIO_Port GPIOD
#define tim4_ch2_out2_Pin GPIO_PIN_13
#define tim4_ch2_out2_GPIO_Port GPIOD
#define tim4_ch3_out3_Pin GPIO_PIN_14
#define tim4_ch3_out3_GPIO_Port GPIOD
#define tim4_ch4_out4_Pin GPIO_PIN_15
#define tim4_ch4_out4_GPIO_Port GPIOD
#define CS_MPU_Pin GPIO_PIN_0
#define CS_MPU_GPIO_Port GPIOD
#define IIC_SCL_Pin GPIO_PIN_3
#define IIC_SCL_GPIO_Port GPIOB
#define IIC_SDA_Pin GPIO_PIN_5
#define IIC_SDA_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
