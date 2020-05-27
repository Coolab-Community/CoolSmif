#include "MyTask.h"
#include "MyTaskI2C.h"
#include "main.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;	// I2C Handler defined in "main.h"
extern UART_HandleTypeDef huart1; // Uart Handler defined in "main.h"

osMailQDef(mail, 20, T_MEAS);    // Define mail queue
osMailQId  mail;
T_MEAS *mptr;

extern uint8_t xrecvdData[1];

uint8_t tempData[3]; // temp buffer
uint8_t storeData[3]; //Buffer for store the error code

uint32_t count=0;
uint16_t newLine=0;
__IO ITStatus UartReady = RESET;

void Uart_Task (const void * argument)
{
	int i;

	// usart mail queue
	mail = osMailCreate(osMailQ(mail), NULL);
	mptr = osMailAlloc(mail, osWaitForever);	// Allocate memory
	osMailPut(mail, mptr);

	while(1)
	{

		if(UartReady == SET)
		{
			if(xrecvdData[0] == '\r')
			{
				mptr = osMailAlloc(mail, osWaitForever);       // Allocate memory
				mptr->data[count++]= '\n';
				osMailPut(mail, mptr);
				newLine++;
				tempData[0] = mptr->data[count-18];
				tempData[1] = mptr->data[count-19];
				tempData[2] = mptr->data[count-20];

				for(i=0; i<3; i++)
				{
					if(tempData[i] == '\n')
					{
						switch (i)
						{
							case 0:
								storeData[0] = mptr->data[count-7];
								//HAL_UART_Transmit(&huart1, (uint8_t *)storeData, 1, HAL_MAX_DELAY);
						        break;
						    case 1:
						    	storeData[0] = mptr->data[count-8];
						    	storeData[1] = mptr->data[count-7];
						    	//HAL_UART_Transmit(&huart1, (uint8_t *)storeData, 2, HAL_MAX_DELAY);
						        break;
						    case 2:
						    	storeData[0] = mptr->data[count-9];
						    	storeData[1] = mptr->data[count-8];
						    	storeData[2] = mptr->data[count-7];
						    	//HAL_UART_Transmit(&huart1, (uint8_t *)storeData, 3, HAL_MAX_DELAY);
						        break;
						      default:
						    break;
						}
						tempData[i] = 'n';
					}
				}
			}
			else
			{
				mptr->data[count++] = xrecvdData[0];
			}
			//here add managment of array size if count > XX the error code string can be cut
			if (newLine == 5)
			{
				mptr->data[0]= '\n';
				count = 1;
				newLine = 0;
			}
			UartReady = RESET;
		}
	}
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		UartReady = SET;
}


