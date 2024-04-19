#include "usart_vofa.h"
#include <stdio.h>
#include <string.h>
#include "motor_control.h"
#include "usbd_cdc_if.h"

#define RXBUFFERSIZE  256   
char RxBuffer[RXBUFFERSIZE];  

#define MAX_BUFFER_SIZE 1024
uint8_t send_buf[MAX_BUFFER_SIZE];

uint16_t cnt = 0;
void vofa_sendframetail(void);
void vofa_send_data(uint8_t num, float data);

	
uint8_t aRxBuffer;			   
uint8_t Uart1_Rx_Cnt = 0;	

int fputc(int ch, FILE *f)
{
 while ((USART3->ISR & 0X40) == 0); 
 USART3->TDR = (uint8_t)ch; 
 return ch;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    UNUSED(huart);
	if(Uart1_Rx_Cnt >= 255)
	{
		Uart1_Rx_Cnt = 0;
		memset(RxBuffer,0x00,sizeof(RxBuffer));
		HAL_UART_Transmit(&huart3, (uint8_t *)"????", 10,0xFFFF); 	        
	}
	else
	{
		RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer;
		if(RxBuffer[Uart1_Rx_Cnt-1]==0x0A)
		{
			if(RxBuffer[0] == 0x4F)
			{
				if(RxBuffer[Uart1_Rx_Cnt-2] == 0x30)
				{
//					rtU.MotorSwitch = 0;
					Motor_stop();
				}
				else
				{
//					rtU.MotorSwitch = 1;
					Motor_start();
				}
			}
		if(RxBuffer[0]==0x73)
		{
			if(Uart1_Rx_Cnt - 7 == 3)
			{
//				rtU.Wm_ref = (RxBuffer[6] - 48) * 100 + (RxBuffer[7] - 48) * 10 + (RxBuffer[8] - 48);
			}
			else
			{
//				rtU.Wm_ref = (RxBuffer[6] - 48) * 1000 + (RxBuffer[7] - 48) * 100 + (RxBuffer[8] - 48) * 10 + (RxBuffer[9] - 48);
			}
		}
			
			Uart1_Rx_Cnt = 0;
			memset(RxBuffer,0x00,sizeof(RxBuffer)); //????
		}
	}	
//	HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);   //???????
}


/**
***********************************************************************
* @brief:      vofa_start(void)
* @param:		   void
* @retval:     void
* @details:    发送数据给上位机
***********************************************************************
**/
void vofa_start(void)
{
//	vofa_demo();		// demo示例
	
	vofa_send_data(0, 0.5);
	vofa_send_data(1, 0.6);
	vofa_send_data(2, 0.7);
//	vofa_send_data(3, foc.i_d);
//	vofa_send_data(4, foc.i_q);
//	vofa_send_data(5, mc.id_set);
//	vofa_send_data(6, mc.iq_set);
//	vofa_send_data(7, foc.theta);
//	vofa_send_data(8, mt6825.elec_angle);
	
//	vofa_send_data(9, ma702_encoder.raw);
//	
	
	vofa_sendframetail();
}

/**
***********************************************************************
* @brief:      vofa_transmit(uint8_t* buf, uint16_t len)
* @param:		   void
* @retval:     void
* @details:    修改通信工具，USART或者USB
***********************************************************************
**/
void vofa_transmit(uint8_t* buf, uint16_t len)
{
	HAL_UART_Transmit_DMA(&huart3, (uint8_t *)buf, len);
//	HAL_UART_Transmit(&huart3, (uint8_t *)buf, len,10);
//	CDC_Transmit_FS((uint8_t *)buf, len);
}
/**
***********************************************************************
* @brief:      vofa_send_data(float data)
* @param[in]:  num: 数据编号 data: 数据 
* @retval:     void
* @details:    将浮点数据拆分成单字节
***********************************************************************
**/
void vofa_send_data(uint8_t num, float data) 
{
	send_buf[cnt++] = byte0(data);
	send_buf[cnt++] = byte1(data);
	send_buf[cnt++] = byte2(data);
	send_buf[cnt++] = byte3(data);
}
/**
***********************************************************************
* @brief      vofa_sendframetail(void)
* @param      NULL 
* @retval     void
* @details:   给数据包发送帧尾
***********************************************************************
**/
void vofa_sendframetail(void) 
{
	send_buf[cnt++] = 0x00;
	send_buf[cnt++] = 0x00;
	send_buf[cnt++] = 0x80;
	send_buf[cnt++] = 0x7f;
	
	/* 将数据和帧尾打包发送 */
	vofa_transmit((uint8_t *)send_buf, cnt);
	cnt = 0;// 每次发送完帧尾都需要清零
}
/**
***********************************************************************
* @brief      vofa_demo(void)
* @param      NULL 
* @retval     void
* @details:   demo示例
***********************************************************************
**/
void vofa_demo(void) 
{
	static float scnt = 0.0f;

	scnt += 0.01f;

	if(scnt >= 360.0f)
		scnt = 0.0f;

	float v1 = scnt;
	float v2 = sin((double)scnt / 180 * 3.14159) * 180 + 180;
	float v3 = sin((double)(scnt + 120) / 180 * 3.14159) * 180 + 180;
	float v4 = sin((double)(scnt + 240) / 180 * 3.14159) * 180 + 180;

	// Call the function to store the data in the buffer
	vofa_send_data(0, v1);
	vofa_send_data(1, v2);
	vofa_send_data(2, v3);
	vofa_send_data(3, v4);

	// Call the function to send the frame tail
	vofa_sendframetail();
}

//void USB_Status_Init(void)
//{
//    GPIO_InitTypeDef GPIO_InitStruct = {0};
// 
//    /* GPIO Ports Clock Enable */
//    __HAL_RCC_GPIOA_CLK_ENABLE();
// 
//    /*Configure GPIO pin Output Level */
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11 | GPIO_PIN_12, GPIO_PIN_RESET);
// 
//    /*Configure GPIO pin : W25Q256_CS_Pin */
//    GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
// 
//    //假如不行的话，下面的延时加长即可。
//    HAL_Delay(10);
//}
