#include "FreeRTOS.h"
#include "semphr.h"

#include "bsp_i2c_mutex.h"
#include <stdio.h>
#include <stdbool.h>


SemaphoreHandle_t mutex;

void Init_Mutex() {
	mutex = xSemaphoreCreateMutex();
}

bool Write_Mutex(uint8_t addr, uint8_t reg, uint8_t data) {
	if (mutex != NULL) {
		xSemaphoreTake(mutex, portMAX_DELAY);
		BSP_I2C_Init(addr);
		BSP_I2C_WriteRegister(reg, data);
		xSemaphoreGive(mutex);
		return true;
	}
	return false;
}

bool Read_Mutex(uint8_t addr, uint8_t reg, uint8_t *val) {
	if (mutex != NULL) {
		xSemaphoreTake(mutex, portMAX_DELAY);
		BSP_I2C_Init(addr);
		BSP_I2C_ReadRegister(reg, val);
		xSemaphoreGive(mutex);
		return true;
	}
	return false;
}
