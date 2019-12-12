#include "User_adc.h"

int adc1_Value = 0;
int adc2_Value = 0;
double luminance;
double temperture;

void MyADC_Init(void){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc1,10);
	HAL_ADC_PollForConversion(&hadc2,10);	
}

void MyADC_ValueGet(void){
	adc1_Value = HAL_ADC_GetValue(&hadc1);
	adc2_Value = HAL_ADC_GetValue(&hadc1);	
	luminance = adc1_Value*3.3/4096;
	temperture = adc2_Value*3.3/4096;	
}
