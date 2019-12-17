#include "User_Logic.h"

uint8_t Menu_Refresh = 0;
uint8_t Game1_Flag = 0;
uint8_t Game1_Refresh = 0;
uint8_t Environment_Flag = 0;
uint8_t Environment_Refresh_Flag = 0;
uint8_t PWMControl_Flag = 0;
uint8_t PWMControl_Refresh_Flag = 0;
uint8_t LEDPWM_Flag = 0;
uint8_t FullColorPWM_Flag = 0;


extern uint8_t Menu_Flag;
extern uint8_t Menu_Index;
extern uint8_t Func_Flag;
extern double luminance;
extern double temperture;
extern uint8_t PWMControl_Index;
extern uint8_t CRR;
extern uint8_t CRR_Red;
extern uint8_t CRR_Green;
extern uint8_t CRR_Blue;

char LUMI[256]={0};
char TEMP[256]={0};
char AIRQ[256]={0};
char Crr[256]={0};
char Crr_Red[256]={0};
char Crr_Green[256]={0};
char Crr_Blue[256]={0};



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
				Lcd_Clear(EnvironmentInformation_BG);
				LCD_DrawSqureBorder(0,0,320,240,BLUE);
				Gui_DrawFont_GBK16(20,20,RED,EnvironmentInformation_BG,"Environment Information:");
				Environment_Refresh_Flag++;
			}
			Environmen_Information();
			HAL_Delay(500);
			break;
		case 3:
			PWMControl_Flag = 1;
			if(!PWMControl_Refresh_Flag){
				Lcd_Clear(PWMControl_BG);
				LCD_DrawSqureBorder(0,0,320,240,WHITE);
				Gui_DrawFont_GBK16(40,60,RGB(255,245,238),PWMControl_BG,"LEDPWM");
				Gui_DrawFont_GBK16(120,60,RGB(255,245,238),PWMControl_BG,"Red");
				Gui_DrawFont_GBK16(180,60,RGB(255,245,238),PWMControl_BG,"Green");
				Gui_DrawFont_GBK16(240,60,RGB(255,245,238),PWMControl_BG,"Blue");				
			}
			PWM_Control();
			break;
		
		default: ;break;
	}
}

void Environmen_Information(void){
	MyADC_ValueGet();
	
	Gui_DrawFont_GBK16(50,60,EnvironmentInformation_BG,EnvironmentInformation_BG,LUMI);
	Gui_DrawFont_GBK16(50,120,EnvironmentInformation_BG,EnvironmentInformation_BG,TEMP);
	Gui_DrawFont_GBK16(50,180,EnvironmentInformation_BG,EnvironmentInformation_BG,AIRQ);
	
	DoubleToString(luminance,LUMI);
	DoubleToString(temperture,TEMP);	
	DoubleToString(temperture,AIRQ);
	
	Gui_DrawFont_GBK16(50,60,RED,EnvironmentInformation_BG,LUMI);
	Gui_DrawFont_GBK16(50,120,RED,EnvironmentInformation_BG,TEMP);
	Gui_DrawFont_GBK16(50,180,RED,EnvironmentInformation_BG,AIRQ);
	
	if(temperture>2){
		Led_OpenALL();
	}
	else{
		Led_CloseALL();
	}
}

void PWM_Control(void){
	switch(PWMControl_Index){
		case 1:
			LCD_DrawSqure(60,30,8,8,RGB(255,255,0));
			LCD_DrawSqure(140,30,8,8,PWMControl_BG);
			LCD_DrawSqure(200,30,8,8,PWMControl_BG);
			LCD_DrawSqure(260,30,8,8,PWMControl_BG);
			break;
		case 2:
			LCD_DrawSqure(60,30,8,8,PWMControl_BG);
			LCD_DrawSqure(140,30,8,8,RGB(255,255,0));
			LCD_DrawSqure(200,30,8,8,PWMControl_BG);
			LCD_DrawSqure(260,30,8,8,PWMControl_BG);			
			break;
		case 3:
			LCD_DrawSqure(60,30,8,8,PWMControl_BG);
			LCD_DrawSqure(140,30,8,8,PWMControl_BG);
			LCD_DrawSqure(200,30,8,8,RGB(255,255,0));
			LCD_DrawSqure(260,30,8,8,PWMControl_BG);			
			break;
		case 4:
			LCD_DrawSqure(60,30,8,8,PWMControl_BG);
			LCD_DrawSqure(140,30,8,8,PWMControl_BG);
			LCD_DrawSqure(200,30,8,8,PWMControl_BG);
			LCD_DrawSqure(260,30,8,8,RGB(255,255,0));			
			break;
		default: ;break;
	}
	Gui_DrawFont_GBK16(60,120,PWMControl_BG,PWMControl_BG,Crr);
	Gui_DrawFont_GBK16(140,120,PWMControl_BG,PWMControl_BG,Crr_Red);
	Gui_DrawFont_GBK16(200,120,PWMControl_BG,PWMControl_BG,Crr_Green);
	Gui_DrawFont_GBK16(260,120,PWMControl_BG,PWMControl_BG,Crr_Blue);	
	
	IntToString(CRR,Crr);
	IntToString(CRR_Red,Crr_Red);
	IntToString(CRR_Green,Crr_Green);
	IntToString(CRR_Blue,Crr_Blue);
	
	Gui_DrawFont_GBK16(60,120,RGB(255,245,238),PWMControl_BG,Crr);
	Gui_DrawFont_GBK16(140,120,RGB(255,245,238),PWMControl_BG,Crr_Red);
	Gui_DrawFont_GBK16(200,120,RGB(255,245,238),PWMControl_BG,Crr_Green);
	Gui_DrawFont_GBK16(260,120,RGB(255,245,238),PWMControl_BG,Crr_Blue);

	Led_PWMControl(CRR);
	FullColor_PWMControl(CRR_Red,CRR_Green,CRR_Blue);
}