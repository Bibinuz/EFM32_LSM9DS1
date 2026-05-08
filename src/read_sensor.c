/*
 * read_sensor.c
 *
 *  Created on: 8 de may. de 2026
 *      Author: practiques
 */
#include "read_sensor.h"
#include "bsp_i2c_mutex.h"
#include <stdint.h>


#define GYRO_SENSITIVITY 8.75e-3f

bool read_gyro(GyroData* data) {
	uint8_t buff[6];
	if(!Read_Mutex(0x18, &buff[0])) return false;
	if(!Read_Mutex(0x19, &buff[1])) return false;
	if(!Read_Mutex(0x1A, &buff[2])) return false;
	if(!Read_Mutex(0x1B, &buff[3])) return false;
	if(!Read_Mutex(0x1C, &buff[4])) return false;
	if(!Read_Mutex(0x1D, &buff[5])) return false;

	int16_t x = (int16_t) ((buff[1]<<8) | buff[0]);
	int16_t y = (int16_t) ((buff[3]<<8) | buff[2]);
	int16_t z = (int16_t) ((buff[5]<<8) | buff[4]);
	data->gyro_x = (float)(x * GYRO_SENSITIVITY);
	data->gyro_y = (float)(y * GYRO_SENSITIVITY);
	data->gyro_z = (float)(z * GYRO_SENSITIVITY);
	return true;

}
