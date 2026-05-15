/*
 * usb.h
 *
 *  Created on: 15 de may. de 2026
 *      Author: practiques
 */

#ifndef INC_USB_H_
#define INC_USB_H_

#include "sensor_data.h"
#include <stdbool.h>

bool clean_data(GyroData_Raw* raw_data, GyroData* data);


#endif /* INC_USB_H_ */
