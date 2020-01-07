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
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

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

	data_stats << "This document shows the numbers of shots which were needed to finish the game by shooting structured (strategy 1)." << endl;
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

				//Treffer Zähler
				if(msg.compare(0,6, "RES[1]") == 0)
				{
					hits++;

					cout << hits << endl;
				}
				else if (msg.compare(0,6, "RES[2]") == 0)
				{
					hits++;

					cout << hits << endl;
				}

				if(msg.compare(0,6, "RES[4]") == 0)
				{
					hits++;

					cout << hits << endl;

					y = 10;

					break;
				}

				//Schüsse werden gezählt
				shotcounter++;

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

		//Beenden des Alg. bei 20 Durchgängen
		if (nmb_of_tests > 19)
		{
			goOn = 0;
			break;
		}
		else
		{
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

		//sleep(1);
	}

	//Datei wird geschlossen
	data_stats.close();

	cout << "Stats successfully written!" << endl;

	cout << "client says: ";
	c.sendData("BYEBYE");

}

void StratTwo::strat(){

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

	data_stats.open("stats_for_entership_stratTwo.txt", ios::out);

	data_stats << "This document shows the numbers of shots which were needed to finish the game by shooting randomly (strategy 2)." << endl;
	data_stats << endl << "shots needed:" << endl << endl;

	//int field[10][10] = {0};

	while(goOn)
	{
	    x = 1;
	    y = 1;

	    int field[10][10] = {0};

	    hits = 0;
	    shotcounter = 0;

	    while (hits > 29)
	    {
	        if(field[x][y] == 0)
	        {
	        	//String leeren
	        	shout.str("");

	        	//Koordinaten ausgeben
	        	shout << "COORD[" << x << ";" << y << "]";
	        	msg = shout.str();

	        	//Koordinaten an Server senden
	        	cout << "client:	" << msg << endl;
	        	c.sendData(msg);

	        	field[x][y] = 1;
	            shotcounter++;

	            //Server antwortet, msg wird zur Antwort
	            msg = c.receive(24);
	            cout << "server:	" << msg << endl;

	            //Treffer Zähler
	            if(msg.compare(0,6, "RES[1]") == 0)
	            {
	            	hits++;
	            	cout << hits << endl;
	            	//field[x][y] = 1;
	            }
	            else if (msg.compare(0,6, "RES[2]") == 0)
	            {
	            	hits++;
	            	cout << hits << endl;
	            	//field[x][y] = 1;
	            }

	            if(msg.compare(0,6, "RES[4]") == 0)
	            {
	            	hits = 30;
	            	cout << hits << endl;
	            	//field[x][y] = 1;

	            	break;
	            }

	            //cout << "Shots: " << shots << endl;
	        }
	        else
	        {
	            x = rand() % 10;
	            y = rand() % 10;
	        }

	        if(hits > 29)
	        {
	        	break;
	        }

	    }

	    //Shotcounter Ausgabe
	    cout << endl << "shots needed:   " << shotcounter << endl;

	    //Durchgang und Anzahl an Schüsse werden in Datei geschrieben
	    data_stats << "stage " << nmb_of_tests << " :   ";
	    data_stats << shotcounter << endl;

	    //String wird geleert
	    shout.str("");

	    //Beenden des Alg. bei 20 Durchgängen
	    if (nmb_of_tests > 19)
	    {
	    	goOn = 0;
	    	break;
	    }
	    else
	    {
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
	}

	//Datei wird geschlossen
	data_stats.close();

	cout << "Stats successfully written!" << endl;

	cout << "client says: ";
	c.sendData("BYEBYE");

}
