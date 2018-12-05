/*
 * Rival.h
 *
 *  Created on: 24 ����. 2018 �.
 *      Author: �������
 */

#ifndef RIVAL_H_
#define RIVAL_H_
#include "SFML/Graphics.hpp"
#include <random>
#include "Card.h"
#include <iostream>

using namespace std;

class Rival {
public:
	void getCard(Card card);
	vector<sf::Sprite> showCards();
	void deleteCard(int pos);
	sf::Sprite moveCard();
	Card defend(Card card);
	int amountCards();
private:
	vector<sf::Sprite> rival_image_cards;
	vector<Card> rival_value_cards;
	float delta = 0; // Don't care about it. Offset cards on the screen
};





#endif /* RIVAL_H_ */
