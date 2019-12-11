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

/*int main() {

	StratOne *run;

	run->strat();

	delete run;*/

	//Strategie 1
	/*
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

	}

	ans = "BYEBYE";
	cout << "client says: " << ans << endl << endl;
	c.sendData(ans);

	cout << "Disconnecting from server..." << endl;*/

	//StratTwo
	/*srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg, ans;
	stringstream shout;

	int shots;

	shout.clear();

	//connect to host
	c.conn(host , 2021);

	int i=0;
	//bool goOn=1;
	int counter = 0;

	while (i <= 10)
	{
		shout.str("");

		/*if(counter == 100)
		{
			goOn = 0;

			break;
		}

		int x, y;

		x = rand() % 10 + 1;

		y = rand() % 10 + 1;

		/*
		 * Erzeuge zwei Felder mit den Random Werten von x und y
		 * Prüfe bei neuer Erzeugung, ob die Zahlen bereits im Array vorhanden sind
		 * Falls ja, erzeuge neue Zahl, sonst mach weiter und fülle den Array weiter
		 *
		 * Feldgröße begrenzt mit 10 x und 10 y Werten
		 *


		shout << "COORD[" << x << ";" << y << "]";
		msg = shout.str();

		cout << "client:	" << msg << endl;
		c.sendData(msg);

		msg = c.receive(24);
		cout << "server:	" << msg << endl;

		i++;

	}
	ans = "BYEBYE";
	cout << "client says: " << ans << endl << endl;
	c.sendData(ans);

	cout << "Disconnecting from server..." << endl;

}*/








