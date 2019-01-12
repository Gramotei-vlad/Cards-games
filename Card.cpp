/*
 * Card.cpp
 *
 *  Created on: 01 дек. 2018 г.
 *      Author: связной
 */
#include "Card.h"
#include "Graphics.h"

Card::Card() {
	image_value = 0;
	trump_value = 0;
	suit = "None";
	image = load_cardsBack();
}

Card::Card(int new_value, string new_suit, sf::Sprite new_image) {
	image_value = new_value;
	trump_value = new_value;
	suit = new_suit;
	image = new_image;
}

void Card::changeImage(float x, float y) {
	image.setPosition(x, y);
}

void Card::changeValue(int new_value)
{
	trump_value = new_value;
}

sf::Sprite Card::showCard() const {
	return image;
}

int Card::showImageValue() const {
	return image_value;
}

int Card::showTrumpValue() const {
	return trump_value;
}

string Card::showSuit() const {
	return suit;
}

void Card::setPosition(float x, float y) {
	image.setPosition(x, y);
}
