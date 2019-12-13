#ifndef __USERLED_H
#define __USERLED_H

#include "gpio.h"
#include "tim.h"

void Led_OpenALL(void);
void Led_CloseALL(void);
void Led_WaterfallLight_Delay(uint8_t Delays);
void Led_WaterfallLight_Times(uint8_t Times,uint8_t Delays);
void Led_PWMControl(void);

#endif