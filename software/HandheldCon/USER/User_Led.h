#ifndef __USERLED_H
#define __USERLED_H

#include "gpio.h"
#include "tim.h"

void Led_OpenALL(void);
void Led_CloseALL(void);
void Led_OpenHUMI(void);
void Led_OpenTEMP(void);
void LED_TwinkleHUMI(uint8_t times,uint8_t delay_ms);
void LED_TwinkleTEMP(uint8_t times,uint8_t delay_ms);

void Led_WaterfallLight_Delay(uint8_t delay_ms);
void Led_WaterfallLight_Times(uint8_t Times,uint8_t On_delay_ms,uint8_t Off_delay_times);
void Led_PWMControl(uint8_t CRR);
void FullColor_PWMControl(uint8_t CRR_Red,uint8_t CRR_Green,uint8_t CRR_Blue);

#endif