/*
 * can_test.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: cody
 */


#include "can_test.hpp"

int main(int argc, char ** argv)
{
	VSCAN can;
	printf("Attempting to open CAN device on %s\n", argv[1]);
	can.open(argv[1],2); // Set for self reception mode
	int status = can.setSpeed("1M");
	if(status == 0)
	{
		printf("CAN Device Opened on %s\n", argv[1]);
		DWORD written;
		VSCAN_MSG msg;
		msg.Id = 0; //0x600 | 0x2;
		msg.Size = 4;
		msg.Flags = VSCAN_FLAGS_STANDARD;
		msg.Data[0] = 0xAA;
		msg.Data[1] = 0xFF;
		msg.Data[2] = 0x00;
		msg.Data[3] = 0x66;
		can.write(&msg, 4, &written);
		while(written < 4);
		can.close();

	}
	else
	{
		printf("CAN Device Failed to Open\n");
	}
	return 0;
}
