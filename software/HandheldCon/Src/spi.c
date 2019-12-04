/**
  ******************************************************************************
  * File Name          : SPI.c
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

/* Includes ------------------------------------------------------------------*/
#include "spi.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

SPI_HandleTypeDef hspi3;

/* SPI3 init function */
void MX_SPI3_Init(void)
{

  hspi3.Instance = SPI3;
  hspi3.Init.Mode = SPI_MODE_MASTER;
  hspi3.Init.Direction = SPI_DIRECTION_2LINES;
  hspi3.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi3.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi3.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi3.Init.NSS = SPI_NSS_SOFT;
  hspi3.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi3.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi3.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi3.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi3.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi3) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(spiHandle->Instance==SPI3)
  {
  /* USER CODE BEGIN SPI3_MspInit 0 */

  /* USER CODE END SPI3_MspInit 0 */
    /* SPI3 clock enable */
    __HAL_RCC_SPI3_CLK_ENABLE();
  
    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**SPI3 GPIO Configuration    
    PC10     ------> SPI3_SCK
    PC11     ------> SPI3_MISO
    PC12     ------> SPI3_MOSI 
    */
    GPIO_InitStruct.Pin = SCK_Pin|MISO_Pin|MOSI_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* USER CODE BEGIN SPI3_MspInit 1 */

  /* USER CODE END SPI3_MspInit 1 */
  }
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if(spiHandle->Instance==SPI3)
  {
  /* USER CODE BEGIN SPI3_MspDeInit 0 */

  /* USER CODE END SPI3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI3_CLK_DISABLE();
  
    /**SPI3 GPIO Configuration    
    PC10     ------> SPI3_SCK
    PC11     ------> SPI3_MISO
    PC12     ------> SPI3_MOSI 
    */
    HAL_GPIO_DeInit(GPIOC, SCK_Pin|MISO_Pin|MOSI_Pin);

  /* USER CODE BEGIN SPI3_MspDeInit 1 */

  /* USER CODE END SPI3_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
void SPI_WriteByte(uint8_t data)
{
	HAL_SPI_Transmit(&hspi3,&data,1,3);
//	while(((hspi3.Instance->SR)&SPI_FLAG_TXE)==RESET);	//绛夊緟鍙�??佸尯�??
//	(hspi3.Instance->TXDR)=data;	 												//鍙戦?佷竴涓猙yte
//	while(((hspi3.Instance->SR)&SPI_FLAG_TXE)==RESET);	//绛夊緟鎺ユ敹瀹屼竴涓猙yte
}

void LCD_SPI_Init()
{
	uint8_t temp=0xFF;
	LCD_RST_SET;
	HAL_Delay(50);
	HAL_SPI_Transmit(&hspi3,&temp,1,3);
}

/****************************************************************************
* �??    绉帮細Lcd_WriteIndex(u8 Index)
* �??    鑳斤細鍚戞恫鏅跺睆鍐欎竴�??8浣嶆寚浠?
* 鍏ュ彛鍙傛暟锛欼ndex   瀵勫瓨鍣ㄥ湴�??
* 鍑哄彛鍙傛暟锛氭�?
* �??    鏄庯細璋冪敤鍓嶉渶鍏�??変腑鎺у埗鍣紝鍐呴儴鍑芥�?
****************************************************************************/
void Lcd_WriteIndex(uint8_t Index)
{
   LCD_CS_CLR;
   LCD_DC_CLR;
   SPI_WriteByte(Index);
   LCD_CS_SET;
}

/****************************************************************************
* �??    绉帮細Lcd_WriteData(u8 Data)
* �??    鑳斤細鍚戞恫鏅跺睆鍐欎竴�??8浣嶆暟鎹?
* 鍏ュ彛鍙傛暟锛歞at     瀵勫瓨鍣ㄦ暟�??
* 鍑哄彛鍙傛暟锛氭�?
* �??    鏄庯細鍚戞帶鍒跺櫒鎸囧畾鍦板潃鍐欏叆鏁版嵁锛屽唴閮ㄥ嚱鏁?
****************************************************************************/
void Lcd_WriteData(uint8_t Data)
{
   LCD_CS_CLR;
   LCD_DC_SET;
   SPI_WriteByte(Data);
   LCD_CS_SET;
}

/****************************************************************************
* �??    绉帮細void LCD_WriteReg(u8 Index,u16 Data)
* �??    鑳斤細鍐欏瘎瀛樺櫒鏁版嵁
* 鍏ュ彛鍙傛暟锛欼ndex,Data
* 鍑哄彛鍙傛暟锛氭�?
* �??    鏄庯細鏈�?嚱鏁颁负缁勫悎鍑芥暟锛屽悜Index鍦板潃鐨勫瘎瀛樺櫒鍐欏叆Data�??
****************************************************************************/
void LCD_WriteReg(uint8_t Index,uint16_t Data)
{
	Lcd_WriteIndex(Index);
	Lcd_WriteData_16Bit(Data);
}

/****************************************************************************
* �??    绉帮細void Lcd_WriteData_16Bit(u16 Data)
* �??    鑳斤細鍚戞恫鏅跺睆鍐欎竴�??16浣嶆暟鎹?
* 鍏ュ彛鍙傛暟锛欴ata
* 鍑哄彛鍙傛暟锛氭�?
* �??    鏄庯細鍚戞帶鍒跺櫒鎸囧畾鍦板潃鍐欏叆�??�??16浣嶆暟鎹?
****************************************************************************/
void Lcd_WriteData_16Bit(uint16_t Data)
{
	Lcd_WriteData(Data>>8);
	Lcd_WriteData(Data);
}

/****************************************************************************
* �??    绉帮細void Lcd_Reset(void)
* �??    鑳斤細娑叉櫠纭浣嶅嚱�??
* 鍏ュ彛鍙傛暟锛氭�?
* 鍑哄彛鍙傛暟锛氭�?
* �??    鏄庯細娑叉櫠鍒濆鍖栧墠�??鎵ц�??娆�?�浣嶆搷浣?
****************************************************************************/
void Lcd_Reset(void)
{
	LCD_RST_CLR;
	HAL_Delay(100);
	LCD_RST_SET;
	HAL_Delay(50);
}
/****************************************************************************
* �??    绉帮細void Lcd_Init(void)
* �??    鑳斤細娑叉櫠鍒濆鍖栧嚱�??
* 鍏ュ彛鍙傛暟锛氭�?
* 鍑哄彛鍙傛暟锛氭�?
* �??    鏄庯細娑叉櫠鍒濆鍖朹ILI9225_176X220
****************************************************************************/
void Lcd_Init(void)
{
	LCD_SPI_Init();
	Lcd_Reset(); 							//Reset before LCD Init.
	Lcd_WriteIndex(0xCB);
	Lcd_WriteData(0x39);
	Lcd_WriteData(0x2C);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x34);
	Lcd_WriteData(0x02);

	Lcd_WriteIndex(0xCF);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0XC1);
	Lcd_WriteData(0X30);

	Lcd_WriteIndex(0xE8);
	Lcd_WriteData(0x85);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x78);

	Lcd_WriteIndex(0xEA);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x00);

	Lcd_WriteIndex(0xED);
	Lcd_WriteData(0x64);
	Lcd_WriteData(0x03);
	Lcd_WriteData(0X12);
	Lcd_WriteData(0X81);

	Lcd_WriteIndex(0xF7);
	Lcd_WriteData(0x20);

	Lcd_WriteIndex(0xC0);			//Power control
	Lcd_WriteData(0x23);			//VRH[5:0]

	Lcd_WriteIndex(0xC1);    	//Power control
	Lcd_WriteData(0x10);   		//SAP[2:0];BT[3:0]

	Lcd_WriteIndex(0xC5);    	//VCM control
	Lcd_WriteData(0x3e); 			//瀵规瘮搴﹁皟�??
	Lcd_WriteData(0x28);

	Lcd_WriteIndex(0xC7);    	//VCM control2
	Lcd_WriteData(0x86);  		//--

	Lcd_WriteIndex(0x36);    	// Memory Access Control
#ifdef USE_HORIZONTAL
	Lcd_WriteData(0xE8); 			//C8	   //48 68绔栧�?//28 E8 妯�?
#else
	Lcd_WriteData(0x48);
#endif

	Lcd_WriteIndex(0x3A);
	Lcd_WriteData(0x55);

	Lcd_WriteIndex(0xB1);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x18);

	Lcd_WriteIndex(0xB6);    // Display Function Control
	Lcd_WriteData(0x08);
	Lcd_WriteData(0x82);
	Lcd_WriteData(0x27);

	Lcd_WriteIndex(0xF2);    // 3Gamma Function Disable
	Lcd_WriteData(0x00);

	Lcd_WriteIndex(0x26);    //Gamma curve selected
	Lcd_WriteData(0x01);

	Lcd_WriteIndex(0xE0);    //Set Gamma
	Lcd_WriteData(0x0F);
	Lcd_WriteData(0x31);
	Lcd_WriteData(0x2B);
	Lcd_WriteData(0x0C);
	Lcd_WriteData(0x0E);
	Lcd_WriteData(0x08);
	Lcd_WriteData(0x4E);
	Lcd_WriteData(0xF1);
	Lcd_WriteData(0x37);
	Lcd_WriteData(0x07);
	Lcd_WriteData(0x10);
	Lcd_WriteData(0x03);
	Lcd_WriteData(0x0E);
	Lcd_WriteData(0x09);
	Lcd_WriteData(0x00);

	Lcd_WriteIndex(0XE1);    //Set Gamma
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x0E);
	Lcd_WriteData(0x14);
	Lcd_WriteData(0x03);
	Lcd_WriteData(0x11);
	Lcd_WriteData(0x07);
	Lcd_WriteData(0x31);
	Lcd_WriteData(0xC1);
	Lcd_WriteData(0x48);
	Lcd_WriteData(0x08);
	Lcd_WriteData(0x0F);
	Lcd_WriteData(0x0C);
	Lcd_WriteData(0x31);
	Lcd_WriteData(0x36);
	Lcd_WriteData(0x0F);

	Lcd_WriteIndex(0x11);    //Exit Sleep
	HAL_Delay(120);

	Lcd_WriteIndex(0x29);    //Display on
	Lcd_WriteIndex(0x2c);

}

/*************************************************
鍑芥暟鍚嶏細LCD_Set_XY
鍔熻兘锛氳缃甽cd鏄剧ず璧峰�??
鍏ュ彛鍙傛暟锛歺y鍧愭�?
杩斿洖鍊硷細�??
*************************************************/
void Lcd_SetXY(uint16_t Xpos, uint16_t Ypos)
{
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData_16Bit(Xpos);
	Lcd_WriteIndex(0x2b);
	Lcd_WriteData_16Bit(Ypos);
	Lcd_WriteIndex(0x2c);
}
/*************************************************
鍑芥暟鍚嶏細LCD_Set_Region
鍔熻兘锛氳缃甽cd鏄剧ず鍖哄煙锛屽湪姝ゅ尯鍩熷啓鐐规暟鎹嚜鍔ㄦ崲�??
鍏ュ彛鍙傛暟锛歺y璧风偣鍜�?粓鐐?
杩斿洖鍊硷細�??
*************************************************/
//璁剧疆鏄剧ず绐楀�?
void Lcd_SetRegion(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd)
{
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData_16Bit(xStar);
	Lcd_WriteData_16Bit(xEnd);
	Lcd_WriteIndex(0x2b);
	Lcd_WriteData_16Bit(yStar);
	Lcd_WriteData_16Bit(yEnd);
	Lcd_WriteIndex(0x2c);
}


/*************************************************
鍑芥暟鍚嶏細LCD_DrawPoint
鍔熻兘锛氱敾�??涓�?
鍏ュ彛鍙傛暟锛歺y鍧愭爣鍜岄鑹叉暟鎹?
杩斿洖鍊硷細�??
*************************************************/
void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data)
{
	Lcd_SetXY(x,y);
	Lcd_WriteData_16Bit(Data);
}

/*************************************************
鍑芥暟鍚嶏細Lcd_Clear
鍔熻兘锛氬叏灞忔竻灞忓嚱�??
鍏ュ彛鍙傛暟锛氬～鍏呴鑹睠OLOR
杩斿洖鍊硷細�??
*************************************************/
void Lcd_Clear(uint16_t Color)
{
   int32_t i,m;
   Lcd_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
   for(i=0;i<X_MAX_PIXEL;i++)
    for(m=0;m<Y_MAX_PIXEL;m++)
    {
	  	Lcd_WriteData_16Bit(Color);
    }
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
