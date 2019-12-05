/*
* 项目用户ADC所有相关函数 结构 定义申明都在这个文件
* 
* 此文件操作ADC1的PA1输入端口 以2048Hz采样速率对PA1进行12位ADC采样
* 采样过程中采用DMA2Stream0 向内存写数据 一次采样采集2048个数据 采样时间1s
* 此用户ADC函数需要TIM3作为触发时钟源 所以其他功能请避免使用TIM3
* 此文件ADC采样主要是为了配合FFT函数实现信号频域分析
*
* 在2048Hz采样率 2048次采样FFT中 能分辨DC~1023Hz的信号 分辨率为1Hz
*/
#ifndef USER_ADC_H_
#define USER_ADC_H_


#include "main.h"
#include "adc.h"
#include "tim.h"

void User_AdcInit(void);

//用户ADC开始转换函数 输入参数为输出数据的存放地址以及转换次数 阻塞模式
void User_AdcStartBlokingMode(uint16_t* ArrayAddress,
									 uint16_t  Lenth
									);

//用户ADC停函数
void User_AdcStop(void);




#endif