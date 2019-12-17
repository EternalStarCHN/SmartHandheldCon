#ifndef __USERBUZZER_H
#define __USERBUZZER_H

#include "gpio.h"

void Buzzer_Yell(void);
void Buzzer_Stop(void);
void Buzzer_Yell_Times(uint8_t Times,uint8_t On_delay_ms,uint8_t Off_delay_ms);
	
#endif