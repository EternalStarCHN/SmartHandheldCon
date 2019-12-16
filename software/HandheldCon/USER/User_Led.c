#include "User_Led.h"

uint8_t LED_Waterfall_Con = 0;
uint8_t LEDPWM_Refresh_Flag = 0;

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

void Led_OpenHUMI(void){
	HAL_GPIO_WritePin(LED_HUMI_GPIO_Port,LED_HUMI_Pin,GPIO_PIN_RESET);
	HAL_Delay(50);
}

void Led_OpenTEMP(void){
	HAL_GPIO_WritePin(LED_TEMP_GPIO_Port,LED_TEMP_Pin,GPIO_PIN_RESET);
	HAL_Delay(50);
}

void LED_TwinkleHUMI(uint8_t times,uint8_t delay_ms){
	int i;
	for(i =0 ;i<times; i++){
		HAL_GPIO_WritePin(LED_HUMI_GPIO_Port,LED_HUMI_Pin,GPIO_PIN_RESET);
		HAL_Delay(delay_ms);
		HAL_GPIO_WritePin(LED_HUMI_GPIO_Port,LED_HUMI_Pin,GPIO_PIN_SET);
		HAL_Delay(delay_ms);
	}
}

void LED_TwinkleTEMP(uint8_t times,uint8_t delay_ms){
	int i;
	for(i =0 ;i<times; i++){
		HAL_GPIO_WritePin(LED_TEMP_GPIO_Port,LED_TEMP_Pin,GPIO_PIN_SET);
		HAL_Delay(delay_ms);
		HAL_GPIO_WritePin(LED_TEMP_GPIO_Port,LED_TEMP_Pin,GPIO_PIN_SET);
		HAL_Delay(delay_ms);
	}
}

void Led_WaterfallLight_Delay(uint8_t delay_ms){
	uint8_t TimesCount = 0;
	while(LED_Waterfall_Con){
		if(TimesCount>=4)TimesCount = 0;
		switch(TimesCount%4){
			case 0:
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_SET);			
				break;		
			case 1:
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_SET);
				break;
			case 2:
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_SET);
				break;
			case 3:
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_SET);			
				break;
			default:;break;
		}
		TimesCount++;		
	}
}

void Led_WaterfallLight_Times(uint8_t Times,uint8_t delay_ms){
	uint8_t times = Times;
while(times>=0){
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Red_GPIO_Port,Led_Red_Pin,GPIO_PIN_SET);			
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port,Led_Yellow_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Blue_GPIO_Port,Led_Blue_Pin,GPIO_PIN_SET);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_RESET);
				HAL_Delay(delay_ms);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port,Led_Green_Pin,GPIO_PIN_SET);
				times--;
		}
}

void Led_PWMControl(uint8_t CRR){
	if(!LEDPWM_Refresh_Flag){
		HAL_TIM_PWM_Init(&htim2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
	}
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,CRR);
}

void FullColor_PWMControl(uint8_t CRR_Red,uint8_t CRR_Green,uint8_t CRR_Blue){
		if(!LEDPWM_Refresh_Flag){
		HAL_TIM_PWM_Init(&htim3);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
	}
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,CRR_Blue);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,CRR_Red);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,CRR_Green);	
}