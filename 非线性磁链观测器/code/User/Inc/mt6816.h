#ifndef __MT6816_H
#define __MT6816_H
#include <stdbool.h>	
#include <string.h>		
#include <stdlib.h>		
#include <stdio.h>		
#include <spi.h>		
#include <main.h>		
#define M_PI (3.14159265358f)         // Բ����
#define MT6816_SPI_CS_H()	     HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,1) 
#define MT6816_SPI_CS_L()		 HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,0) 
#define MT6816_SPI_Get_HSPI		    (hspi1)
#define MT6816_Mode_SPI		        (0x03)	

typedef struct
{
	int raw;			 // �ű�������ԭʼ����ֵ
	int dir;			 // �ű���������ת����+1 ��ʾ˳ʱ�룬-1 ��ʾ��ʱ��
	int32_t count;		 // �ű������ĵ�ǰ����ֵ����һ�����������������ڵļ���ֵ��
	int32_t count_prev;	 // ��һ�����������ڵļ���ֵ
	int32_t acc_count;	 // �ۼƼ���ֵ�����б����������ڵ��ۻ�����ֵ��
	int32_t delta_count; // �����������ڵ���������ֵ����������������֮��Ĳ�ֵ��

	int32_t offset_lut[128]; // ���ڴű��������Ի��Ĳ��ұ�
	uint32_t offset;

	float mec_angle;  // ��е�Ƕȣ�������������ֵ�������Ի������õ��Ļ�е�Ƕ�ֵ
	float elec_angle; // ��Ƕȣ���Ӧ�ڻ�е�Ƕȵĵ��ת��λ�ã����ݵ���ļ���������õ���

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
