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
#include "LCD1602.h"
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
TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
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
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim1);
  uint8_t  B_B ;
  uint8_t B_B_old=0;
  lcd_init ();
  lcd_clear();

  lcd_put_cur(0, 0);
  lcd_send_string("   Panda+ Kit   ");
  lcd_put_cur(1, 0);
  lcd_send_string("SW -- is Preesed");

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	B_B=0;
//	while (B_B==0)
//	{
	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 0);
	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 1);
	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 1);
	HAL_GPIO_WritePin(DO_Row4_GPIO_Port, DO_Row4_Pin, 1);
	if (HAL_GPIO_ReadPin(DI_Col1_GPIO_Port, DI_Col1_Pin) == 0 )B_B=1;
	else if(HAL_GPIO_ReadPin(DI_Col2_GPIO_Port, DI_Col2_Pin) == 0)B_B=2;
	else if(HAL_GPIO_ReadPin(DI_Col3_GPIO_Port, DI_Col3_Pin) == 0)B_B=3;
	else if(HAL_GPIO_ReadPin(DI_Col4_GPIO_Port, DI_Col4_Pin) == 0)B_B=4;
	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 1);
//	if (B_B!=0) goto Exit_Scan;
	//-----
	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 0);
	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 1);
	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 1);
	HAL_GPIO_WritePin(DO_Row4_GPIO_Port, DO_Row4_Pin, 1);
	if (HAL_GPIO_ReadPin(DI_Col1_GPIO_Port, DI_Col1_Pin) == 0 )B_B=5;
	else if(HAL_GPIO_ReadPin(DI_Col2_GPIO_Port, DI_Col2_Pin) == 0)B_B=6;
	else if(HAL_GPIO_ReadPin(DI_Col3_GPIO_Port, DI_Col3_Pin) == 0)B_B=7;
	else if(HAL_GPIO_ReadPin(DI_Col4_GPIO_Port, DI_Col4_Pin) == 0)B_B=8;
	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 1);
//	if (B_B!=0) goto Exit_Scan;
	//-----
	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 0);
	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 1);
	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 1);
	HAL_GPIO_WritePin(DO_Row4_GPIO_Port, DO_Row4_Pin, 1);
	if (HAL_GPIO_ReadPin(DI_Col1_GPIO_Port, DI_Col1_Pin) == 0 )B_B=9;
	else if(HAL_GPIO_ReadPin(DI_Col2_GPIO_Port, DI_Col2_Pin) == 0)B_B=10;
	else if(HAL_GPIO_ReadPin(DI_Col3_GPIO_Port, DI_Col3_Pin) == 0)B_B=11;
	else if(HAL_GPIO_ReadPin(DI_Col4_GPIO_Port, DI_Col4_Pin) == 0)B_B=12;
	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 1);
//	if (B_B!=0) goto Exit_Scan;
	//-----
	HAL_GPIO_WritePin(DO_Row4_GPIO_Port, DO_Row4_Pin, 0);
	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 1);
	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 1);
	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 1);
	if (HAL_GPIO_ReadPin(DI_Col1_GPIO_Port, DI_Col1_Pin) == 0 )B_B=13;
	else if(HAL_GPIO_ReadPin(DI_Col2_GPIO_Port, DI_Col2_Pin) == 0)B_B=14;
	else if(HAL_GPIO_ReadPin(DI_Col3_GPIO_Port, DI_Col3_Pin) == 0)B_B=15;
	else if(HAL_GPIO_ReadPin(DI_Col4_GPIO_Port, DI_Col4_Pin) == 0)B_B=16;
	HAL_GPIO_WritePin(DO_Row4_GPIO_Port, DO_Row4_Pin, 1);
//  }
//Exit_Scan:
	if (B_B != B_B_old)
	{
switch (B_B) {
	case 1:
				B_B_old =1;
		lcd_put_cur(1, 3);
		lcd_send_string("01");
		for (uint8_t i =0; i<4;i++)
		HAL_Delay(255);

		break;
	case 2:
		{		B_B_old =2;
			lcd_put_cur(1, 3);
			lcd_send_string("02");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 3:
		{		B_B_old =3;
			lcd_put_cur(1, 3);
			lcd_send_string("03");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 4:
		{		B_B_old =4;
			lcd_put_cur(1, 3);
			lcd_send_string("04");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 5:
		{		B_B_old =5;
			lcd_put_cur(1, 3);
			lcd_send_string("05");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 6:
		{		B_B_old =6;
			lcd_put_cur(1, 3);
			lcd_send_string("06");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 7:
		{		B_B_old =7;
			lcd_put_cur(1, 3);
			lcd_send_string("07");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 8:
		{		B_B_old =8;
			lcd_put_cur(1, 3);
			lcd_send_string("08");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 9:
		{		B_B_old =9;
			lcd_put_cur(1, 3);
			lcd_send_string("09");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 10:
		{		B_B_old =10;
			lcd_put_cur(1, 3);
			lcd_send_string("10");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 11:
		{		B_B_old =11;
			lcd_put_cur(1, 3);
			lcd_send_string("11");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 12:
		{		B_B_old =12;
			lcd_put_cur(1, 3);
			lcd_send_string("12");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 13:
		{		B_B_old =13;
			lcd_put_cur(1, 3);
			lcd_send_string("13");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 14:
		{		B_B_old =14;
			lcd_put_cur(1, 3);
			lcd_send_string("14");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 15:
		{		B_B_old =15;
			lcd_put_cur(1, 3);
			lcd_send_string("15");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
		break;
	case 16:
		{		B_B_old =16;
			lcd_put_cur(1, 3);
			lcd_send_string("16");
			for (uint8_t i =0; i<4;i++)
			HAL_Delay(255);
		}
        break;
	default:
		    B_B_old =0;
			lcd_put_cur(1, 3);
			lcd_send_string("--");
	    break;
}
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
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 71;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, DO_Row1_Pin|DO_Row2_Pin|DO_Row3_Pin|DO_Row4_Pin
                          |DO_EN_Pin|DO_RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, DO_D7_Pin|DO_D6_Pin|DO_D5_Pin|DO_D4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : DO_Row1_Pin DO_Row2_Pin DO_Row3_Pin DO_Row4_Pin
                           DO_EN_Pin DO_RS_Pin */
  GPIO_InitStruct.Pin = DO_Row1_Pin|DO_Row2_Pin|DO_Row3_Pin|DO_Row4_Pin
                          |DO_EN_Pin|DO_RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : DI_Col4_Pin DI_Col3_Pin DI_Col1_Pin DI_Col2_Pin */
  GPIO_InitStruct.Pin = DI_Col4_Pin|DI_Col3_Pin|DI_Col1_Pin|DI_Col2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : DO_D7_Pin DO_D6_Pin DO_D5_Pin DO_D4_Pin */
  GPIO_InitStruct.Pin = DO_D7_Pin|DO_D6_Pin|DO_D5_Pin|DO_D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

