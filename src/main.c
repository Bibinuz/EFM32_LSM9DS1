
#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "croutine.h"

#include "em_chip.h"
#include "bsp.h"
#include "bsp_trace.h"

#include "bsp_i2c_mutex.h"
#include "read_sensor.h"


#define STACK_SIZE_FOR_TASK    (configMINIMAL_STACK_SIZE + 10)
#define TASK_PRIORITY          (tskIDLE_PRIORITY + 1)
#define LSM9DS1_AG_ADDR 	   0xD7
/***************************************************************************//**
 * @brief Simple task which is blinking led
 * @param *pParameters pointer to parameters passed to the function
 ******************************************************************************/
static void LedBlink(void *pParameters)
{
  (void) pParameters;
  const portTickType delay = pdMS_TO_TICKS(500);

  for (;; ) {
    BSP_LedToggle(1);
    printf("Task 1\n");
    vTaskDelay(delay);
  }
}

static void PrintGyro(void *pParameters)
{
  (void) pParameters;
  const portTickType delay = pdMS_TO_TICKS(500);
  GyroData data;

  if(I2C_Test())
	  printf("Sensor works!\n");
  else
	  printf("Sensor worksn't!\n");


  for (;; ) {
	if(!read_gyro(&data)) {
		printf("Couldn't read Gyro\n");
	}
	else{
		printf("X: %f, Y: %f, Z:%f\n", data.gyro_x, data.gyro_y, data.gyro_z);
	}
    vTaskDelay(delay);
  }
}

/***************************************************************************//**
 * @brief  Main function
 ******************************************************************************/
int main(void)
{
  /* Chip errata */
  CHIP_Init();
  /* If first word of user data page is non-zero, enable Energy Profiler trace */
  BSP_TraceProfilerSetup();

  /* Initialize LED driver */
  BSP_LedsInit();
  Init_Mutex(LSM9DS1_AG_ADDR);
  /* Setting state of leds*/
  BSP_LedSet(0);
  BSP_LedSet(1);
  /*Create two task for blinking leds*/
  //xTaskCreate(LedBlink, (const char *) "LedBlink1", STACK_SIZE_FOR_TASK, NULL, TASK_PRIORITY, NULL);
  printf("Starting Gyro read\n");
  xTaskCreate(PrintGyro, (const char *) "PrintGyro1", STACK_SIZE_FOR_TASK, NULL, TASK_PRIORITY, NULL);
  /*Start FreeRTOS Scheduler*/
  vTaskStartScheduler();

  return 0;
}
