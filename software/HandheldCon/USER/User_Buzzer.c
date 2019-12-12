#include "User_Buzzer.h"

void Buzzer_Yell(void){
	HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_RESET);
}

void Buzzer_Stop(void){
	HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_SET);
}

void Buzzer_Yell_Times(uint8_t Times,uint8_t Delays){
	uint8_t times = Times;
	while(times > 0){
		HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_RESET);
		HAL_Delay(100*Delays);
		HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_SET);
		times--;
	}
}