/*
 * Game.h
 *
 *  Created on: 12 дек. 2018 г.
 *      Author: связной
 */

#ifndef GAME_H_
#define GAME_H_

#include <random>

#include "Graphics.h"
#include "Card.h"
#include "Audio.h"
#include "Player.h"
#include "Rival.h"
#include "Utils.h"

using namespace std;

class Game {
public:
	Game();
	vector<Card> showDesk() const;
	bool checkDeck() const;
	bool whoAttacks() const;
	bool moveCard() const;
	void changeAssaulter();
	void giveoutCards(Player& Player1, Rival& Rival1);
	bool playerAttack(Player& Player1, const sf::Vector2i pos_mouse);
	bool playerDefend(Player& Player1, const sf::Vector2i pos_mouse);
	void playerTakesCards(Player& Player1, Rival& Rival1);
	bool rivalAttack(Rival& Rival1);
	bool rivalDefend(Rival& Rival1);
	void rivalTakesCards(Rival& Rival1);
	string checkWinners(Player& Player1, Rival& Rival1);
	string getTrump() const;
private:
	bool checkCard(const Card card) const;
	void setTrumpCards();
	bool movePermition(const Card card) const;
	bool defendPermition(const Card player_card, const Card rival_card) const;
	void setPositionsCards(bool attack);

	bool move_card_ = true;
	bool player_assaulter_ = true;
	string trump;
	vector<Card> deck;
	vector<Card> desk_cards;
	Card active_card;
};






#endif /* GAME_H_ */
