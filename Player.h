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
	void getCard(Card card);
	vector<sf::Sprite> showCards() const;
	vector<Card> listCards() const;
	void deleteCard(int pos);
	Card returnCard(int pos);
	int amountCards() const;
	void sortCards();
private:
	vector<sf::Sprite> player_image_cards;
	vector<Card> player_values_cards;
};





#endif /* PLAYER_H_ */
