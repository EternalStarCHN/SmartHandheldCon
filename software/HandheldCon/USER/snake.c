#include"snake.h"

uint8_t Game1_Up_Pre=0;
uint8_t Game1_Down_Pre=0;
uint8_t Game1_Left_Pre=0;
uint8_t Game1_Right_Pre=0;

uint8_t Game1_Up_Status = 0;
uint8_t Game1_Down_Status = 0;
uint8_t Game1_Left_Status =0;
uint8_t Game1_Right_Status =0;

uint8_t Game1_Dead_Refresh = 0;
uint8_t Game1_Restart = 0;

extern uint8_t Game1_Up_Flag;
extern uint8_t Game1_Down_Flag;
extern uint8_t Game1_Left_Flag;
extern uint8_t Game1_Right_Flag;
extern uint8_t Game1_Dead;

Snake Snake_R;
Food Food_R;

void Init_SNAKE(void){
	uint8_t i;
	
	Game1_Up_Status = Game1_Down_Status = Game1_Left_Status = Game1_Right_Status = 0;//CLear
	Game1_Up_Pre = Game1_Down_Pre = Game1_Left_Pre = Game1_Right_Pre = 0;//CLear
	
	Lcd_Clear(BLACK); //背景色
	//LCD_DrawSqure1(0,18,320,222,WHITE,BLACK);
	LCD_DrawSqureBorder(0,18,320,222,WHITE);
	Gui_DrawFont_GBK16(120,0,RED,BLACK,"YOUR SCORE:");

	Snake_R.Long=2; 
	Snake_R.Life=0; //初始化蛇还活着
	Snake_R.Score=0;
	Food_R.Yes=1;

	for(i=0;i<Snake_R.Long;i++) //将蛇给赋值
	{
		Snake_R.X[i]=SNAKE_Length*i+10;
		Snake_R.Y[i]=20; 
	}
	for(i=0;i<Snake_R.Long;i++) //将蛇给画出来
	{
		LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Length,SNAKE_Length,RED);
	}
}

void Run_SNAKE(void){
	uint8_t i = 0;
	HAL_Delay(1000);
	
	if(Game1_Up_Flag)
		Game1_Up_Status = 1;
	if(Game1_Down_Flag)
		Game1_Down_Status = 1;
	if(Game1_Left_Flag)
		Game1_Left_Status = 1;
	if(Game1_Right_Flag)
		Game1_Right_Status = 1;
	
	if((Game1_Up_Status==1&&Game1_Down_Pre==0)||(Game1_Down_Flag==1&&Game1_Up_Pre==1))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Length,SNAKE_Length,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+0;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]-SNAKE_Length; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Length,SNAKE_Length,RED);
		}
		if(Game1_Down_Flag==0){
			Game1_Up_Pre = Game1_Up_Status;
		}
		Game1_Up_Flag = 0;
	} 
		
	if((Game1_Down_Status==1&&Game1_Up_Pre==0)||(Game1_Up_Flag==1&&Game1_Down_Pre==1))
	{
	
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Length,SNAKE_Length,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+0;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+SNAKE_Length; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Length,SNAKE_Length,RED);
		}
		if(Game1_Up_Flag==0){
			Game1_Down_Pre = Game1_Down_Status;
		}
		Game1_Down_Flag = 0;
	} 
	
		if((Game1_Left_Status==1&&Game1_Right_Pre==0)||(Game1_Right_Flag==1&&Game1_Left_Pre==1))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Length,SNAKE_Length,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]-SNAKE_Length;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+0; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Length,SNAKE_Length,RED);
		}
		if(Game1_Right_Flag==0){
			Game1_Left_Pre = Game1_Left_Status;
		}
		Game1_Left_Flag = 0;
	} 
		
	if((Game1_Right_Status==1&&Game1_Left_Pre==0)||(Game1_Left_Flag==1&&Game1_Right_Pre==1))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Length,SNAKE_Length,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+SNAKE_Length;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+0; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Length,SNAKE_Length,RED);
		}
		if(Game1_Left_Flag==0){
			Game1_Right_Pre = Game1_Right_Status;
		}
	Game1_Right_Flag = 0;
	} 	
}

void Display_dead(void)
{
	Game1_Dead = 1;
	if(!Game1_Dead_Refresh){
		Lcd_Clear(BLACK);
		Game1_Dead_Refresh++;
	}
	LCD_DrawSqureBorder(0,18,320,222,RED);
	Gui_DrawFont_GBK16(120,100,WHITE,BLACK,"GAME OVER! ");
	Gui_DrawFont_GBK16(120,150,WHITE,BLACK,"Restart <-");
	Gui_DrawFont_GBK16(120,170,WHITE,BLACK,"Menu    <-");
//	while(Key_Value!=KEY_DOWN)
//	{
//	Key_Value=KEY_Scan(0);;
//	}
//	LCD_Clear(BLACK);
	
	//Init_SNAKE();
}


	