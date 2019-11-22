/*
 * MyTCPServer.H
 *
 *  Created on: 24.10.2019
 *      Author: ledi64
 */

#ifndef MYTCPSERVER_H_
#define MYTCPSERVER_H_

#include "SIMPLESOCKET.H"
#include "TASK3.H"
#include <string>

class MyTCPServer : public TCPserver{

protected:
	TASK3::World *world_;

public:
	MyTCPServer(int port, int maxDataSizeRecv) : TCPserver(port, maxDataSizeRecv)
	{
		world_ = new TASK3::World;

		world_->printBoard();

	};

protected:

	virtual string myResponse(string input);
};


#endif /* MYTCPSERVER_H_ */
