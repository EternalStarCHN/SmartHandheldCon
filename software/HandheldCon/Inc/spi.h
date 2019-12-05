/**
  ******************************************************************************
  * File Name          : SPI.h
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __spi_H
#define __spi_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN Private defines */
#define LCD_X_SIZE	        240
#define LCD_Y_SIZE	        320
//֨ӥˇرʹԃۡǁ 		0,һʹԃ.1,ʹԃ
#define USE_HORIZONTAL  		1
#ifdef USE_HORIZONTAL
#define X_MAX_PIXEL	        LCD_Y_SIZE
#define Y_MAX_PIXEL	        LCD_X_SIZE
#else
#define X_MAX_PIXEL	        LCD_X_SIZE
#define Y_MAX_PIXEL	        LCD_Y_SIZE
#endif

#define RED			0xF800
#define GREEN		0x07E0
#define BLUE 		0x001F
#define WHITE		0xFFFF
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   		//ܒɫ0  00110 001011 00101
#define GRAY1   0x8410      //ܒɫ1  00000 000000 00000
#define GRAY2   0x4208      //ܒɫ2  11111 111110 11111

//Һާ࠘׆ࠚ׃1әطԯߤ۪֨ӥ
#define	LCD_CS_SET  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);    
#define	LCD_DC_SET  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);     
#define	LCD_RST_SET  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_SET);      

//Һާ࠘׆ࠚ׃0әطԯߤ۪֨ӥ
#define	LCD_CS_CLR  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET);    
#define	LCD_DC_CLR  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);      
#define	LCD_RST_CLR  	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, GPIO_PIN_RESET); 

#define SPI_SPEED_SET(SPIHandle,SPIScale)	do{(SPIHandle.Instance->CR1)&=0xFFC7;(SPIHandle.Instance->CR1)|=SPIScale;}while(0);

/* USER CODE END Private defines */

void MX_SPI1_Init(void);

/* USER CODE BEGIN Prototypes */
void Lcd_WriteIndex(uint8_t Index);
void Lcd_WriteData(uint8_t Data);
void LCD_WriteReg(uint8_t Index,uint16_t Data);
void Lcd_WriteData_16Bit(uint16_t Data);
void Lcd_Reset(void);
void Lcd_Init(void);
void Lcd_SetXY(uint16_t Xpos, uint16_t Ypos);
void Lcd_SetRegion(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);
void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data);
void Lcd_Clear(uint16_t Color);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ spi_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
