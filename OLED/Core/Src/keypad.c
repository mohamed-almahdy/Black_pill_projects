#include "main.h"
#include "stdint.h"
	uint8_t B_B=0;
	uint16_t kp_col[4]=
	{DI_Col1_Pin,DI_Col2_Pin,DI_Col3_Pin,DI_Col4_Pin};

	void TurnOn_TBUZL(void);

	void TurnOn_TBUZS(void);

uint8_t ReadSwitches ()
{

#if 0
	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 0);
	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 1);
	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 1);
	HAL_GPIO_WritePin(DO_Row4_GPIO_Port, DO_Row4_Pin, 1);
	if (HAL_GPIO_ReadPin(DI_Col1_GPIO_Port, DI_Col1_Pin) == 0 )B_B=1;
	else if(HAL_GPIO_ReadPin(DI_Col2_GPIO_Port, DI_Col2_Pin) == 0)B_B=2;
	else if(HAL_GPIO_ReadPin(DI_Col3_GPIO_Port, DI_Col3_Pin) == 0)B_B=3;
	else if(HAL_GPIO_ReadPin(DI_Col4_GPIO_Port, DI_Col4_Pin) == 0)B_B=4;
//	HAL_GPIO_WritePin(DO_Row1_GPIO_Port, DO_Row1_Pin, 1);
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
//	HAL_GPIO_WritePin(DO_Row2_GPIO_Port, DO_Row2_Pin, 1);
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
//	HAL_GPIO_WritePin(DO_Row3_GPIO_Port, DO_Row3_Pin, 1);
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

	return B_B;
#endif /* 0*/

    for (int row = 0; row < 4; row++) {
        // Set the current row low
        HAL_GPIO_WritePin(GPIOA, (1 << (row+4)), GPIO_PIN_RESET);

        for (int col = 0; col < 4; col++) {
            // Check if the key is pressed
            if (HAL_GPIO_ReadPin(GPIOB, kp_col[col]) == GPIO_PIN_RESET) {
            	TurnOn_TBUZS();
                // Wait for key release
                while (HAL_GPIO_ReadPin(GPIOB, kp_col[col]) == GPIO_PIN_RESET);
                // Set the row back high
                HAL_GPIO_WritePin(GPIOA, (1 << (row+4)), GPIO_PIN_SET);
                uint8_t res=(row*4)+col+1;
                TurnOn_TBUZL();
                return res; // Return the pressed key
            }
        }

        // Set the current row back to high
        HAL_GPIO_WritePin(GPIOA, (1 << (row+4)), GPIO_PIN_SET);
    }
    return 0; // No key pressed

}


void TurnOn_TBUZL(void) {
    // Add implementation to turn on low buzzer
	  HAL_GPIO_WritePin(GPIOB, DO_Buzzer_Pin, GPIO_PIN_RESET);
}

void TurnOn_TBUZS(void) {
    // Add implementation to turn on high buzzer
	  HAL_GPIO_WritePin(GPIOB, DO_Buzzer_Pin, GPIO_PIN_SET);
}
