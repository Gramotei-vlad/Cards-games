/*
 * Rival.cpp
 *
 *  Created on: 24 но€б. 2018 г.
 *      Author: св€зной
 */
#include "Rival.h"

void Rival::getCard(sf::Sprite card) {
	rival_cards.push_back(card);
}

vector<sf::Sprite> Rival::showCard() {
	return rival_cards;
}



