#include "User_Logic.h"

uint8_t Menu_Refresh = 0;
extern uint8_t Menu_Flag;
extern uint8_t Menu_Index;

void Logic(void){
	if(Menu_Flag == 1){
		Menu_Show(Menu_Index);
	}
}

void delay_ms(uint16_t time)
{    
   uint16_t i=0;  
   while(time--)
   {
      i = 12000;  
      while(i--) ;    
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
			Gui_DrawFont_GBK24(20,50,RGB(178,34,34),RGB(255,255,255),"Game1:Gluttonous Snake <-");
			Gui_DrawFont_GBK24(20,90,RGB(178,34,34),RGB(255,255,255),"Game2:Tetris");
			Gui_DrawFont_GBK24(20,130,RGB(178,34,34),RGB(255,255,255),"Game3:");
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
			Gui_DrawFont_GBK24(20,50,RGB(178,34,34),RGB(255,255,255),"Game1:Gluttonous Snake");
			Gui_DrawFont_GBK24(20,90,RGB(178,34,34),RGB(255,255,255),"Game2:Tetris           <-");
			Gui_DrawFont_GBK24(20,130,RGB(178,34,34),RGB(255,255,255),"Game3:");
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
			Gui_DrawFont_GBK24(20,50,RGB(178,34,34),RGB(255,255,255),"Game1:Gluttonous Snake");
			Gui_DrawFont_GBK24(20,90,RGB(178,34,34),RGB(255,255,255),"Game2:Tetris");
			Gui_DrawFont_GBK24(20,130,RGB(178,34,34),RGB(255,255,255),"Game3:                <-");
			Gui_DrawFont_GBK16(225,220,RGB(178,34,34),RGB(255,255,255),"Choose:");
			Gui_DrawFont_Num32(280, 200, RED, WHITE, 3);
			break;
		default:;break;
	}
}