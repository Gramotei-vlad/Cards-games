/*
 * Card.h
 *
 *  Created on: 01 дек. 2018 г.
 *      Author: связной
 */

#ifndef CARD_H_
#define CARD_H_
#include <SFML/Graphics.hpp>

using namespace std;

class Card {
public:
	Card();
	Card(int new_value, string new_suit, sf::Sprite new_image);
	void changeImage(float x, float y);
	sf::Sprite showCard() const;
	int showValue() const;
	string showSuit() const;

private:
	int value;
	string suit;
	sf::Sprite image;
};




#endif /* CARD_H_ */
