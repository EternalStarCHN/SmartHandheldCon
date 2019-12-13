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
#include "User_adc.h"

extern uint8_t Menu_Flag;
extern uint8_t LED_Waterfall_Con;
extern int adc1_Value;
extern int adc2_Value;
extern double luminance;
extern double temperture;
//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	Lcd_Clear(WHITE);
	Menu_Flag = 1;
	LED_Waterfall_Con = 1;
	while(1)
	{
		//HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
		//__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,500);
		Logic();
	}
}



