#ifndef __MT6816_H
#define __MT6816_H
#include <stdbool.h>	
#include <string.h>		
#include <stdlib.h>		
#include <stdio.h>		
#include <spi.h>		
#include <main.h>		
#define M_PI (3.14159265358f)         // 圆周率
#define MT6816_SPI_CS_H()	     HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,1) 
#define MT6816_SPI_CS_L()		 HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,0) 
#define MT6816_SPI_Get_HSPI		    (hspi1)
#define MT6816_Mode_SPI		        (0x03)	

typedef struct
{
	int raw;			 // 磁编码器的原始计数值
	int dir;			 // 磁编码器的旋转方向，+1 表示顺时针，-1 表示逆时针
	int32_t count;		 // 磁编码器的当前计数值（在一个完整编码器周期内的计数值）
	int32_t count_prev;	 // 上一个编码器周期的计数值
	int32_t acc_count;	 // 累计计数值（所有编码器周期内的累积计数值）
	int32_t delta_count; // 编码器周期内的增量计数值（两个编码器周期之间的差值）

	int32_t offset_lut[128]; // 用于磁编码器线性化的查找表
	uint32_t offset;

	float mec_angle;  // 机械角度，即编码器计数值经过线性化处理后得到的机械角度值
	float elec_angle; // 电角度，对应于机械角度的电机转子位置（根据电机的极对数计算得到）

	uint8_t cnt;
	float speed;
	float speed_filt;
	float angule_speed;
	float last_angle;

} enc_para_t;

typedef struct{
	uint16_t	sample_data;	
	uint16_t	angle;				
	bool		no_mag_flag;	
	bool		pc_flag;			
}MT6816_SPI_Signal_Typedef;

void REIN_MT6816_SPI_Signal_Init(void);		
void RINE_MT6816_SPI_Get_AngleData(void);	

typedef struct{
	uint16_t	angle_data;			
	uint16_t	rectify_angle;		
	bool			rectify_valid;		
}MT6816_Typedef;

extern MT6816_Typedef	mt6816_t;
extern enc_para_t mt6816;
float REIN_MT6816_Get_AngleData(void);
float get_speed_M(uint8_t N);


#endif
