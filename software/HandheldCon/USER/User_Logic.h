#ifndef USER_LOGIC_H_
#define USER_LOGIC_H_

#include "gpio.h"
#include "gui.h"
#include "spi.h"

#define IntToString(a,NUM) sprintf(NUM,"%d",a) //itos转换

void Logic(void);
void delay_ms(uint16_t time);
void Menu(void);
void Menu_Show(uint8_t Menu_Index);
void Game_Start(uint8_t Menu_Index);
void Display_dead(void);
void Display_Pass(void);

#endif
