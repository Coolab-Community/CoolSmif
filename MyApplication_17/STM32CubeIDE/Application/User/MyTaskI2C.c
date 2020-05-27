#include "MyTaskI2C.h"
#include "MyTask.h"
#include "main.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;	// I2C Handler defined in "main.h"
extern UART_HandleTypeDef huart1; // Uart Handler defined in "main.h"

extern uint8_t storeData[3]; //Buffer for store the error code
extern T_MEAS *mptr;

/* Buffer used for transmission */
uint8_t aTxBuffer[] = " ****I2C_TwoBoards communication based on DMA****  ****I2C_TwoBoards communication based on DMA****  ****I2C_TwoBoards communication based on DMA**** ";

/* Buffer used for reception */
uint8_t aRxBuffer[RXBUFFERSIZE];


void I2C_Task (const void * argument)
{
	while(1)
	{

		/* The board receives the message and sends it back */

		  /*##-2- Put I2C peripheral in reception process ###########################*/
		  if(HAL_I2C_Slave_Receive_DMA(&hi2c1, (uint8_t *)aRxBuffer, RXBUFFERSIZE) != HAL_OK)
		  {
		    /* Transfer error in reception process */
		    Error_Handler();
		  }

		  /*##-3- Wait for the end of the transfer ###################################*/
		  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
		  {
		  }

		  /*##-4- Start the transmission process #####################################*/
		  if(HAL_I2C_Slave_Transmit_DMA(&hi2c1, (uint8_t*)storeData, 3)!= HAL_OK)
		  //if(HAL_I2C_Slave_Transmit_DMA(&hi2c1, (uint8_t*)aTxBuffer, TXBUFFERSIZE)!= HAL_OK)
		  {
		    /* Transfer error in transmission process */
		    Error_Handler();
		  }


		  /*##-5- Wait for the end of the transfer ###################################*/
		  while (HAL_I2C_GetState(&hi2c1) != HAL_I2C_STATE_READY)
		  {
		  }

	}
}

//void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//	HAL_UART_Transmit(&huart1, (uint8_t *)"Dude", 4, HAL_MAX_DELAY);
//}
