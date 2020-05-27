#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "string.h"

extern osMailQId (mail);   // Declare external handler for  Mailq
extern UART_HandleTypeDef huart1;


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	osEvent event = osMailGet(mail, 10);        // wait for mail
	if (event.status == osEventMail)
	{
		T_MEAS *received_Value = (T_MEAS *)event.value.p;
		strcpy(currentLog.data,received_Value->data);

	    modelListener->notifyLogChanged();
	    osMailFree(mail, received_Value);  // Free the memory location of the Mailq
	}
}
