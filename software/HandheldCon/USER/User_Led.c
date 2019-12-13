#include "User_Led.h"

uint8_t LED_Waterfall_Con = 0;
uint8_t PWM_Refresh_Flag = 0;

void Led_OpenALL(void){
		HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_RESET);
}

void Led_CloseALL(void){
		HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_SET);
}

void Led_WaterfallLight_Delay(uint8_t Delays){
	uint8_t TimesCount = 0;
	while(LED_Waterfall_Con){
		if(TimesCount>=4)TimesCount = 0;
		switch(TimesCount%4){
			case 0:
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_SET);			
				break;		
			case 1:
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_SET);
				break;
			case 2:
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_SET);
				break;
			case 3:
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_SET);			
				break;
			default:;break;
		}
		TimesCount++;		
	}
}

void Led_WaterfallLight_Times(uint8_t Times,uint8_t Delays){
	uint8_t times = Times;
while(times>=0){
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_SET);			
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_RESET);
				HAL_Delay(100*Delays);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_SET);
				times--;
		}
}

void Led_PWMControl(void){
	if(!PWM_Refresh_Flag){
		HAL_TIM_PWM_Init(&htim2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	}
}