/*
 * DestroyShip.C
 *
 *  Created on: 14.11.2019
 *      Author: ledi64
 */

#include "DestroyShip.H"
#include "TASK3.H"
#include "TASK3.C"
#include "SIMPLESOCKET.H"
#include "MyTCPServer.H"

#include <unistd.h>
#include <string>

using namespace std;

void StratOne::strat(){

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
	cout << "client says: ";
	ans = "BYEBYE";
	c.sendData(ans);

}

void StratTwo::strat(){

}
