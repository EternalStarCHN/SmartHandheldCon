#ifndef USER_LOGIC_H_
#define USER_LOGIC_H_

#include "gpio.h"
#include "gui.h"
#include "spi.h"
#include "User_adc.h"
#include "User_Led.h"

#define IntToString(VAL,ARR) sprintf(ARR,"%d",VAL) //itos转换
#define DoubleToString(VAL,ARR) sprintf(ARR,"%lf",VAL) //itos转换

#define Menu_BG RGB(0,191,255)
#define Menu_Font_Color RGB(255,255,240)
#define Menu_Num_Color RGB(255,215,0)

#define EnvironmentInformation_Font_BG RGB(34,139,34)
#define EnvironmentInformation_BG RGB(152,251,152)

#define PWMControl_BG RGB(186,85,211)

void Logic(void);
void delay_ms(uint16_t time);
void Menu(void);
void Menu_Show(uint8_t Menu_Index);
void Func_Start(uint8_t Menu_Index);
void Environmen_Information(void);
void PWM_Control(void);

#endif
