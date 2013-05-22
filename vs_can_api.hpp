/*
 * vs_can_api.hpp
 *
 *  Created on: Apr 30, 2013
 *      Author: cody
 */

#ifndef VS_CAN_API_HPP_
#define VS_CAN_API_HPP_

#include <vs_can_api/vs_can_api.h>
#include <string.h>

class VSCAN
{
public:
	VSCAN_HANDLE open(char *port, unsigned long mode);
	VSCAN_STATUS close(void);
	VSCAN_STATUS flush(void);
	VSCAN_STATUS write(VSCAN_MSG *buf, unsigned long size, unsigned long *written);
	VSCAN_STATUS read(VSCAN_MSG *buf, unsigned long size, unsigned long *read);
	VSCAN_STATUS setRcvEvent(sem_t *event);
	VSCAN_STATUS ioctl(unsigned long ioctl, void *param);
	void getErrorString(VSCAN_STATUS status, char *string, unsigned long maxLen);

	VSCAN_STATUS setSpeed(char * speed);

private:
	VSCAN_HANDLE handle;

};

#endif /* VS_CAN_API_HPP_ */
