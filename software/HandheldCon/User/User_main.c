#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "gui.h"
#include "User_Logic.h"
#include "snake.h"
#include "rng.h"
#include "User_Pic.h"

extern uint8_t Menu_Flag;

//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	Lcd_Clear(WHITE);
	Menu_Flag = 1;
	char num[256]={0};
	while(1)
	{
//		HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_RESET);
		//LCD_Image2LcdDrawBmp565Pic(0, 0,gImage_111);
		//Logic();
	}
}



