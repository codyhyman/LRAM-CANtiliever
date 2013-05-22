/*
 * vs_can_api.cpp
 *
 *  Created on: Apr 30, 2013
 *      Author: cody
 */


#include "vs_can_api.hpp"


	VSCAN_HANDLE VSCAN::open(char *port, unsigned long mode)
	{
		handle = VSCAN_Open(port, mode);
		return handle;
	}

	VSCAN_STATUS VSCAN::close(void)
	{
		return VSCAN_Close(handle);
	}

	VSCAN_STATUS VSCAN::ioctl(unsigned long ioctl, void *param)
	{
		return VSCAN_Ioctl(handle,ioctl, param);
	}

	VSCAN_STATUS VSCAN::flush(void)
	{
		return VSCAN_Flush(handle);
	}

	VSCAN_STATUS VSCAN::write(VSCAN_MSG *buf, unsigned long size, unsigned long *written)
	{
		return VSCAN_Write(handle, buf, size, written);
	}

	VSCAN_STATUS VSCAN::read(VSCAN_MSG *buf, unsigned long size, unsigned long *read)
	{
		return VSCAN_Read(handle, buf, size, read);
	}

	VSCAN_STATUS VSCAN::setRcvEvent(sem_t *event)
	{
		return VSCAN_SetRcvEvent(handle, event);
	}

	VSCAN_STATUS VSCAN::setSpeed(char * speed)
	{
		void * speed_ptr;
		if(strcmp(speed, "20k"))
			speed_ptr = VSCAN_SPEED_20K;
		else if(strcmp(speed, "50k"))
			speed_ptr = VSCAN_SPEED_50K;
		else if(strcmp(speed, "100k"))
			speed_ptr = VSCAN_SPEED_100K;
		else if(strcmp(speed, "125k"))
			speed_ptr = VSCAN_SPEED_125K;
		else if(strcmp(speed, "250k"))
			speed_ptr = VSCAN_SPEED_250K;
		else if(strcmp(speed, "500k"))
			speed_ptr = VSCAN_SPEED_500K;
		else if(strcmp(speed, "800k"))
			speed_ptr = VSCAN_SPEED_800K;
		else if(strcmp(speed, "1M"))
			speed_ptr = VSCAN_SPEED_1M;
		else
			return 0; // Check for bad status
		return this->ioctl(VSCAN_IOCTL_SET_SPEED, speed_ptr);
	}

	void VSCAN::getErrorString(VSCAN_STATUS status, char *string, unsigned long maxLen)
	{
		VSCAN_GetErrorString(status, string, maxLen);
	}
