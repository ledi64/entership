/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
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

#include <string>
#include <sstream>
#include <iostream>
#include "TASK3.H"

//#include "SIMPLESOCKET.H"
#include "DestroyShip.H"
#include "MyTCPServer.H"

using namespace std;
/*
int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;

	//connect to host
	c.conn(host , 2021);

	int i=0;
	bool goOn=1;
	while(goOn){ // send and receive data
		if((rand() % 20) < i++){
			msg = string("BYEBYE");
			goOn = 0;
		}else{
			msg = string("client wants this");
		}
		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		msg = c.receive(32);
		cout << "got response:" << msg << endl;
		sleep(1);

	}
}*/

int main() {
	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg, ans;
	stringstream shout;

	int shots;

	shout.clear();

	//connect to host
	c.conn(host , 2021);

	int i=0;
	bool goOn=1;

	while(goOn)
	{
		int x = 1;
		int y = 1;

		while(y <= 10)
		{
			if(y == 10)
			{
				goOn = 0;
			}

			while (x <= 10)
			{
				shout.str("");

				shout << "COORD[" << x << ";" << y << "]";
				msg = shout.str();

				cout << "client:	" << msg << endl;
				c.sendData(msg);

				msg = c.receive(24);
				cout << "server:	" << msg << endl;

				if(msg.compare(0,6, "RES[1]") == 0)
				{
					shots++;

					cout << shots << endl;
				}

				if(shots == 30)
				{
					y = 10;

					break;
				}

				x++;

				sleep(1);
			}

			y++;
			x = 1;
		}

		/*msg = "COORD"

		cout << "client sends:" << msg << endl;
		c.sendData(msg);
		msg = c.receive(32);
		cout << "got response:" << msg << endl;
		sleep(1);*/
	}
	cout << "client says: ";
	ans = "BYEBYE";
	c.sendData(ans);

}

/*int main(){

	//srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg, input;
	int counter = 0;

	//StratOne s;

	c.conn(host, 2021);

	bool goOn = 1;

	while(goOn)
	{
		/*if(input.compare(0,6, "RES[4]") == 0){
			cout << "NEWGAME" << endl;
		}else if(counter > 10 ) {
			msg = string("BYEBYE");
			goOn = 0;
		}else{

		int x, y;

		x = 1;
		y = 1;

		cout << "Start" << endl;

		while(y <= 10)
		{
			while (x <= 10)
			{
				cout << "COORD[" << x << ";" << y << "]" ;

				x++;

				//sleep(1);
			}

			y++;
			x = 1;
		}
		if(y == 10) cout << "BYEBYE";

		sleep(1);

		//}
	}

}*/







