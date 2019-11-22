/*
 * DestroyShip.C
 *
 *  Created on: 14.11.2019
 *      Author: ledi64
 */

#include "DestroyShip.H"
#include "TASK3.H"
#include "TASK3.C"

#include <string>

using namespace std;

virtual void StrategyOneShip::strat_gothrew()
{
	int x, y;
	x = 1;
	y = 1;

	while(y <= 10)
	{
	    while (x <= 10)
	    {
	        cout << "X-Koordinate:  ";
	        cout << x << endl;
	        cout << "Y-Koordinate:  ";
	        cout << y << endl << endl;

	        x++;
	    }

	    y++;
	    x = 1;
	}
}

virtual void StrategyTwoShip::strat_sourroundings()
{

};






