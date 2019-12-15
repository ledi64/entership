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

#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string>
#include <sstream>

using namespace std;

void StratOne::strat(){

	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg, ans;
	stringstream shout;

	fstream data_stats;

	int hits, shotcounter, nmb_of_tests;
	int x, y;

	nmb_of_tests = 1;

	shout.clear();

	//connect to host
	c.conn(host , 2021);

	bool goOn = 1;

	data_stats.open("stats_for_entership_stratOne.txt", ios::out);

	data_stats << "This document shows the numbers of shots which were needed to finish the game." << endl;
	data_stats << endl << "shots needed:" << endl << endl;

	while(goOn)
	{
		shotcounter = 0;
		hits = 0;

		x = 1;
		y = 1;

		while(y <= 10)
		{
			while (x <= 10)
			{
				//String leeren
				shout.str("");

				//Koordinaten ausgeben
				shout << "COORD[" << x << ";" << y << "]";
				msg = shout.str();

				//Koordinaten an Server senden
				cout << "client:	" << msg << endl;
				c.sendData(msg);

				//Server antwortet, msg wird zur Antwort
				msg = c.receive(24);
				cout << "server:	" << msg << endl;

				//Schüsse werden gezählt
				shotcounter++;

				//Treffer Zähler
				if(msg.compare(0,6, "RES[1]") == 0)
				{
					hits++;

					cout << hits << endl;
				}

				//Abbruchkriterium von Clientenseite
				if(hits == 30)
				{
					y = 10;
					x = 10;
					//break;
				}

				x++;
			}

			y++;
			x = 1;
		}

		//Shotcounter Ausgabe
		cout << endl << "shots needed:   " << shotcounter << endl;

		//Durchgang und Anzahl an Schüsse werden in Datei geschrieben
		data_stats << "stage " << nmb_of_tests << " :   ";
		data_stats << shotcounter << endl;

		//String wird geleert
		shout.str("");

		if (nmb_of_tests > 20)
		{
			goOn = 0;
		}
		else
		{
			sleep(1);
			//New Game Message
			shout << "NEWGAME";
			msg = shout.str();

			//Message wird gesendet
			cout << "client:	" << msg << endl;
			c.sendData(msg);
		}

		//msg wird zur Antwort des Servers
		msg = c.receive(24);
		cout << "server:	" << msg << endl;

		//Neuer Durchgang
		nmb_of_tests++;

		goOn = 1;

		//sleep(1);

		//Beenden des Alg. bei 20 Durchgängen
		if (nmb_of_tests > 20)
		{
			goOn = 0;
		}
	}

	//Datei wird geschlossen
	data_stats.close();

	cout << "Stats successfully written!" << endl;

	/*cout << "client says: ";
	ans = "BYEBYE";
	c.sendData(ans);*/

}

void StratTwo::strat(){

}
