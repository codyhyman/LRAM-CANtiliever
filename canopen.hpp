/*
 * canopen.hpp
 *
 *  Created on: May 1, 2013
 *      Author: cody
 */

#ifndef CANOPEN_HPP_
#define CANOPEN_HPP_

#include "vs_can_api.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COB_BASE 0x0600
#define MSG_EN_bm 1<<31
#define RTR_bm 1<<30
#define COB_ID_bm 0b8FF

class RPDO
{
public:
	RPDO(unsigned char node_id, int rpdo, unsigned char length, unsigned char * data);
	~RPDO();
	char * toString(void);
private:
	VSCAN_MSG * msg;
	unsigned char node_id;
	unsigned short length;

};

class TPDO
{
public:
	TPDO();
	~TPDO();
	char * toString(void);
private:
	VSCAN_MSG * msg;
	unsigned char node_id;
	unsigned short length;
};

class CANOpen
{
public:
	bool sendRPDO(RPDO * msg);
	bool sendTPDO(TPDO * msg, unsigned char * rx_buffer);
	bool sendNMT();
	bool setCanAdapter(VSCAN * canAdapter);
private:
	VSCAN * can;
};

#endif /* CANOPEN_HPP_ */
