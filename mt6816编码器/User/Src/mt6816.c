#include "mt6816.h"
#include "stdio.h"

MT6816_SPI_Signal_Typedef	mt6816_spi;

#define M_PI (3.14159265358f)         // 圆周率
#define M_2PI (6.28318530716f)        // 2倍圆周率


enc_para_t mt6816;

void REIN_MT6816_SPI_Signal_Init(void)
{
	mt6816_spi.sample_data = 0;
	mt6816_spi.angle = 0;
}

void RINE_MT6816_SPI_Get_AngleData(void)
{
	uint16_t data_t[2];
	uint16_t data_r[2];
	uint8_t h_count;
	data_t[0] = (0x80 | 0x03) << 8;
	data_t[1] = (0x80 | 0x04) << 8;
	for(uint8_t i=0; i<3; i++){
		//读取SPI数据
		MT6816_SPI_CS_L();
		HAL_SPI_TransmitReceive(&MT6816_SPI_Get_HSPI, (uint8_t*)&data_t[0], (uint8_t*)&data_r[0], 1, HAL_MAX_DELAY);
		MT6816_SPI_CS_H();
		MT6816_SPI_CS_L();
		HAL_SPI_TransmitReceive(&MT6816_SPI_Get_HSPI, (uint8_t*)&data_t[1], (uint8_t*)&data_r[1], 1, HAL_MAX_DELAY);
		MT6816_SPI_CS_H();
		mt6816_spi.sample_data = ((data_r[0] & 0x00FF) << 8) | (data_r[1] & 0x00FF);
		//奇偶校验
		h_count = 0;
		for(uint8_t j=0; j<16; j++){
			if(mt6816_spi.sample_data & (0x0001 << j))
				h_count++;
		}
		if(h_count & 0x01){
			mt6816_spi.pc_flag = false;
		}
		else{
			mt6816_spi.pc_flag = true;
			break;
		}
	}
	if(mt6816_spi.pc_flag){
		mt6816_spi.angle = mt6816_spi.sample_data >> 2;
		mt6816_spi.no_mag_flag = (bool)(mt6816_spi.sample_data & (0x0001 << 1));
	}
}

MT6816_Typedef	mt6816_t;

float REIN_MT6816_Get_AngleData()
{
	RINE_MT6816_SPI_Get_AngleData();
	mt6816_t.angle_data = mt6816_spi.angle;   
	return mt6816_t.angle_data;
}

static float pwm_time = 0.0000625f;//16K
float temp1 = 0.1f;
float get_speed_M(uint8_t N)
{
	if (++mt6816.cnt >= N && N != 0)
	{
		float speed;

		speed = mt6816.mec_angle - mt6816.last_angle;
		if (speed > M_PI)
			speed -= M_2PI;
		else if (speed < (-1) * M_PI)
			speed += M_2PI;

		speed = speed / M_2PI / (pwm_time * N) * 60.0f / 9.55f;
		
		mt6816.speed = speed;
//		ma702_encoder.speed  = (float)speed;
		mt6816.speed_filt += (speed - mt6816.speed) * temp1;
		mt6816.angule_speed = mt6816.speed * 7;

		mt6816.cnt = 0;
		mt6816.last_angle = mt6816.mec_angle;
	}

	return mt6816.speed;
}