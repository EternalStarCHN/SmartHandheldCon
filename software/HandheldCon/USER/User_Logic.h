#ifndef USER_LOGIC_H_
#define USER_LOGIC_H_

#include "gpio.h"
#include "gui.h"
#include "spi.h"
#include "User_adc.h"
#include "User_Led.h"

#define IntToString(VAL,ARR) sprintf(ARR,"%d",VAL) //itos转换
#define DoubleToString(VAL,ARR) sprintf(ARR,"%lf",VAL) //itos转换

#define EnvironmentInformation_BG RGB(193,255,193)
#define PWMControl_BG RGB(186,85,211)

void Logic(void);
void delay_ms(uint16_t time);
void Menu(void);
void Menu_Show(uint8_t Menu_Index);
void Func_Start(uint8_t Menu_Index);
void Environmen_Information(void);
void PWM_Control(void);

#endif
