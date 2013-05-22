/*
 * amc_dpc.hpp
 *
 *  Created on: May 16, 2013
 *      Author: cody
 */

#ifndef AMC_DPC_HPP_
#define AMC_DPC_HPP_

#include "canopen.hpp"

enum MotorMode
{
	PROFILE_POSITION = 0,
	PROFILE_VELOCITY = 1,
	PROFILE_TORQUE = 2,
	HOMING = 3,
	INTERPOLATED_POSITION = 4,
	CYCLICAL_SYNCHRONOUS_POSITION = 5,
	CYCLICAL_SYNCHRONOUS_VELOCITY = 6,
	CYCLICAL_SYNCHRONOUS_TORQUE = 7,
	CUSTOM = 8
};

class AMC_DPC
{
public:
	bool bridgeEnable(bool bridgeState);
	bool setMotorMode(int motorMode)
	bool setCurrent(int targetCurrent);
	int readCurrent();
	bool setVelocity(int targetVelocity);
	int readVelocity();
	bool setPosition(int targetPosition);
	int readPosition();
private:
	unsigned char nodeID;
	CANOpen * can;
	int actualPosition;
	int targPosition; // Target Position
	int actualVelocity;
	int targVelocity;
	int actualCurrent;
	int targCurrent;
};


#endif /* AMC_DPC_HPP_ */
