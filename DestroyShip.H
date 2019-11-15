/*
 * DestroyShip.H
 *
 *  Created on: 14.11.2019
 *      Author: ledi64
 */

#ifndef DESTROYSHIP_H_
#define DESTROYSHIP_H_

class IStrategyShip{

public:
	virtual void strat_gothrew() = 0;

	/*
	 *	Strategie 1:
	 *	Es wird der Reihe nach abgefragt (erst horizontal, also x-Achse, dann vertikal, also y-Achse),
	 *	ob eine Koordinate ein Teil eines Schiffes beinhält.
	 */

	virtual void strat_sourroundings() = 0;

	/*
	 *	Strategie 2:
	 *	Es wird zunächst Strategie 2 angewandt bis ein Teil vom Schiff erreicht wird. Danach wird die unmittelbare
	 *	Umgebung auf Schiffe bzw. Schiffteile geprüft.
	 *	Wichtig:
	 *		>> Fehlerbehebungen bei 1. und letzter x-Achse sowie 1. und letzter y-Achse
	 *		>> Abbruch bei Nachricht "Schiff versenkt!"
	 */

};

class StrategyOneShip : public IStrategyShip {

public:
	virtual void strat_gothrew();

};

class StrategyTwoShip : public IStrategyShip {

public:
	virtual void strat_sourroundings();

};


#endif /* DESTROYSHIP_H_ */
