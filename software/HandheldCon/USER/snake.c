#include"snake.h"

uint8_t Game1_Up_Pre=0;
uint8_t Game1_Down_Pre=0;
uint8_t Game1_Left_Pre=0;
uint8_t Game1_Right_Pre=0;

uint8_t Game1_Pre = 0;//Up:1 Down:2 Left:3 Right:4

uint8_t Game1_Up_Status = 0;
uint8_t Game1_Down_Status = 0;
uint8_t Game1_Left_Status =0;
uint8_t Game1_Right_Status =0;

uint8_t Game1_InitFirst = 0;
uint8_t Game1_Dead = 0;
uint8_t Game1_Restart = 0;
uint8_t Game1_Pass = 0;
uint8_t Game1_Continue = 0;
uint8_t Game1_Dead_Refresh = 0;
uint8_t Game1_Pass_Refresh = 0;

extern uint8_t Game1_Up_Flag;
extern uint8_t Game1_Down_Flag;
extern uint8_t Game1_Left_Flag;
extern uint8_t Game1_Right_Flag;


char SCORE[256]={0};	
char S_HeadX[256]={0};
char S_HeadY[256]={0};
char F_HeadX[256]={0};
char F_HeadY[256]={0};

Snake Snake_R;
Food Food_R;

void Init_SNAKE(void){
	uint8_t i;
	
	Game1_Up_Status = Game1_Down_Status = Game1_Left_Status = Game1_Right_Status = 0;//Status_CLear
	Game1_Up_Pre = Game1_Down_Pre = Game1_Left_Pre = Game1_Right_Pre = 0;//Pre_CLear
	
	Lcd_Clear(BLACK); //背景色
	//LCD_DrawSqure1(0,18,320,222,WHITE,BLACK);
	LCD_DrawSqureBorder(0,0,240,240,WHITE);
	Gui_DrawFont_GBK16(270,20,YELLOW,BLACK,"SCORE:");

	Snake_R.Long = 2; 
	Snake_R.Life = 0; //初始化蛇还活着
	if(!Game1_InitFirst){
		Snake_R.Score = 0;
		Game1_InitFirst++;
	}
	Food_R.Yes = 1;
	
	IntToString(Snake_R.Score,SCORE);
	Gui_DrawFont_GBK16(270,40,YELLOW,BLACK,SCORE);
	
	for(i=0;i<Snake_R.Long;i++) //将蛇给赋值
	{
		Snake_R.X[i]=SNAKE_Area*i+120;
		Snake_R.Y[i]=120; 
	}
	for(i=0;i<Snake_R.Long;i++) //将蛇给画出来
	{
		LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RED);
	} 
}

void Run_SNAKE(void){
	uint8_t i = 0;
	
	if(Game1_Up_Flag)
		Game1_Up_Status = 1;
	if(Game1_Down_Flag)
		Game1_Down_Status = 1;
	if(Game1_Left_Flag)
		Game1_Left_Status = 1;
	if(Game1_Right_Flag)
		Game1_Right_Status = 1;
	Show_Head();
// 判蛇头是否撞到墙壁
	if(Snake_R.X[Snake_R.Long-1]<5||Snake_R.X[Snake_R.Long-1]>230||Snake_R.Y[Snake_R.Long-1]<5||Snake_R.Y[Snake_R.Long-1]>230){
		Snake_R.Life=1;
	}
	
//判断蛇是否死亡
	if(Snake_R.Life==1)
	{
		Display_Dead();
	}
if(!Snake_R.Life){
	if((Game1_Up_Status==1&&Game1_Down_Pre==0)||(Game1_Down_Flag==1&&Game1_Up_Pre==1))
	{
		
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+0;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]-SNAKE_Area; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RED);
		}
		if(Game1_Down_Flag==0){
			Game1_Up_Pre = Game1_Up_Status;
		}
		Game1_Up_Flag = 0;
	} 
		
	if((Game1_Down_Status==1&&Game1_Up_Pre==0)||(Game1_Up_Flag==1&&Game1_Down_Pre==1))
	{
	
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+0;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+SNAKE_Area; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RED);
		}
		if(Game1_Up_Flag==0){
			Game1_Down_Pre = Game1_Down_Status;
		}
		Game1_Down_Flag = 0;
	} 
	
		if((Game1_Left_Status==1&&Game1_Right_Pre==0)||(Game1_Right_Flag==1&&Game1_Left_Pre==1))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]-SNAKE_Area;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+0; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RED);
		}
		if(Game1_Right_Flag==0){
			Game1_Left_Pre = Game1_Left_Status;
		}
		Game1_Left_Flag = 0;
	} 
		
	if((Game1_Right_Status==1&&Game1_Left_Pre==0)||(Game1_Left_Flag==1&&Game1_Right_Pre==1))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+SNAKE_Area;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+0; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RED);
		}
		if(Game1_Left_Flag==0){
			Game1_Right_Pre = Game1_Right_Status;
		}
	Game1_Right_Flag = 0;
	}
}	

	


// 从第三节开始判断蛇头是否咬到自己	
	for(i=3;i<Snake_R.Long;i++)
	{
		if(Snake_R.X[i]==Snake_R.X[0]&&Snake_R.Y[i]==Snake_R.Y[0])
		{
			Snake_R.Life=1;
		}
	}
	
 
	
//判断蛇是否到达最长
	if(Snake_R.Long==SNAKE_Max_Long)
	{
		Display_Pass();
	}	
	
//判断蛇是否吃到食物
	if(Snake_R.X[Snake_R.Long-1]==Food_R.X&&Snake_R.Y[Snake_R.Long-1]==Food_R.Y)
	{
		IntToString(Snake_R.Score,SCORE);						//将分数转换为String
		Gui_DrawFont_GBK16(270,40,BLACK,BLACK,1);
		LCD_DrawSqure(Food_R.X,Food_R.Y,SNAKE_Area,SNAKE_Area,BLACK); //消隐食物
		Snake_R.Long++;// 蛇节数加 1
		Snake_R.X[Snake_R.Long-1]=Food_R.X;
		Snake_R.Y[Snake_R.Long-1]=Food_R.Y;
		Snake_R.Score+=10;
		IntToString(Snake_R.Score,SCORE);					//将分数转换为String
		Gui_DrawFont_GBK16(270,40,YELLOW,BLACK,SCORE);
		Food_R.Yes=1; //食物标志置 1
	}
	
//生成食物
	if(Food_R.Yes==1)
	{
		while(1)
		{
			Food_R.X=((int)(abs(HAL_RNG_GetRandomNumber(&hrng))%72))*5; //随机生成食物X
			if(Food_R.X%5==4)
				Food_R.X++;
			Food_R.Y=(int)(abs(HAL_RNG_GetRandomNumber(&hrng))%44)*5+20; //随机生成食物Y
			for(i=0;i<Snake_R.Long;i++) //判断产生的食物坐标是否和蛇身重合
			{
			if((Food_R.X==Snake_R.X[i])&&(Food_R.X==Snake_R.Y[i]))
				break;
			}
			if(i==Snake_R.Long)
			{
				Food_R.Yes=0;
				break; //产生有效的食物坐标
			}
		}
	}
	if(Food_R.Yes==0 && Snake_R.Life == 0)
	{
		LCD_DrawSqure(Food_R.X,Food_R.Y,SNAKE_Area,SNAKE_Area,GREEN); 
	}
	HAL_Delay(1000-Snake_R.Level*10);
}

void Display_Dead(void)
{
	Game1_Dead = 1;
	if(!Game1_Dead_Refresh){
		Lcd_Clear(BLACK);
		Game1_Dead_Refresh++;
	}
	LCD_DrawSqureBorder(0,0,320,240,RED);
	Gui_DrawFont_GBK16(120,100,WHITE,BLACK,"GAME OVER! ");
	Gui_DrawFont_GBK16(80,150,WHITE,BLACK,"press CONFIRM to restart");
	Gui_DrawFont_GBK16(80,170,WHITE,BLACK,"press RETURN  to MENU");	
	if(Game1_Restart){
		
		Snake_R.Score = 0;
		Snake_R.Level = 0;
		Init_SNAKE();
		
		Game1_Dead = 0;
		Game1_Restart = 0;
		Game1_Dead_Refresh = 0;
	}
}

void Display_Pass(void)
{
	Game1_Pass = 1;
	Snake_R.Level++;
	if(!Game1_Pass_Refresh){
			Lcd_Clear(BLACK);
			Game1_Pass_Refresh++;
	}
	LCD_DrawSqureBorder(0,0,320,240,GREEN);
	Gui_DrawFont_GBK16(100,100,YELLOW,BLACK,"MISSION SUCCESS!");
	Gui_DrawFont_GBK16(60,150,YELLOW,BLACK,"press Confirm to contiue");
	if(Game1_Continue){

		Init_SNAKE();
		
		Game1_Pass = 0;
		Game1_Continue = 0;
		Game1_Pass_Refresh = 0;
	}
}

void Show_Head(void){
	Gui_DrawFont_GBK16(250,180,BLACK,BLACK,S_HeadX);
	Gui_DrawFont_GBK16(290,180,BLACK,BLACK,S_HeadY);
	Gui_DrawFont_GBK16(250,220,BLACK,BLACK,F_HeadX);
	Gui_DrawFont_GBK16(290,220,BLACK,BLACK,F_HeadY);
	IntToString(Snake_R.X[Snake_R.Long-1],S_HeadX);
	IntToString(Snake_R.Y[Snake_R.Long-1],S_HeadY);
	IntToString(Food_R.X,F_HeadX);
	IntToString(Food_R.Y,F_HeadY);
	Gui_DrawFont_GBK16(250,180,WHITE,BLACK,S_HeadX);
	Gui_DrawFont_GBK16(290,180,WHITE,BLACK,S_HeadY);
	Gui_DrawFont_GBK16(250,220,WHITE,BLACK,F_HeadX);
	Gui_DrawFont_GBK16(290,220,WHITE,BLACK,F_HeadY);
}
	