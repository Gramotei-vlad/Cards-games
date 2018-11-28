/*
 * Player.cpp
 *
 *  Created on: 21 но€б. 2018 г.
 *      Author: св€зной
 */
#include "Player.h"

void Player::getCard(sf::Sprite card) {
	player_cards.push_back(card);
}

vector<sf::Sprite> Player::showCard() {
	return player_cards;
}

void Player::deleteCard(int pos) {
	player_cards.erase(player_cards.begin() + pos);
}


