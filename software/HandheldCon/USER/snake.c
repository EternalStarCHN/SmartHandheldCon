#include"snake.h"

uint8_t Up_Pre=0;
uint8_t Down_Pre=0;
uint8_t Left_Pre=0;
uint8_t Right_Pre=0;

uint8_t Up_Status = 0;
uint8_t Down_Status = 0;
uint8_t Left_Status =0;
uint8_t Right_Status =0;

extern uint8_t Up_Flag;
extern uint8_t Down_Flag;
extern uint8_t Left_Flag;
extern uint8_t Right_Flag;

Snake Snake_R;
Food Food_R;

void Init_SNAKE(void){
	uint8_t i;
	
	Up_Status = Down_Status = Left_Status = Right_Status = 0;//CLear
	Up_Pre = Down_Pre = Left_Pre = Right_Pre = 0;//CLear
	
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
	
	if(Up_Flag)
		Up_Status = 1;
	if(Down_Flag)
		Down_Status = 1;
	if(Left_Flag)
		Left_Status = 1;
	if(Right_Flag)
		Right_Status = 1;
	
	if((Up_Status==1&&Down_Pre==0)||(Down_Flag==1&&Up_Pre==1))
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
		if(Down_Flag==0){
			Up_Pre = Up_Status;
		}
		Up_Flag = 0;
	} 
		
	if((Down_Status==1&&Up_Pre==0)||(Up_Flag==1&&Down_Pre==1))
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
		if(Up_Flag==0){
			Down_Pre = Down_Status;
		}
		Down_Flag = 0;
	} 
	
		if((Left_Status==1&&Right_Pre==0)||(Right_Flag==1&&Left_Pre==1))
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
		if(Right_Flag==0){
			Left_Pre = Left_Status;
		}
		Left_Flag = 0;
	} 
		
	if((Right_Status==1&&Left_Pre==0)||(Left_Flag==1&&Right_Pre==1))
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
		if(Left_Flag==0){
			Right_Pre = Right_Status;
		}
	Right_Flag = 0;
	} 	
}
	