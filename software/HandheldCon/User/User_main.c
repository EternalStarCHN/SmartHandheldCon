#include "main.h"
#include "spi.h"
#include "gpio.h"
#include "gui.h"
//TIM3 触发输出事件连接到ADC1 PA1端口控制采样速率 ADC1 PA1使用DMA2S0


//此处为真正的mian函数 自动生成部分请不要动
void User_main(void)
{
	Lcd_Clear(WHITE);
	while(1)
	{
		LCD_DrawSqure(100,100,100,100,BLUE);
		//Gui_DrawFont_GBK24(100,5,RED,WHITE,"<HandheldCon>");
	}
}



