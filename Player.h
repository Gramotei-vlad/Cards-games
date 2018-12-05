/*
 * Player.h
 *
 *  Created on: 21 но€б. 2018 г.
 *      Author: св€зной
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Utils.h"

using namespace std;


class Player {
public:
	void getCards(Card card);
	vector<sf::Sprite> showCards();
	void deleteCard(int pos);
	Card returnCard(int pos);
	int amountCards();
	void sortCards();
private:
	vector<sf::Sprite> player_image_cards;
	vector<Card> player_values_cards;
};





#endif /* PLAYER_H_ */
