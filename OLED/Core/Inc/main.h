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
/* USER CODE BEGIN Private defines */
/*#define DO_F_Pin GPIO_PIN_12
#define DO_F_GPIO_Port GPIOB

#define DO_E_Pin GPIO_PIN_13
#define DO_E_GPIO_Port GPIOB

#define DO_D_Pin GPIO_PIN_14
#define DO_D_GPIO_Port GPIOB

#define DO_C_Pin GPIO_PIN_15
#define DO_C_GPIO_Port GPIOB

#define DO_B_Pin GPIO_PIN_8
#define DO_B_GPIO_Port GPIOA

#define DO_A_Pin GPIO_PIN_11
#define DO_A_GPIO_Port GPIOA*/

#define DO_Buzzer_Pin GPIO_PIN_4
#define DO_Buzzer_GPIO_Port GPIOB

#define DO_Row1_Pin GPIO_PIN_4
#define DO_Row1_GPIO_Port GPIOA

#define DO_Row2_Pin GPIO_PIN_5
#define DO_Row2_GPIO_Port GPIOA

#define DO_Row3_Pin GPIO_PIN_6
#define DO_Row3_GPIO_Port GPIOA

#define DO_Row4_Pin GPIO_PIN_7
#define DO_Row4_GPIO_Port GPIOA

#define DI_Col4_Pin GPIO_PIN_0
#define DI_Col4_GPIO_Port GPIOB

#define DI_Col3_Pin GPIO_PIN_1
#define DI_Col3_GPIO_Port GPIOB

#define DI_Col1_Pin GPIO_PIN_2
#define DI_Col1_GPIO_Port GPIOB

#define DI_Col2_Pin GPIO_PIN_10
#define DI_Col2_GPIO_Port GPIOB
/*
#define DO_D7_Pin GPIO_PIN_12
#define DO_D7_GPIO_Port GPIOB

#define DO_D6_Pin GPIO_PIN_13
#define DO_D6_GPIO_Port GPIOB

#define DO_D5_Pin GPIO_PIN_14
#define DO_D5_GPIO_Port GPIOB

#define DO_D4_Pin GPIO_PIN_15
#define DO_D4_GPIO_Port GPIOB

#define DO_EN_Pin GPIO_PIN_8
#define DO_EN_GPIO_Port GPIOA

#define DO_RS_Pin GPIO_PIN_11
#define DO_RS_GPIO_Port GPIOA
*/
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
