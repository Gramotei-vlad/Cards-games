/*
 * Card.cpp
 *
 *  Created on: 01 дек. 2018 г.
 *      Author: связной
 */
#include "Card.h"
#include "Graphics.h"

Card::Card() {
	value = 0;
	suit = "None";
	image = load_cardsBack()[0];
}

Card::Card(int new_value, string new_suit, sf::Sprite new_image) {
	value = new_value;
	suit = new_suit;
	image = new_image;
}

void Card::changeImage(float x, float y) {
	image.setPosition(x, y);
}

sf::Sprite Card::showCard() const {
	return image;
}

int Card::showValue() const {
	return value;
}

string Card::showSuit() const {
	return suit;
}
