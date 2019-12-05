/*
* 本工程FFT相关函数 结构体 定义声明都在这个文件内
*/
#ifndef USER_FFT_H_
#define USER_FFT_H_

#include "User_FFT.h"
#include "User_adc.h"
#include "arm_math.h"
#include "stdint.h"
/*
* 该函数会从ADC以阻塞模式 2048Hz采样率采2048个点 然后进行rFFT 最终输出每个点的模长
*/
typedef struct {
	int key;
	float value;
}Pair;
void User_FastRfft2048BlokingMode(float32_t* MagOutPosition);
int compare(int a, int b);
void sort(Pair* a);
Pair* generate_data();
void OUTPUT_Fre(void);
void OUTPUT_amp(void);
void print_data(Pair *data);
#endif
