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

	virtual void strat() = 0;

	/*
	 *	Strategie 1:
	 *	Es wird der Reihe nach abgefragt (erst horizontal, also x-Achse, dann vertikal, also y-Achse),
	 *	ob eine Koordinate ein Teil eines Schiffes beinhält.
	 */

	/*
	 *	Strategie 2:
	 *	Ähnelt Strategie 1, jedoch werden zufällig Koordinaten erzeugt und dem Server geschickt
	 *	Zudem wird geprüft, ob die Koordinaten bereits verschickt wurden.
	 *
	 */

};

class StratOne : public IStrategyShip{

public:

	virtual void strat();

};

class StratTwo : public IStrategyShip{

public:

	virtual void strat();
};

#endif /* DESTROYSHIP_H_ */
