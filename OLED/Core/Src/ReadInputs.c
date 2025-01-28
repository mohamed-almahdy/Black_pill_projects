#include "main.h"
#include "OLED.h"

uint8_t ReadSwitches ();

void SW_1_Func(){
	  SSD1306_Fill(0);
SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 1 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
}
		void SW_2_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 2 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_3_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 3 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_4_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 4 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_5_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 5 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_6_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 6 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_7_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 7 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_8_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 8 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void SW_9_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch 9 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void  SW_10_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch10 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void  SW_11_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch11 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void  SW_12_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch12 is", get_Font_11x18(), 1);
  SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
//  SSD1306_GotoXY(0,38);SSD1306_Puts ("STM32F401  ", get_Font_11x18(), 1);
		}
		void  SW_13_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch13 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void  SW_14_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch14 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void  SW_15_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch15 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}
		void  SW_16_Func(){
			  SSD1306_Fill(0);
		  SSD1306_GotoXY(0,0); SSD1306_Puts ("Switch16 is", get_Font_11x18(), 1);
SSD1306_GotoXY(0,19);SSD1306_Puts ("Pressed", get_Font_11x18(), 1);
		}

void ReadInputs()
{
	uint8_t B_Byte = ReadSwitches();
	switch (B_Byte)
	{
		case 0:break;
		case 1: SW_1_Func(); break;
		case 2: SW_2_Func(); break;
		case 3: SW_3_Func(); break;
		case 4: SW_4_Func(); break;
		case 5: SW_5_Func(); break;
		case 6: SW_6_Func(); break;
		case 7: SW_7_Func(); break;
		case 8: SW_8_Func(); break;
		case 9: SW_9_Func(); break;
		case 10: SW_10_Func(); break;
		case 11: SW_11_Func(); break;
		case 12: SW_12_Func(); break;
		case 13: SW_13_Func(); break;
		case 14: SW_14_Func(); break;
		case 15: SW_15_Func(); break;
		case 16: SW_16_Func(); break;
	}

}

