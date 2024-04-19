#ifndef __ENCODER_H__
#define __ENCODER_H__
#include <stdbool.h>	
#include <string.h>		
#include <stdlib.h>		
#include <stdio.h>		
#include <spi.h>		
#include <main.h>	


#define cs_down HAL_GPIO_WritePin(SPI_CS_GPIO_Port,SPI_CS_Pin,GPIO_PIN_RESET);
#define cs_up HAL_GPIO_WritePin(SPI_CS_GPIO_Port,SPI_CS_Pin,GPIO_PIN_SET);

#define ENCODER_CPR			 262144u
#define ENCODER_CPR_F		(262144.0f)
#define ENCODER_CPR_DIV	(ENCODER_CPR>>1)



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
	float elec_angle_offset; // ��Ƕȣ���Ӧ�ڻ�е�Ƕȵĵ��ת��λ�ã����ݵ���ļ���������õ���
	uint8_t offset_cnt;
	uint8_t cnt;
	float speed;
	float speed_filt;
	float angule_speed;
	float last_angle;

} enc_para_t;

extern enc_para_t mt6816;

void encoder_init(enc_para_t *encoder);
uint16_t encoder_read_raw(void);
void encoder_loop(enc_para_t *encoder);
float normalize_angle(float angle);
float get_speed_M(uint8_t N);

#endif /* __ENCODER_H__ */
