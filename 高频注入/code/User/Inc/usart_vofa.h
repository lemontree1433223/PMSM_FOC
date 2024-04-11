#ifndef __USART_VOFA_H
#define __USART_VOFA_H
#include "usart.h"
#define byte0(dw_temp)     (*(char*)(&dw_temp))
#define byte1(dw_temp)     (*((char*)(&dw_temp) + 1))
#define byte2(dw_temp)     (*((char*)(&dw_temp) + 2))
#define byte3(dw_temp)     (*((char*)(&dw_temp) + 3))



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void vofa_demo(void);
void vofa_start(void);
void vofa_sendframetail(void);
void vofa_send_data(uint8_t num, float data);
#endif
