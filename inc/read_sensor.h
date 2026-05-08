/*
 * read_sensor.h
 *
 *  Created on: 8 de may. de 2026
 *      Author: practiques
 */

#ifndef INC_READ_SENSOR_H_
#define INC_READ_SENSOR_H_

#include <stdbool.h>

typedef struct{
	float gyro_x;
	float gyro_y;
	float gyro_z;
}GyroData;

bool read_gyro(GyroData* data);

#endif /* INC_READ_SENSOR_H_ */
