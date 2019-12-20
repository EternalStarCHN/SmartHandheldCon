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
#include "usart.h"
#include "stdio.h"

uint8_t START_Refresh = 0;

extern uint8_t Menu_Flag;
extern uint8_t LED_Waterfall_Con;

/***************TEST**************/
extern int adc1_Value;
extern int adc2_Value;
extern int adc3_Value;
extern double luminance;
extern double temperture;
extern double airquality;
/********************************/

void User_main(void)
{
	Menu_Flag = 1;
	LED_Waterfall_Con = 1;
	while(1)
	{
		Logic();
		if(!START_Refresh){
			Buzzer_Yell_Times(3,50,50);
			LED_TwinkleTEMP(2,30);
			START_Refresh++;
		}
					printf("1\r\n");
	}
}

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif 


/* printf??????1 */
int fputc(int ch,FILE *f)
{
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart1,temp,1,10);        //UartHandle??????
  return ch;
}


PUTCHAR_PROTOTYPE
{
 HAL_UART_Transmit(&huart1,(uint8_t*)&ch,1,10);
 return ch;
}


