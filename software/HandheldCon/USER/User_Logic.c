#include "User_Logic.h"

uint8_t Menu_Refresh = 0;
uint8_t Menu_Index_Refresh = 0;
uint8_t Game1_Flag = 0;
uint8_t Game1_Refresh = 0;
uint8_t Environment_Flag = 0;
uint8_t Environment_Refresh_Flag = 0;
uint8_t PWMControl_Flag = 0;
uint8_t PWMControl_Refresh_Flag = 0;
uint8_t LEDPWM_Flag = 0;
uint8_t FullColorPWM_Flag = 0;
uint8_t PWM_CRR_Refresh = 0;
uint8_t PWM_CRRRED_Refresh = 0;
uint8_t PWM_CRRGREEN_Refresh = 0;
uint8_t PWM_CRRBLUE_Refresh = 0;
uint8_t CRR_Pre = 0;
uint8_t CRRRED_Pre = 0;
uint8_t CRRGREEN_Pre = 0;
uint8_t CRRBLUE_Pre = 0;

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
	if(Menu_Refresh == 0 ){
		Lcd_Clear(Menu_BG);
		Gui_DrawFont_GBK24(110,8,Menu_Font_Color,Menu_BG,"-HandHeLdCon-");
		Gui_DrawLine(20, 30, 300, 30, RGB(255,215,0));	
		Menu_Refresh++;
	}
	switch(Menu_Index){
		case 1:
			if(Menu_Index_Refresh == 0 ){
				Gui_DrawFont_GBK24(20,50,Menu_BG,Menu_BG,">Gluttonous Snake        <-");
				Gui_DrawFont_GBK24(20,90,Menu_BG,Menu_BG,">Environment Information <-");
				Gui_DrawFont_GBK24(20,130,Menu_BG,Menu_BG,">LED CONTROL             <-");
				Menu_Index_Refresh++;
			}

			Gui_DrawFont_GBK24(20,50,Menu_Font_Color,Menu_BG,">Gluttonous Snake        <-");
			Gui_DrawFont_GBK24(20,90,Menu_Font_Color,Menu_BG,">Environment Information");
			Gui_DrawFont_GBK24(20,130,Menu_Font_Color,Menu_BG,">LED CONTROL");
			Gui_DrawFont_GBK16(225,220,Menu_Font_Color,Menu_BG,"Choose:");
			Gui_DrawFont_Num32(280, 200,Menu_Num_Color,Menu_BG, 1);
			break;
		case 2:
			if(Menu_Index_Refresh == 0 ){
				Gui_DrawFont_GBK24(20,50,Menu_BG,Menu_BG,">Gluttonous Snake        <-");
				Gui_DrawFont_GBK24(20,90,Menu_BG,Menu_BG,">Environment Information <-");
				Gui_DrawFont_GBK24(20,130,Menu_BG,Menu_BG,">LED CONTROL             <-");
				Menu_Index_Refresh++;
			}
		
			Gui_DrawFont_GBK24(20,50,Menu_Font_Color,Menu_BG,">Gluttonous Snake");
			Gui_DrawFont_GBK24(20,90,Menu_Font_Color,Menu_BG,">Environment Information <-");
			Gui_DrawFont_GBK24(20,130,Menu_Font_Color,Menu_BG,">LED CONTROL");
			Gui_DrawFont_GBK16(225,220,Menu_Font_Color,Menu_BG,"Choose:");
			Gui_DrawFont_Num32(280, 200,Menu_Num_Color,Menu_BG, 2);			
			break;
		case 3:
			if(Menu_Index_Refresh == 0 ){
				Gui_DrawFont_GBK24(20,50,Menu_BG,Menu_BG,">Gluttonous Snake        <-");
				Gui_DrawFont_GBK24(20,90,Menu_BG,Menu_BG,">Environment Information <-");
				Gui_DrawFont_GBK24(20,130,Menu_BG,Menu_BG,">LED CONTROL             <-");
				Menu_Index_Refresh++;
			}
			
			Gui_DrawFont_GBK24(20,50,Menu_Font_Color,Menu_BG,">Gluttonous Snake");
			Gui_DrawFont_GBK24(20,90,Menu_Font_Color,Menu_BG,">Environment Information");
			Gui_DrawFont_GBK24(20,130,Menu_Font_Color,Menu_BG,">LED CONTROL             <-");
			Gui_DrawFont_GBK16(225,220,Menu_Font_Color,Menu_BG,"Choose:");
			Gui_DrawFont_Num32(280, 200,Menu_Num_Color,Menu_BG, 3);
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
				LCD_DrawSqureBorder(0,0,320,240,RGB(205,155,29));
				LCD_DrawSqureBorder(3,3,314,234,RGB(238,180,34));
				LCD_DrawSqureBorder(6,6,308,228,RGB(255,193,37));
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
				Gui_DrawLine(100,0,100,240,WHITE);
				Gui_DrawFont_GBK16(30,60,RGB(255,245,238),PWMControl_BG,"LEDPWM");
				Gui_DrawFont_GBK16(120,60,RED,PWMControl_BG,"Red");
				Gui_DrawFont_GBK16(180,60,GREEN,PWMControl_BG,"Green");
				Gui_DrawFont_GBK16(240,60,BLUE,PWMControl_BG,"Blue");	
				PWMControl_Refresh_Flag++;
				PWM_CRR_Refresh = 0;
				PWM_CRRRED_Refresh = 0;
				PWM_CRRGREEN_Refresh = 0;
				PWM_CRRBLUE_Refresh = 0;
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
	
	Gui_DrawFont_GBK16(50,60,EnvironmentInformation_Font_BG,EnvironmentInformation_BG,LUMI);
	Gui_DrawFont_GBK16(50,120,EnvironmentInformation_Font_BG,EnvironmentInformation_BG,TEMP);
	Gui_DrawFont_GBK16(50,180,EnvironmentInformation_Font_BG,EnvironmentInformation_BG,AIRQ);
	
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
			LCD_DrawSqure(50,30,8,8,RGB(255,255,0));
			LCD_DrawSqure(128,30,8,8,PWMControl_BG);
			LCD_DrawSqure(193,30,8,8,PWMControl_BG);
			LCD_DrawSqure(248,30,8,8,PWMControl_BG);
			break;
		case 2:
			LCD_DrawSqure(50,30,8,8,PWMControl_BG);
			LCD_DrawSqure(128,30,8,8,RGB(255,255,0));
			LCD_DrawSqure(193,30,8,8,PWMControl_BG);
			LCD_DrawSqure(248,30,8,8,PWMControl_BG);			
			break;
		case 3:
			LCD_DrawSqure(50,30,8,8,PWMControl_BG);
			LCD_DrawSqure(128,30,8,8,PWMControl_BG);
			LCD_DrawSqure(193,30,8,8,RGB(255,255,0));
			LCD_DrawSqure(248,30,8,8,PWMControl_BG);			
			break;
		case 4:
			LCD_DrawSqure(50,30,8,8,PWMControl_BG);
			LCD_DrawSqure(128,30,8,8,PWMControl_BG);
			LCD_DrawSqure(193,30,8,8,PWMControl_BG);
			LCD_DrawSqure(248,30,8,8,RGB(255,255,0));			
			break;
		default: ;break;
	}	
	
//	IntToString(CRR,Crr);
//	IntToString(CRR_Red,Crr_Red);
//	IntToString(CRR_Green,Crr_Green);
//	IntToString(CRR_Blue,Crr_Blue);
	if(CRR == 10){
		Gui_DrawFont_Num32(25, 120,RGB(255,245,238),PWMControl_BG, 1);
		Gui_DrawFont_Num32(55, 120,RGB(255,245,238),PWMControl_BG, 0);
	}
	else	Gui_DrawFont_Num32(40, 120,RGB(255,245,238),PWMControl_BG, CRR);	

	if(CRR_Red == 10){
		Gui_DrawFont_Num32(105, 120,RGB(255,245,238),PWMControl_BG, 1);	
		Gui_DrawFont_Num32(135, 120,RGB(255,245,238),PWMControl_BG, 0);	
	}
	else Gui_DrawFont_Num32(120, 120,RGB(255,245,238),PWMControl_BG, CRR_Red);

	if(CRR_Green == 10){
		Gui_DrawFont_Num32(165, 120,RGB(255,245,238),PWMControl_BG, 1);
		Gui_DrawFont_Num32(195, 120,RGB(255,245,238),PWMControl_BG, 0);
	}
	else Gui_DrawFont_Num32(180, 120,RGB(255,245,238),PWMControl_BG, CRR_Green);	

	if(CRR_Blue == 10){
		Gui_DrawFont_Num32(225, 120,RGB(255,245,238),PWMControl_BG, 1);	
		Gui_DrawFont_Num32(255, 120,RGB(255,245,238),PWMControl_BG, 0);	
	}
	else Gui_DrawFont_Num32(240, 120,RGB(255,245,238),PWMControl_BG, CRR_Blue);	
//	Gui_DrawFont_GBK16(45,120,RGB(255,245,238),PWMControl_BG,Crr);
//	Gui_DrawFont_GBK16(125,120,RGB(255,245,238),PWMControl_BG,Crr_Red);
//	Gui_DrawFont_GBK16(185,120,RGB(255,245,238),PWMControl_BG,Crr_Green);
//	Gui_DrawFont_GBK16(245,120,RGB(255,245,238),PWMControl_BG,Crr_Blue);		
	Led_PWMControl(CRR);
	FullColor_PWMControl(CRR_Red,CRR_Green,CRR_Blue);

	if(CRR_Pre == 10 && CRR!=10){
		Gui_DrawFont_Num32(25, 120,PWMControl_BG,PWMControl_BG, 1);
		Gui_DrawFont_Num32(55, 120,PWMControl_BG,PWMControl_BG, 0);
		//Gui_DrawFont_GBK16(45,120,PWMControl_BG,PWMControl_BG,Crr);
	}
		
	if(CRRRED_Pre == 10 && CRR_Red!=10){
		Gui_DrawFont_Num32(105, 120,PWMControl_BG,PWMControl_BG, 1);	
		Gui_DrawFont_Num32(135, 120,PWMControl_BG,PWMControl_BG, 0);	
		//Gui_DrawFont_GBK16(125,120,PWMControl_BG,PWMControl_BG,Crr_Red);
	}

	if(CRRGREEN_Pre == 10 && CRR_Green!=10){
		Gui_DrawFont_Num32(165, 120,PWMControl_BG,PWMControl_BG, 1);
		Gui_DrawFont_Num32(195, 120,PWMControl_BG,PWMControl_BG, 0);
		//Gui_DrawFont_GBK16(185,120,PWMControl_BG,PWMControl_BG,Crr_Green);
	}
	
	if(CRRBLUE_Pre == 10 && CRR_Blue!=10){
		Gui_DrawFont_Num32(225, 120,PWMControl_BG,PWMControl_BG, 1);	
		Gui_DrawFont_Num32(255, 120,PWMControl_BG,PWMControl_BG, 0);	
		//Gui_DrawFont_GBK16(245,120,PWMControl_BG,PWMControl_BG,Crr_Blue);
	}	
	
	CRR_Pre = CRR;
	CRRRED_Pre = CRR_Red;
	CRRGREEN_Pre = CRR_Green;
	CRRBLUE_Pre = CRR_Blue;	
}