#ifndef __SNAKE_H__
#define __SNAKE_H__
#include"User_Logic.h"
#include "gpio.h"
#include "gui.h"
#include "spi.h"
#include "time.h"
#include "rng.h"

#define SNAKE_Area 5
#define SNAKE_Max_Long 64 
typedef struct 
{
uint8_t X;
uint8_t Y;
uint8_t Yes;
}Food; 

typedef struct 
{
uint8_t X[SNAKE_Max_Long];
uint8_t Y[SNAKE_Max_Long];
uint8_t Long;
uint8_t Life;
uint8_t Score;
uint8_t Level; 
}Snake; 




void Init_SNAKE(void);
void Run_SNAKE(void);
void Display_Pass(void);
void Display_Dead(void);
void Trun_On_Point (uint8_t x,uint8_t y);
void Trun_Off_Point (uint8_t x,uint8_t y);


//extern void Trun_On_Point (uchar x,uchar y,uchar color);
#endif