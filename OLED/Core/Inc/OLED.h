

#ifndef INC_OLED_H_
#define INC_OLED_H_

#include "stdint.h"

typedef struct {
	uint8_t FontWidth;    /*!< Font width in pixels */
	uint8_t FontHeight;   /*!< Font height in pixels */
	const uint16_t *data; /*!< Pointer to data font data array */
} FontDef_t;


void TestLines(uint8_t color);
void TestRectangles (uint8_t color);
void TestFilledRectangles (uint8_t color);
void TestFilledCircles(uint8_t radius, uint16_t color);
void TestCircles(uint8_t radius, uint16_t color);
void TestTriangles(uint8_t color);
char * get_logo();

FontDef_t * get_Font_7x10();
FontDef_t* get_Font_11x18();
FontDef_t * get_Font_16x26();
char * get_hourse1();
char * get_hourse2();
char * get_hourse3();
char * get_hourse4();
char * get_hourse5();
char * get_hourse6();
char * get_hourse7();
char * get_hourse8();
char * get_hourse9();
char * get_hourse10();

	/* Private SSD1306 structure */
	 typedef struct {
		uint16_t CurrentX;
		uint16_t CurrentY;
		uint8_t Inverted;
		uint8_t Initialized;
	} SSD1306_t;

	/**
	 * @brief  String length and height
	 */
	 typedef struct {
		uint16_t Length;      /*!< String length in units of pixels */
		uint16_t Height;      /*!< String height in units of pixels */
	} FONTS_SIZE_t;

	typedef enum {
		SSD1306_COLOR_BLACK = 0x00, /*!< Black color, no pixel */
		SSD1306_COLOR_WHITE = 0x01  /*!< Pixel is set. Color depends on LCD */
	} SSD1306_COLOR_t;

	uint8_t SSD1306_Init(void);
	void SSD1306_UpdateScreen(void);
	void UpdateOLED(void);
	void SSD1306_ToggleInvert(void);
	/**
	 * @brief  Fills entire LCD with desired color
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  Color: Color to be used for screen fill. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_Fill(SSD1306_COLOR_t Color);

	/**
	 * @brief  Draws pixel at desired location
	 * @note   @ref SSD1306_UpdateScreen() must called after that in order to see updated LCD screen
	 * @param  x: X location. This parameter can be a value between 0 and SSD1306_WIDTH - 1
	 * @param  y: Y location. This parameter can be a value between 0 and SSD1306_HEIGHT - 1
	 * @param  color: Color to be used for screen fill. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawPixel(uint16_t x, uint16_t y, SSD1306_COLOR_t color);

	/**
	 * @brief  Sets cursor pointer to desired location for strings
	 * @param  x: X location. This parameter can be a value between 0 and SSD1306_WIDTH - 1
	 * @param  y: Y location. This parameter can be a value between 0 and SSD1306_HEIGHT - 1
	 * @retval None
	 */
	void SSD1306_GotoXY(uint16_t x, uint16_t y);

	/**
	 * @brief  Puts character to internal RAM
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  ch: Character to be written
	 * @param  *Font: Pointer to @ref FontDef_t structure with used font
	 * @param  color: Color used for drawing. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval Character written
	 */
	char SSD1306_Putc(char ch, FontDef_t* Font, SSD1306_COLOR_t color);

	/**
	 * @brief  Puts string to internal RAM
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  *str: String to be written
	 * @param  *Font: Pointer to @ref FontDef_t structure with used font
	 * @param  color: Color used for drawing. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval Zero on success or character value when function failed
	 */
	char SSD1306_Puts(char* str, FontDef_t* Font, SSD1306_COLOR_t color);

	/**
	 * @brief  Draws line on LCD
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  x0: Line X start point. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y0: Line Y start point. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  x1: Line X end point. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y1: Line Y end point. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, SSD1306_COLOR_t c);

	/**
	 * @brief  Draws rectangle on LCD
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  x: Top left X start point. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y: Top left Y start point. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  w: Rectangle width in units of pixels
	 * @param  h: Rectangle height in units of pixels
	 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR_t c);

	/**
	 * @brief  Draws filled rectangle on LCD
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  x: Top left X start point. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y: Top left Y start point. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  w: Rectangle width in units of pixels
	 * @param  h: Rectangle height in units of pixels
	 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawFilledRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR_t c);

	/**
	 * @brief  Draws triangle on LCD
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  x1: First coordinate X location. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y1: First coordinate Y location. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  x2: Second coordinate X location. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y2: Second coordinate Y location. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  x3: Third coordinate X location. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y3: Third coordinate Y location. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, SSD1306_COLOR_t color);

	/**
	 * @brief  Draws circle to STM buffer
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  x: X location for center of circle. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y: Y location for center of circle. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  r: Circle radius in units of pixels
	 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawCircle(int16_t x0, int16_t y0, int16_t r, SSD1306_COLOR_t c);

	/**
	 * @brief  Draws filled circle to STM buffer
	 * @note   @ref SSD1306_UpdateScreen() must be called after that in order to see updated LCD screen
	 * @param  x: X location for center of circle. Valid input is 0 to SSD1306_WIDTH - 1
	 * @param  y: Y location for center of circle. Valid input is 0 to SSD1306_HEIGHT - 1
	 * @param  r: Circle radius in units of pixels
	 * @param  c: Color to be used. This parameter can be a value of @ref SSD1306_COLOR_t enumeration
	 * @retval None
	 */
	void SSD1306_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, SSD1306_COLOR_t c);





	/**
	 * @brief  Initializes SSD1306 LCD
	 * @param  None
	 * @retval Initialization status:
	 *           - 0: LCD was not detected on I2C port
	 *           - > 0: LCD initialized OK and ready to use
	 */
	void ssd1306_I2C_Init();

	/**
	 * @brief  Writes single byte to slave
	 * @param  *I2Cx: I2C used
	 * @param  address: 7 bit slave address, left aligned, bits 7:1 are used, LSB bit is not used
	 * @param  reg: register to write to
	 * @param  data: data to be written
	 * @retval None
	 */
	void ssd1306_I2C_Write(uint8_t address, uint8_t reg, uint8_t data);

	/**
	 * @brief  Writes multi bytes to slave
	 * @param  *I2Cx: I2C used
	 * @param  address: 7 bit slave address, left aligned, bits 7:1 are used, LSB bit is not used
	 * @param  reg: register to write to
	 * @param  *data: pointer to data array to write it to slave
	 * @param  count: how many bytes will be written
	 * @retval None
	 */
	void ssd1306_I2C_WriteMulti(uint8_t address, uint8_t reg, uint8_t *data, uint16_t count);

	/**
	 * @brief  Draws the Bitmap
	 * @param  X:  X location to start the Drawing
	 * @param  Y:  Y location to start the Drawing
	 * @param  *bitmap : Pointer to the bitmap
	 * @param  W : width of the image
	 * @param  H : Height of the image
	 * @param  color : 1-> white/blue, 0-> black
	 */
	void SSD1306_DrawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, int16_t w, int16_t h, uint16_t color);
	void SSD1306_ScrollRight(uint8_t start_row, uint8_t end_row);// scroll the screen for fixed rows
	void SSD1306_ScrollLeft(uint8_t start_row, uint8_t end_row);
	void SSD1306_Scrolldiagright(uint8_t start_row, uint8_t end_row);
	void SSD1306_Scrolldiagleft(uint8_t start_row, uint8_t end_row);
	void SSD1306_Stopscroll(void);
	void SSD1306_InvertDisplay (int i);	// inverts the display i = 1->inverted, i = 0->normal
	void SSD1306_Clear (void);// clear the display


	void MX_I2C1_Init(void);





























/**
 * @brief  Calculates string length and height in units of pixels depending on string and font used
 * @param  *str: String to be checked for length and height
 * @param  *SizeStruct: Pointer to empty @ref FONTS_SIZE_t structure where informations will be saved
 * @param  *Font: Pointer to @ref FontDef_t font used for calculations
 * @retval Pointer to string used for length and height
 */
char* FONTS_GetStringSize(char* str, FONTS_SIZE_t* SizeStruct, FontDef_t* Font);






#endif /* INC_OLED_H_ */
