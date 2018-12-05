/*
 * Rival.cpp
 *
 *  Created on: 24 но€б. 2018 г.
 *      Author: св€зной
 */
#include "Rival.h"

void Rival::getCard(Card card) {
	rival_value_cards.push_back(card);

	sf::Sprite image_card = card.showCard();
	image_card.setPosition(330.f + delta, 0.f);
	delta += 120.f;
	rival_image_cards.push_back(image_card);
}

vector<sf::Sprite> Rival::showCards() {
	return rival_image_cards;
}

void Rival::deleteCard(int pos) {
	rival_image_cards.erase(rival_image_cards.begin() + pos);
	rival_value_cards.erase(rival_value_cards.begin() + pos);
	delta -= 120.f;
}

sf::Sprite Rival::moveCard() {
	srand( time(0) );
	int pos = rand() % rival_image_cards.size();
    sf::Sprite card_for_move = rival_image_cards[pos];
	Rival::deleteCard(pos);
	return card_for_move;
}

Card Rival::defend(Card card) {
	Card defend_card;
	int player_value = card.showValue();
	string player_suit = card.showSuit();
	int pos = 100;
	int min_value = 100;

	for (size_t i = 0; i < rival_value_cards.size(); i++) {
		int rival_value = rival_value_cards[i].showValue();
		string rival_suit = rival_value_cards[i].showSuit();

		/*cout << "Rival value: " << rival_value << endl;
		cout << "Rival suit: " << rival_suit << endl;
		cout << "Player value: " << player_value << endl;
		cout << "Player suit: " << player_suit << endl;*/

		// Deafen by minimum card
		if ((rival_value > player_value) && (rival_suit == player_suit)) {
			if (min_value > rival_value) {
				min_value = rival_value;
				pos = i;
				defend_card = rival_value_cards[i];
			}
		}
	}

	if (pos != 100) {
		Rival::deleteCard(pos);
	}

	return defend_card;
}

int Rival::amountCards() {
	return rival_value_cards.size();
}


