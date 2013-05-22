/*
 * amc_dpc.cpp
 *
 *  Created on: May 16, 2013
 *      Author: cody
 */


#include "amc_dpc.hpp"

void AMC_DPC::AMC_DPC(CANOpen * newCan, unsigned char newNodeID)
{
	nodeID = newNodeID;
	can = newCan;
}

AMC_DPC::~AMC_DPC()
{

}

bool AMC_DPC::setCurrent(int targetCurrent)
{
	// RPDO 23, 6071:00 COB-521
}

int AMC_DPC::readCurrent()
{

}

bool AMC_DPC::setVelocity(int targetVelocity)
{
	// RPDO 22, 60FF:00, COB511
}

int AMC_DPC::readVelocity()
{

}

bool AMC_DPC::setPosition(int targetPosition)
{
	// RPDO 21 607A::00, COB-501
}

int AMC_DPC::readPosition()
{

}
