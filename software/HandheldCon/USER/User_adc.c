#include "User_adc.h"

int adc1_Value;
int adc2_Value;
double luminance;
double temperture;

void MyADC_Init(void){
	HAL_ADC_Start(&hadc1);
	HAL_ADC_Start(&hadc2);
}

void MyADC_ValueGet(void){
		HAL_ADC_Start(&hadc1);
		HAL_ADC_Start(&hadc2);		
		if(HAL_ADC_PollForConversion(&hadc1,0xff)==HAL_OK){
			adc1_Value = HAL_ADC_GetValue(&hadc1);
			luminance = adc1_Value*3.3/4096;
		}
		if(HAL_ADC_PollForConversion(&hadc2,0xff)==HAL_OK){
			adc2_Value = HAL_ADC_GetValue(&hadc2);
			temperture = adc2_Value*3.3/4096;
		}
}
