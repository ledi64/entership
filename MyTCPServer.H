/*
 * MyTCPServer.H
 *
 *  Created on: 24.10.2019
 *      Author: ledi64
 */

#ifndef MYTCPSERVER_H_
#define MYTCPSERVER_H_

#include "SIMPLESOCKET.H"
#include <string>

class MyTCPServer : public TCPserver{
protected:

	virtual string myResponse(string input);
};


#endif /* MYTCPSERVER_H_ */
