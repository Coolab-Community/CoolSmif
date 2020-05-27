#include "MyTask.h"
#include "main.h"
#include "string.h"

extern UART_HandleTypeDef huart1; // Uart Handler defined in "main.h"

osMailQDef(mail, 20, T_MEAS);                    // Define mail queue
osMailQId  mail;
T_MEAS *mptr;

extern uint8_t xrecvdData[1];
uint32_t count=0;
__IO ITStatus UartReady = RESET;

void Uart_Task (const void * argument)
{
	mail = osMailCreate(osMailQ(mail), NULL);
	mptr = osMailAlloc(mail, osWaitForever);       // Allocate memory
	osMailPut(mail, mptr);
	HAL_UART_Transmit(&huart1, (uint8_t*)"here1", 5, HAL_MAX_DELAY);

  while(1)
  {
	  if(UartReady == SET)
	  {
		  if(xrecvdData[0] == '\r')
		  {
		  mptr = osMailAlloc(mail, osWaitForever);       // Allocate memory
		  //mptr->data[count++] = xrecvdData[0];
		  mptr->data[count++]= '\n';
		  mptr->data[count++]= '\n';
		  osMailPut(mail, mptr);
		  //memset (mptr->data, 0, sizeof (mptr->data));
		  osDelay(100);
		  }
		  else
		  {
			 mptr->data[count++] = xrecvdData[0];
			 //HAL_UART_Transmit(&huart1, (uint8_t*)"here3", 5, HAL_MAX_DELAY);
		  }
		  UartReady = RESET;
		  if (count == 125)
		  {
			count = 0;
		  }
	 }
  }
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		UartReady = SET;
}
