#pragma once

#include "bsp_i2c.h"

#include <stdbool.h>


void Init_Mutex(uint8_t addr);

bool Write_Mutex(uint8_t reg, uint8_t data);

bool Read_Mutex(uint8_t reg, uint8_t *val);
