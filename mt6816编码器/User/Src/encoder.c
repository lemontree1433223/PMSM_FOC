#include "encoder.h"
#include "main.h"
#include "math.h"
#include "spi.h"

enc_para_t mt6816;

#define M_PI (3.14159265358f)         // 圆周率
#define M_2PI (6.28318530716f)        // 2倍圆周率

void encoder_init(enc_para_t *encoder)
{
	encoder->dir = -1;
	encoder->raw = 0;
	encoder->count = 0;
	encoder->count_prev = 0;
	encoder->acc_count = 0;
	encoder->delta_count = 0;
	encoder->offset = 45800;
}

uint16_t encoder_read_raw(void)
{
	uint16_t	sample_data;	
			
	bool		no_mag_flag;	
	bool		pc_flag;	
	uint16_t	angle;
	
	uint16_t data_t[2];
	uint16_t data_r[2];
	uint8_t h_count;
	data_t[0] = (0x80 | 0x03) << 8;
	data_t[1] = (0x80 | 0x04) << 8;
	for(uint8_t i=0; i<3; i++){
		//读取SPI数据
		cs_down;
		HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&data_t[0], (uint8_t*)&data_r[0], 1, HAL_MAX_DELAY);
		cs_up;
		cs_down;
		HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)&data_t[1], (uint8_t*)&data_r[1], 1, HAL_MAX_DELAY);
		cs_up;
		sample_data = ((data_r[0] & 0x00FF) << 8) | (data_r[1] & 0x00FF);
		//奇偶校验
		h_count = 0;
		for(uint8_t j=0; j<16; j++){
			if(sample_data & (0x0001 << j))
				h_count++;
		}
		if(h_count & 0x01){
			pc_flag = false;
		}
		else{
			pc_flag = true;
			break;
		}
	}
	if(pc_flag){
		angle = sample_data >> 2;
		no_mag_flag = (bool)(sample_data & (0x0001 << 1));
	}

	return angle;
}

void encoder_loop(enc_para_t *encoder)
{
	
	int raw = encoder_read_raw();
	
	encoder->mec_angle = normalize_angle(M_2PI * raw/16348 );
	encoder->elec_angle = normalize_angle(7 * encoder->mec_angle - encoder->elec_angle_offset);
}

// 归一化角度到 [0,2PI]
float normalize_angle(float angle)
{
	float a = fmod(angle, 2 * M_PI); // 取余运算可以用于归一化
	return a >= 0 ? a : (a + 2 * M_PI);
}


static float pwm_time = 0.0000625f;
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
//		mt6816.speed_filt += (speed - mt6816.speed) * temp1;
		mt6816.angule_speed = mt6816.speed * 7;

		mt6816.cnt = 0;
		mt6816.last_angle = mt6816.mec_angle;
	}

	return mt6816.speed;
}


