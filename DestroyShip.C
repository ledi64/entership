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
	int x, y;

	x = 1;
	y = 1;

	while(y <= 10)
	{
		while (x <= 10)
		{
			cout << "COORD[" << x << ";" << y << "]" ;

			x++;

			sleep(1);
		}

		y++;
		x = 1;
	}

}






