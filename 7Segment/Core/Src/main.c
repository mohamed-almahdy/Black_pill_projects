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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
static void MX_GPIO_Init(void);
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
  /* USER CODE BEGIN 2 */
	uint8_t B_Shift=0;
	uint8_t B_Digit[3]={0,0,0};
	uint8_t B_Symbols[]={0xfc/*0*/,0x60/*1*/,0xda/*2*/,0xf2/*3*/,0x66/*4*/,0xb6/*5*/,0xbe/*6*/,0xe0/*7*/,0xfe/*8*/,0xf6/*9*/};
	const int _TIME=50;
	uint32_t Counter4time =_TIME;
	uint16_t Counter =0;
	uint16_t W_Word;
	uint8_t B_B;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		// Disable 7-segment digits
		HAL_GPIO_WritePin(DO_Sel1_GPIO_Port, DO_Sel1_Pin, 0);
		HAL_GPIO_WritePin(DO_Sel2_GPIO_Port, DO_Sel2_Pin, 0);
		HAL_GPIO_WritePin(DO_Sel3_GPIO_Port, DO_Sel3_Pin, 0);
		// Update data
		B_B=B_Symbols[B_Digit[B_Shift]];
		HAL_GPIO_WritePin(DO_DOT_GPIO_Port, DO_DOT_Pin,(B_B)&1);
		HAL_GPIO_WritePin(DO_A_GPIO_Port, DO_A_Pin,(B_B>>7)&1);
		HAL_GPIO_WritePin(DO_B_GPIO_Port, DO_B_Pin,(B_B>>6)&1);
		HAL_GPIO_WritePin(DO_C_GPIO_Port, DO_C_Pin,(B_B>>5)&1);
		HAL_GPIO_WritePin(DO_D_GPIO_Port, DO_D_Pin,(B_B>>4)&1);
		HAL_GPIO_WritePin(DO_E_GPIO_Port, DO_E_Pin,(B_B>>3)&1);
		HAL_GPIO_WritePin(DO_F_GPIO_Port, DO_F_Pin,(B_B>>2)&1);
		HAL_GPIO_WritePin(DO_G_GPIO_Port, DO_G_Pin,(B_B>>1)&1);
		// Select digit
		if(B_Shift==0)
		{
			HAL_GPIO_WritePin(DO_Sel1_GPIO_Port, DO_Sel1_Pin, 1);
			B_Shift=1;
		}
		else if(B_Shift==1)
		{
			HAL_GPIO_WritePin(DO_Sel2_GPIO_Port, DO_Sel2_Pin, 1);
			B_Shift=2;
		}
		else if(B_Shift==2)
		{
			HAL_GPIO_WritePin(DO_Sel3_GPIO_Port, DO_Sel3_Pin, 1);
			B_Shift=0;
		}
		HAL_Delay(1);



		if(Counter4time==0)
		{
			Counter4time=_TIME;

			if(Counter==999)
				Counter=0;
			else
				Counter++;

			W_Word=Counter;
			B_Digit[0]=W_Word /100;
			W_Word=W_Word %100;
			B_Digit[1]=W_Word /10;
			W_Word=W_Word %10;
			B_Digit[2]=W_Word;

		}
		else
		{
			Counter4time--;
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DO_F_Pin|DO_E_Pin|DO_D_Pin|DO_C_Pin
                          |DO_Sel3_Pin|DO_Sel1_Pin|DO_Sel2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DO_B_Pin|DO_A_Pin|DO_G_Pin|DO_DOT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DO_F_Pin DO_E_Pin DO_D_Pin DO_C_Pin
                           DO_Sel3_Pin DO_Sel1_Pin DO_Sel2_Pin */
  GPIO_InitStruct.Pin = DO_F_Pin|DO_E_Pin|DO_D_Pin|DO_C_Pin
                          |DO_Sel3_Pin|DO_Sel1_Pin|DO_Sel2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : DO_B_Pin DO_A_Pin DO_G_Pin DO_DOT_Pin */
  GPIO_InitStruct.Pin = DO_B_Pin|DO_A_Pin|DO_G_Pin|DO_DOT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

