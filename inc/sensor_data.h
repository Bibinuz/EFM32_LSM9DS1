/*
 * sensor_data.h
 *
 *  Created on: 15 de may. de 2026
 *      Author: practiques
 */

#ifndef INC_SENSOR_DATA_H_
#define INC_SENSOR_DATA_H_

typedef struct{
	float gyro_x;
	float gyro_y;
	float gyro_z;
}GyroData_Raw;

typedef struct{
	int8_t x;
	int8_t y;
}GyroData;

#endif /* INC_SENSOR_DATA_H_ */
