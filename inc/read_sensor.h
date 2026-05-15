/*
 * read_sensor.h
 *
 *  Created on: 8 de may. de 2026
 *      Author: practiques
 */

#ifndef INC_READ_SENSOR_H_
#define INC_READ_SENSOR_H_

#include <stdbool.h>
#include "sensor_data.h"

bool sensor_gyro_init();

bool read_gyro(GyroData_Raw* data);

#endif /* INC_READ_SENSOR_H_ */
