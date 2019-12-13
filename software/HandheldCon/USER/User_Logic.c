#include "User_Logic.h"

uint8_t Menu_Refresh = 0;
uint8_t Game1_Flag = 0;
uint8_t Game1_Refresh = 0;
uint8_t Environment_Flag = 0;
uint8_t Environment_Refresh_Flag = 0;
uint8_t LEDControl_Flag = 0;
uint8_t LEDControl_Refresh_Flag = 0;


extern uint8_t Menu_Flag;
extern uint8_t Menu_Index;
extern uint8_t Func_Flag;
extern double luminance;
extern double temperture;
char LUMI[256]={0};
char TEMP[256]={0};


void Logic(void){
	if(Menu_Flag == 1 && Func_Flag == 0){
		Menu_Show(Menu_Index);
	}
	if(Menu_Flag == 0 && Func_Flag == 1){
		Func_Start(Menu_Index);
	}
}

void delay_ms(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i = 12000;  
      while(i--);    
   }
}

void Menu_Show(uint8_t Menu_Index){
	switch(Menu_Index){
		case 1:
			if(Menu_Refresh == 0 ){
				Lcd_Clear(WHITE);
				Menu_Refresh++;
			}
			Gui_DrawFont_GBK24(110,5,RGB(178,34,34),RGB(255,255,255),"-HandHeldCon-");
			Gui_DrawLine(20, 30, 300, 30, RGB(255,215,0));		
			Gui_DrawFont_GBK24(20,50,RGB(178,34,34),RGB(255,255,255),"Game:Gluttonous Snake  <-");
			Gui_DrawFont_GBK24(20,90,RGB(178,34,34),RGB(255,255,255),"Environment Information");
			Gui_DrawFont_GBK24(20,130,RGB(178,34,34),RGB(255,255,255),"LED Control");
			Gui_DrawFont_GBK16(225,220,RGB(178,34,34),RGB(255,255,255),"Choose:");
			Gui_DrawFont_Num32(280, 200, RED, WHITE, 1);
			break;
		case 2:
			if(Menu_Refresh == 0 ){
				Lcd_Clear(WHITE);
				Menu_Refresh++;
			}
			Gui_DrawFont_GBK24(110,5,RGB(178,34,34),RGB(255,255,255),"-HandHeldCon-");
			Gui_DrawLine(20, 30, 300, 30, RGB(255,215,0));				
			Gui_DrawFont_GBK24(20,50,RGB(178,34,34),RGB(255,255,255),"Game:Gluttonous Snake");
			Gui_DrawFont_GBK24(20,90,RGB(178,34,34),RGB(255,255,255),"Environment Information <-");
			Gui_DrawFont_GBK24(20,130,RGB(178,34,34),RGB(255,255,255),"LED Control");
			Gui_DrawFont_GBK16(225,220,RGB(178,34,34),RGB(255,255,255),"Choose:");
			Gui_DrawFont_Num32(280, 200, RED, WHITE, 2);			
			break;
		case 3:
			if(Menu_Refresh == 0 ){
				Lcd_Clear(WHITE);
				Menu_Refresh++;
			}
			Gui_DrawFont_GBK24(110,5,RGB(178,34,34),RGB(255,255,255),"-HandHeldCon-");
			Gui_DrawLine(20, 30, 300, 30, RGB(255,215,0));	
			Gui_DrawFont_GBK24(20,50,RGB(178,34,34),RGB(255,255,255),"Game:Gluttonous Snake");
			Gui_DrawFont_GBK24(20,90,RGB(178,34,34),RGB(255,255,255),"Environment Information");
			Gui_DrawFont_GBK24(20,130,RGB(178,34,34),RGB(255,255,255),"LED Control             <-");
			Gui_DrawFont_GBK16(225,220,RGB(178,34,34),RGB(255,255,255),"Choose:");
			Gui_DrawFont_Num32(280, 200, RED, WHITE, 3);
			break;
		default:;break;
	}
}

void Func_Start(uint8_t Menu_Index){
	switch(Menu_Index){
		case 1: 
			Game1_Flag = 1;
			if(!Game1_Refresh){
				Init_SNAKE();
				Game1_Refresh++;
			}
			Run_SNAKE();
			break;
		case 2:
			Environment_Flag = 1;
			if(!Environment_Refresh_Flag){
				Lcd_Clear(RGB(193,255,193));
				LCD_DrawSqureBorder(0,0,320,240,BLUE);
				Gui_DrawFont_GBK16(20,20,RED,RGB(193,255,193),"Environment Information:");
				Environment_Refresh_Flag++;
			}
			Environmen_Information();
			HAL_Delay(500);
			break;
		case 3:
				
			break;
		
		default: ;break;
	}
}

void Environmen_Information(void){
	MyADC_ValueGet();
	Gui_DrawFont_GBK16(50,60,RGB(193,255,193),RGB(193,255,193),LUMI);
	Gui_DrawFont_GBK16(50,120,RGB(193,255,193),RGB(193,255,193),TEMP);
	DoubleToString(luminance,LUMI);
	DoubleToString(temperture,TEMP);	
	Gui_DrawFont_GBK16(50,60,RED,RGB(193,255,193),LUMI);
	Gui_DrawFont_GBK16(50,120,RED,RGB(193,255,193),TEMP);	
	if(temperture>2){
		Led_OpenALL();
	}
	else{
		Led_CloseALL();
	}
}