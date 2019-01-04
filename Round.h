/*
 * Round.h
 *
 *  Created on: 18 дек. 2018 г.
 *      Author: связной
 */

#ifndef ROUND_H_
#define ROUND_H_
#include "Rival.h"
#include "Game.h"
#include "DrawGame.h"
#include "AudioGame.h"
#include "Player.h"

class Round
{
public:
	Round();
	void run(sf::RenderWindow& window, DrawGame& DrawGame1, AudioGame& AudioGame1);
private:
	Game startRound(Player& Player1, Rival& Rival1);
	void stopRound();
	bool round;
};





#endif /* ROUND_H_ */
