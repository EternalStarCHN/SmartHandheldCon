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

uint8_t LED_Refresh_Flag = 0;
uint8_t Buzzer_Refresh_Flag = 0;

uint8_t Snake_Color_R = 0;
uint8_t Snake_Color_G = 0;
uint8_t Snake_Color_B = 0;

extern uint8_t Game1_Up_Flag;
extern uint8_t Game1_Down_Flag;
extern uint8_t Game1_Left_Flag;
extern uint8_t Game1_Right_Flag;


char SCORE[256]={0};
char LEVEL[256]={0};
char S_HeadX[256]={0};
char S_HeadY[256]={0};
char F_HeadX[256]={0};
char F_HeadY[256]={0};

Snake Snake_R;
Food Food_R;

void Init_SNAKE(void){
	uint8_t i;
	
	Game1_Up_Status = Game1_Down_Status = Game1_Left_Status = Game1_Right_Status = 0;//Status_CLear
	Game1_Pre = 0;
	
	Lcd_Clear(BLACK); //背景色
	LCD_DrawSqureBorder(0,0,240,240,WHITE);
	Gui_DrawFont_GBK16(250,20,YELLOW,BLACK,"SCORE:");
	Gui_DrawFont_GBK16(250,70,YELLOW,BLACK,"LEVEL:");
	Snake_R.Long = 2; //初始化蛇长度为2
	Snake_R.Life = 0; //初始化蛇还活着
	if(!Game1_InitFirst){
		Snake_R.Score = 0;
		Game1_InitFirst++;
	}
	Food_R.Yes = 1;
	
	IntToString(Snake_R.Score,SCORE);
	IntToString(Snake_R.Level,LEVEL);
	Gui_DrawFont_GBK16(250,40,YELLOW,BLACK,SCORE);
	Gui_DrawFont_GBK16(250,90,YELLOW,BLACK,LEVEL);
	
	for(i=0;i<Snake_R.Long;i++) //将蛇给赋值
	{
		Snake_R.X[i]=SNAKE_Area*i+120;
		Snake_R.Y[i]=120; 
	}
	for(i=0;i<Snake_R.Long;i++) //将蛇给画出来
	{
		LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RGB(255,165,0)); //蛇身颜色
	} 
	printf("游戏开始!请按任意方向键让蛇运动...\r\n");
}

void Run_SNAKE(void){
	uint8_t i = 0;
	LED_Refresh_Flag = 0;
	Buzzer_Refresh_Flag = 0;
	if(Game1_Up_Flag)
		Game1_Up_Status = 1;
	if(Game1_Down_Flag)
		Game1_Down_Status = 1;
	if(Game1_Left_Flag)
		Game1_Left_Status = 1;
	if(Game1_Right_Flag)
		Game1_Right_Status = 1;
//	Show_Head();
// 判蛇头是否撞到墙壁
	
	if(Snake_R.X[Snake_R.Long-1]<5||Snake_R.X[Snake_R.Long-1]>230||Snake_R.Y[Snake_R.Long-1]<5||Snake_R.Y[Snake_R.Long-1]>230){
		Snake_R.Life=1;
	}
	
//判断蛇是否死亡
	if(Snake_R.Life==1)
	{
		if(!Buzzer_Refresh_Flag){
			Buzzer_Yell_Times(1,50,1000);
			Buzzer_Refresh_Flag++;
		}
		Display_Dead();
	}
	
if(!Snake_R.Life){
	//上走
	if((Game1_Up_Status==1&&Game1_Pre!=2)||(Game1_Down_Flag==1&&Game1_Pre==1))
	{	
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+0;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]-SNAKE_Area; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RGB(255,165,0));
		}
		if(Game1_Down_Flag==0){
			Game1_Pre = 1;
		}
		Game1_Up_Flag = 0;
	} 
	//下走
	if((Game1_Down_Status==1&&Game1_Pre!=1)||(Game1_Up_Flag==1&&Game1_Pre==2))
	{
	
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+0;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+SNAKE_Area; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RGB(255,165,0));
		}
		if(Game1_Up_Flag==0){
			Game1_Pre = 2;
		}
		Game1_Down_Flag = 0;
	} 
	//左走
		if((Game1_Left_Status==1&&Game1_Pre!=4)||(Game1_Right_Flag==1&&Game1_Pre==3))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]-SNAKE_Area;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+0; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RGB(255,165,0));
		}
		if(Game1_Right_Flag==0){
			Game1_Pre = 3;
		}
		Game1_Left_Flag = 0;
	} 
	//右走
	if((Game1_Right_Status==1&&Game1_Pre!=3)||(Game1_Left_Flag==1&&Game1_Pre==4))
	{
		LCD_DrawSqure(Snake_R.X[0],Snake_R.Y[0],SNAKE_Area,SNAKE_Area,BLACK);
		for(i=0;i<Snake_R.Long-1;i++){
			Snake_R.X[i]=Snake_R.X[i+1];
			Snake_R.Y[i]=Snake_R.Y[i+1];
		} 
		Snake_R.X[Snake_R.Long-1]=Snake_R.X[Snake_R.Long-2]+SNAKE_Area;
		Snake_R.Y[Snake_R.Long-1]=Snake_R.Y[Snake_R.Long-2]+0; 
		for(i=0;i<Snake_R.Long;i++){
			LCD_DrawSqure(Snake_R.X[i],Snake_R.Y[i],SNAKE_Area,SNAKE_Area,RGB(255,165,0));
		}
		if(Game1_Left_Flag==0){
			Game1_Pre = 4;
		}
		Game1_Right_Flag = 0;
	}
}	
	
//从第三节开始判断蛇头是否咬到自己	
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
		if(!LED_Refresh_Flag){
			Led_WaterfallLight_Times(2,50,30);
			LED_Refresh_Flag++;
		}
		IntToString(Snake_R.Score,SCORE);						//将分数转换为String
		Gui_DrawFont_GBK16(250,40,BLACK,BLACK,SCORE);
		IntToString(Snake_R.Level,LEVEL);						//将等级转换为String
		Gui_DrawFont_GBK16(250,90,BLACK,BLACK,LEVEL);
		LCD_DrawSqure(Food_R.X,Food_R.Y,SNAKE_Area,SNAKE_Area,BLACK); //消隐食物
		Snake_R.Long++;// 蛇节数加 1
		Snake_R.X[Snake_R.Long-1]=Food_R.X;
		Snake_R.Y[Snake_R.Long-1]=Food_R.Y;
		Snake_R.Score+=10;
		Snake_R.Level++;
		IntToString(Snake_R.Score,SCORE);					//将分数转换为String
		IntToString(Snake_R.Level,LEVEL);					//将分数转换为String
		Gui_DrawFont_GBK16(250,40,YELLOW,BLACK,SCORE);
		Gui_DrawFont_GBK16(250,90,YELLOW,BLACK,LEVEL);
		Food_R.Yes=1; //食物标志置 1
		printf("吃到食物!继续加油！\r\n");
	}
	
//生成食物坐标
	if(Food_R.Yes==1)
	{
		while(1)
		{
			Food_R.X=((int)(abs(HAL_RNG_GetRandomNumber(&hrng))%48))*5; //随机生成食物X
			if(Food_R.X%5==4)
				Food_R.X++;
			Food_R.Y=(int)(abs(HAL_RNG_GetRandomNumber(&hrng))%48)*5; //随机生成食物Y
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
//画出食物	
	if(Food_R.Yes==0 && Snake_R.Life == 0)
	{
		Snake_Color_R = ((int)(abs(HAL_RNG_GetRandomNumber(&hrng))%100))+150;//生成随机R
		Snake_Color_G =	((int)(abs(HAL_RNG_GetRandomNumber(&hrng))%100))+150;//生成随机G
		Snake_Color_B = ((int)(abs(HAL_RNG_GetRandomNumber(&hrng))%100))+150;//生成随机B
		LCD_DrawSqure(Food_R.X,Food_R.Y,SNAKE_Area,SNAKE_Area,RGB(Snake_Color_R,Snake_Color_G,Snake_Color_B)); 
	}
	HAL_Delay(1000-Snake_R.Level*20);//Snake_R.Level
}

void Display_Dead(void)
{
	Game1_Dead = 1;
	Buzzer_Refresh_Flag = 0;
	if(!Game1_Dead_Refresh){
		Lcd_Clear(BLACK);
		Game1_Dead_Refresh++;
	}
	LCD_DrawSqureBorder(0,0,320,240,RED);
	Gui_DrawFont_GBK16(100,100,WHITE,BLACK,"MISSON FAILED! ");
	Gui_DrawFont_GBK16(60,150,WHITE,BLACK,"Press 'CONFIRM' to Restart");
	Gui_DrawFont_GBK16(60,170,WHITE,BLACK,"Press 'RETURN'  to Menu");	
	printf("游戏失败！等待用户操作... \r\n");
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
	Gui_DrawFont_GBK16(60,150,YELLOW,BLACK,"Press ‘Confirm’ to Contiue");
	printf("游戏胜利！等待用户操作... \r\n");
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
	