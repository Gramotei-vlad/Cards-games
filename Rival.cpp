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

void Rival::deleteCard(int pos) {
	rival_cards.erase(rival_cards.begin() + pos);
}

sf::Sprite Rival::moveCard() {
	srand( time(0) );
	int pos = rand() % rival_cards.size();
	sf::Sprite card_for_move = rival_cards[pos];
	Rival::deleteCard(pos);
	return card_for_move;
}


