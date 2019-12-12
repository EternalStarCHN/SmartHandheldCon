#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "gui.h"
#include "User_Logic.h"
#include "snake.h"
#include "rng.h"
#include "User_Pic.h"
#include "User_Led.h"
#include "adc.h"

extern uint8_t Menu_Flag;
extern uint8_t LED_Waterfall_Con;
//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	Lcd_Clear(WHITE);
	Menu_Flag = 1;
	LED_Waterfall_Con = 1;
	while(1)
	{
		HAL_ADC_Start(&hadc1);
		//HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
		//__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,500);
		//LCD_Image2LcdDrawBmp565Pic(0, 0,gImage_111);
		Logic();
	}
}



