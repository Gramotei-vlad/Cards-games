/*
 * Player.cpp
 *
 *  Created on: 21 но€б. 2018 г.
 *      Author: св€зной
 */
#include "Player.h"

void Player::getCards(Card card) {
	player_values_cards.push_back(card);
    Player::sortCards();
    // Necessary call a method showCards in main loop!!!!!
}

vector<sf::Sprite> Player::showCards() {
	return player_image_cards;
}

void Player::deleteCard(int pos) {
	player_image_cards.erase(player_image_cards.begin() + pos);
	player_values_cards.erase(player_values_cards.begin() + pos);
	// delta -= 120.f;
}

Card Player::returnCard(int pos) {
	return player_values_cards[pos];
}

int Player::amountCards() {
	return player_values_cards.size();
}

void Player::sortCards() {
	sort(player_values_cards.begin(), player_values_cards.end());
	player_image_cards.clear();
	float delta = 0.f;
    for (size_t i = 0; i < player_values_cards.size(); i++) {
    	sf::Sprite image_card = player_values_cards[i].showCard();
    	image_card.setPosition(330.f + delta, 570.f);
    	delta += 120.f;
    	player_image_cards.push_back(image_card);
    }
}
