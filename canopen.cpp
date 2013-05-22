/*
 * canopen.cpp
 *
 *  Created on: May 1, 2013
 *      Author: cody
 */


#include "canopen.hpp"

RPDO::RPDO(unsigned char node_id, int rpdo_id, unsigned char length, unsigned char * data)
{
	this->node_id = node_id;
	this->msg->Id = node_id | rpdo_id;
	this->msg->Size = length;
	int i;
	for(i = 0; i < length; i++)
	{
		this->msg->Data[i] = data[i];
	}
}

char * RPDO::toString(void)
{
	char * retString =
	return retString;
}

TPDO::TPDO()
{

}
char * TPDO::toString(void)
{
	char * retString;
	// Node ID
	// Payload
	return retString;
}

bool CANOpen::setCanAdapter(VSCAN * canAdapter)
{
	if(canAdapter != NULL)
	{
		can = canAdapter;
		printf("CAN Adapter Connected\n");
		return true;
	}
	else
	{
		printf("WARNING: Specified CAN Adapter not found\n");
		return false;
	}
}

bool CANOpen::sendRPDO(RPDO * rpdo)
{
	//
	can->write(rpdo->msg, rpdo->msg->size, );
	return false;
}

bool CANOpen::sendTPDO(TPDO * tpdo, unsigned char * buffer)
{
	return false;
}
