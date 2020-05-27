#include "main.h" 
#include "stm32f7xx_hal.h"
#include "cmsis_os.h"

void Uart_Task (void const * argument);

typedef struct {                                 // Mail object structure
  float    voltage;                              // AD result of measured voltage
  float    current;                              // AD result of measured current
  char      data[150];                              // A counter value
} T_MEAS;
