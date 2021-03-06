/*
 * Player.cpp
 *
 *  Created on: 21 ����. 2018 �.
 *      Author: �������
 */
#include "Player.h"

void Player::getCard(Card card) {
	player_values_cards.push_back(card);
    Player::setPositionCards();
    // Necessary call a method showCards in main loop!!!!!
}

vector<sf::Sprite> Player::showCards() const {
	return player_image_cards;
}

vector<Card> Player::listCards() const {
	return player_values_cards;
}

void Player::deleteCard(int pos) {
	player_image_cards.erase(player_image_cards.begin() + pos);
	player_values_cards.erase(player_values_cards.begin() + pos);
	// delta -= 120.f;
	Player::setPositionCards();
}

Card Player::returnCard(int pos) {
	return player_values_cards[pos];
}

int Player::amountCards() const {
	return player_values_cards.size();
}

void Player::setPositionCards() {
	sort(player_values_cards.begin(), player_values_cards.end());
	player_image_cards.clear();
	float delta = 0.f;
	float shift = 120.f;
	if (player_values_cards.size() > 6)
	{
		delta = -((player_values_cards.size() % 6) * 20.f);
		shift = 120.f - (player_values_cards.size() % 6) * 2.f;
	}
    for (size_t i = 0; i < player_values_cards.size(); i++) {
    	sf::Sprite image_card = player_values_cards[i].showCard();
    	image_card.setPosition(330.f + delta, 570.f);
    	delta += shift;
    	player_image_cards.push_back(image_card);
    }
}
