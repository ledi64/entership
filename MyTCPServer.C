/*
 * MyTCPServer.C
 *
 *  Created on: 24.10.2019
 *      Author: ledi64
 */

#include <cstdio> // standard input and output library
#include <cstdlib> // this includes functions regarding memory allocation
#include <cstring> // contains string functions
#include <cerrno> //It defines macros for reporting and retrieving error conditions through error codes
#include <ctime> //contains various functions for manipulating date and time

#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses

//#include "SIMPLESOCKET.H"
#include "MyTCPServer.H"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "TASK3.H"

using namespace std;

string MyTCPServer::myResponse(string input){

	std::stringstream ss;
	int x,y;
	TASK3::ShootResult result;

	/*
	 * Antwortmöglichkeiten bei "Koordinatenaustausch"
	 *
	 * res[0] = "Water"
	 * res[1] = "Ship-Hit"
	 * res[2] = "Ship-Destroyed"
	 * res[3] = "All-Ships-Destroyed"
	 * res[4] = "Game-Over"
	 *
	 */

	if(input.compare(0,6,"COORD[") == 0)
	{
		if(2!=sscanf(input.c_str(), "COORD[%d;%d]", &x, &y) )
		{
			return string("RES[-1]\n");
		}

		if( (x < 1) || (y < 1) || (x > 10) || (y > 10) ){
			return string("RES[-2]\n");
		}

		cout << "shoot(" << x << "," << y << ")\n";

		result = world_->shoot(x,y);

		//result = (TASK3::ShootResult) (rand() % 6);

		if (result == 4)
		{
			ss << "RES[" << result << "]\n";
		}
		else if (result == 2)
		{
			ss << "RES[" << result << "]\n";
		}
		else
		{
			ss << "RES[" << result << "]\n";
		}

		return ss.str();
	};

	//Neue Welt erzeugen (del altes Objekt, new neues Objekt

	if(input.compare(0,7, "NEWGAME") == 0 ){

		delete world_;

		world_ = new TASK3::World;

		cout << endl;

		world_->printBoard();

		return string("CREATING NEW GAME\n");
	};

	/*if(input.compare(0,3, "HELP") == 0 ){

		return string("BYEBYE for disconnect\n\nCOORD[x;y] for sending coordinates to the server\n\nHELP for a list of commands\n\nNEWGAME for starting a new game\n\n");
	};*/

	return string("UNKNOWN COMMAND!\n");
}
