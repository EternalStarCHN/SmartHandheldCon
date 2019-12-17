#include "User_Buzzer.h"

void Buzzer_Yell(void){
	HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_RESET);
}

void Buzzer_Stop(void){
	HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_SET);
}

void Buzzer_Yell_Times(uint8_t Times,uint8_t On_delay_ms,uint8_t Off_delay_ms){
	uint8_t i = 0;
	for(i = 0;i<Times;i++){
		HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_RESET);
		HAL_Delay(On_delay_ms);
		HAL_GPIO_WritePin(Buzzer_GPIO_Port,Buzzer_Pin,GPIO_PIN_SET);
		HAL_Delay(Off_delay_ms);
	}
}