/*
 * Rival.h
 *
 *  Created on: 24 но€б. 2018 г.
 *      Author: св€зной
 */

#ifndef RIVAL_H_
#define RIVAL_H_
#include "SFML/Graphics.hpp"
#include <random>
#include "Card.h"
#include "Utils.h"
#include <iostream>

using namespace std;

class Rival {
public:
	void getCard(Card card);
	vector<sf::Sprite> showCards() const;
	void deleteCard(int pos);
	Card moveCard(const vector<Card> active_cards);
	Card defend(Card card);
	int amountCards() const;
private:
	void sortCards();
	vector<sf::Sprite> rival_image_cards;
	vector<Card> rival_value_cards;
	float delta = 0; // Don't care about it. Offset cards on the screen
};





#endif /* RIVAL_H_ */
