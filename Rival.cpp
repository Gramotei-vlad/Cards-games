/*
 * Rival.cpp
 *
 *  Created on: 24 ����. 2018 �.
 *      Author: �������
 */
#include "Rival.h"

void Rival::getCard(sf::Sprite card) {
	rival_cards.push_back(card);
}

vector<sf::Sprite> Rival::showCard() {
	return rival_cards;
}



