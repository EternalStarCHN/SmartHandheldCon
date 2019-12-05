/*
* 项目所有ADC相关函数 变量的定义 原形在这个文件中
* 此文件作用详情见 User_adc.h
*/
#include "User_adc.h"

//ADC转换完成标志位 阻塞模式函数会使用该标志位
//static volatile uint8_t ADC_CompleteFlag = 0;

//初始化ADC 采样率应该在CubeMx配置
void User_AdcInit(void)
{
	//ADC初始化
	HAL_ADC_Init(&hadc1);
	//TIM3初始化
	HAL_TIM_Base_Init(&htim3);
	HAL_TIM_Base_Start(&htim3);
}


void User_AdcStartBlokingMode(uint16_t* ArrayAddress,
															uint16_t  Lenth
														 )
{
	HAL_ADC_Start_DMA(&hadc1,(uint32_t*)ArrayAddress,Lenth);
	HAL_Delay(1005);
	User_AdcStop(); 
}

void User_AdcStop(void)
{
	HAL_ADC_Stop_DMA(&hadc1);
}


//注意 回调函数就是HAL库的中断服务函数 底层自动生成的中断服务函数
//切勿修改
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
	//判断 如果是ADC1
//	if(hadc->Instance == ADC1)
//	{
//		ADC_CompleteFlag = 1;
//	}
}
