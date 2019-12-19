/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */
uint8_t Confirm_Flag = 0;
uint8_t Menu_Flag = 0;
uint8_t Menu_Index = 1;
uint8_t Func_Flag = 0;
uint8_t Return_Flag = 0;
uint8_t Game1_Up_Flag = 0;
uint8_t Game1_Down_Flag = 0;
uint8_t Game1_Left_Flag = 0;
uint8_t Game1_Right_Flag = 0;
uint8_t PWMControl_Index = 1;

extern uint8_t Menu_Refresh;
extern uint8_t Menu_Index_Refresh;
extern uint8_t Game1_Up_Status;
extern uint8_t Game1_Down_Status;
extern uint8_t Game1_Left_Status;
extern uint8_t Game1_Right_Status;
extern uint8_t Game1_Flag;
extern uint8_t Game1_Refresh;
extern uint8_t Game1_Dead;
extern uint8_t Game1_Restart;
extern uint8_t Game1_Dead_Refresh;
extern uint8_t Game1_Pass;
extern uint8_t Game1_Pass_Refresh;
extern uint8_t Game1_Continue;
extern uint8_t Environment_Flag;
extern uint8_t Environment_Refresh_Flag;
extern uint8_t PWMControl_Flag;
extern uint8_t PWMControl_Refresh_Flag;
extern uint8_t CRR;
extern uint8_t CRR_Red;
extern uint8_t CRR_Green;
extern uint8_t CRR_Blue;
/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, RST_Pin|CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_Pin|LED_HUMI_Pin|LED_TEMP_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, Led_Red_Pin|Led_Yellow_Pin|Led_Blue_Pin|Led_Green_Pin 
                          |Buzzer_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = Menu_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Menu_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  GPIO_InitStruct.Pin = RST_Pin|CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = LED_HUMI_Pin|LED_TEMP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin */
  GPIO_InitStruct.Pin = Return_Pin|LightControl_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = Confirm_Pin|Up_Pin|Left_Pin|Right_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = Led_Red_Pin|Led_Yellow_Pin|Led_Blue_Pin|Led_Green_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = Buzzer_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Buzzer_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = Down_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Down_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	
	if(GPIO_Pin == Confirm_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Confirm_GPIO_Port,Confirm_Pin))
		{
			if(Menu_Flag == 1){
				Func_Flag = 1;
				Menu_Flag = 0;
				Menu_Refresh = 0;
				Menu_Index_Refresh = 0;
			}
			if(Func_Flag&&Game1_Flag&&Game1_Dead){
				Game1_Restart = 1;
				Game1_Dead_Refresh = 0;
			}
			if(Func_Flag&&Game1_Flag&&Game1_Pass){
				Game1_Continue = 1;
				Game1_Pass_Refresh = 0;
			}
		}
	}
	
	
	else if(GPIO_Pin == Menu_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Menu_GPIO_Port,Menu_Pin))
		{
			Menu_Flag = 1;
			Menu_Index = 1;
			Menu_Refresh = 0;
			Menu_Index_Refresh = 0;
			Func_Flag = 0;
			Game1_Flag = 0;
			Game1_Dead = 0;
			Game1_Pass = 0;
			Game1_Restart = 0;
			Game1_Refresh = 0;	   //主界面刷新标志复�?
			Game1_Dead_Refresh = 0;//死亡界面刷新标志复位
			Game1_Pass_Refresh = 0;//死亡界面刷新标志复位
			Environment_Flag = 0;
			Environment_Refresh_Flag = 0;
			PWMControl_Flag = 0;
			PWMControl_Refresh_Flag = 0;
			PWMControl_Index = 1;
		}
	}	
	
	
	else if(GPIO_Pin == Up_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Up_GPIO_Port,Up_Pin))
		{
			if(Menu_Flag == 1){
				Menu_Index_Refresh = 0;
				if(Menu_Index <= 1){
					Menu_Index = 3;
				}
				else{
					Menu_Index--;
				}
			}
			if(Func_Flag && Game1_Flag && !Game1_Dead && !Game1_Pass && !Game1_Down_Flag && !Game1_Left_Flag && !Game1_Right_Flag && !Game1_Down_Status){
				Game1_Up_Flag = 1;
				Game1_Down_Status = Game1_Left_Status = Game1_Right_Status = 0;
			}
			if(PWMControl_Flag && Func_Flag){
				if(PWMControl_Index == 1 && CRR<10)
					CRR++;
				else if(PWMControl_Index == 2 && CRR_Red<10)
					CRR_Red++;
				else if(PWMControl_Index == 3 && CRR_Green<10)
					CRR_Green++;
				else if(PWMControl_Index == 4 && CRR_Blue<10)
					CRR_Blue++;
			}
		}
	}	
	
	
	else if(GPIO_Pin == Down_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Down_GPIO_Port,Down_Pin))
		{
			if(Menu_Flag == 1){
				Menu_Index_Refresh = 0;
				if(Menu_Index >= 3){
					Menu_Index = 1;
				}
				else{
				Menu_Index ++;
				}
			}
			if(Func_Flag && Game1_Flag && !Game1_Dead && !Game1_Pass && !Game1_Up_Flag && !Game1_Left_Flag && !Game1_Right_Flag&& !Game1_Up_Status){
				Game1_Down_Flag = 1;
				Game1_Up_Status = Game1_Left_Status = Game1_Right_Status = 0;
			}
			if(PWMControl_Flag && Func_Flag ){
				if(PWMControl_Index == 1 && CRR>0)
					CRR--;
				else if(PWMControl_Index == 2 && CRR_Red>0)
					CRR_Red--;
				else if(PWMControl_Index == 3 && CRR_Green>0)
					CRR_Green--;
				else if(PWMControl_Index == 4 && CRR_Blue>0)
					CRR_Blue--;
			}
		}
	}	
	
	
	else if(GPIO_Pin == Left_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Left_GPIO_Port,Left_Pin))
		{
			if(Func_Flag && Game1_Flag && !Game1_Dead && !Game1_Pass && !Game1_Up_Flag && !Game1_Down_Flag && !Game1_Right_Flag && !Game1_Right_Status){
				Game1_Left_Flag = 1;
				Game1_Down_Status =Game1_Up_Status = Game1_Right_Status = 0;
			}
			if(PWMControl_Flag && Func_Flag){
				if(PWMControl_Index <= 1){
					PWMControl_Index = 4;
				}
				else{
				PWMControl_Index--;
				}
			}
		}
	}	
	
	
	else if(GPIO_Pin == Right_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Right_GPIO_Port,Right_Pin))
		{
			if(Func_Flag && Game1_Flag && !Game1_Dead && !Game1_Pass && !Game1_Up_Flag && !Game1_Down_Flag && !Game1_Left_Flag && !Game1_Left_Status){
				Game1_Right_Flag = 1;
				Game1_Down_Status = Game1_Left_Status = Game1_Up_Status = 0;
			}
			if(PWMControl_Flag && Func_Flag){
				if(PWMControl_Index >= 4){
					PWMControl_Index = 1;
				}
				else{
				PWMControl_Index++;
				}
			}
		}
	}	
	
	
	else if(GPIO_Pin == LightControl_Pin){
		delay_ms(Elimination_times);
    if(HAL_GPIO_ReadPin(LightControl_GPIO_Port,LightControl_Pin))
		HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
	}	
	
	
	else if(GPIO_Pin == Return_Pin){
		delay_ms(Elimination_times);
		if(HAL_GPIO_ReadPin(Return_GPIO_Port,Return_Pin))
		{
			if(Func_Flag&&Game1_Flag&&Game1_Dead){
				Menu_Flag = 1;
				Menu_Index = 1;
				Func_Flag = 0;
				Game1_Flag = 0;
				Game1_Dead = 0;
				Game1_Pass = 0;
				Game1_Restart = 0;
				Game1_Refresh = 0;	   //主界面刷新标志复�?
				Game1_Dead_Refresh = 0;//死亡界面刷新标志复位
			}
				if(Func_Flag&&Game1_Flag&&Game1_Pass){
				Menu_Flag = 1;
				Menu_Index = 1;
				Func_Flag = 0;
				Game1_Flag = 0;
				Game1_Dead = 0;
				Game1_Pass = 0;
				Game1_Restart = 0;
				Game1_Continue = 0;
				Game1_Refresh = 0;	   //主界面刷新标志复�?
				Game1_Dead_Refresh = 0;//死亡界面刷新标志复位
				Game1_Pass_Refresh = 0;
			}
				if(Func_Flag&&Environment_Flag){
					Menu_Flag = 1;
					Menu_Index = 1;					
					Func_Flag = 0;
					Environment_Flag = 0;
					Environment_Refresh_Flag = 0;
				}
				if(Func_Flag&&PWMControl_Flag){
					Menu_Flag = 1;
					Menu_Index = 1;					
					Func_Flag = 0;
					PWMControl_Flag = 0;
					PWMControl_Refresh_Flag = 0;
					PWMControl_Index = 1;
				}

			}
	}	
}

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
