/*
 * Rival.cpp
 *
 *  Created on: 24 но€б. 2018 г.
 *      Author: св€зной
 */
#include "Rival.h"

void Rival::getCard(Card card) {
	rival_value_cards.push_back(card);

	Rival::sortCards();
}

vector<sf::Sprite> Rival::showCards() const {
	return rival_image_cards;
}

void Rival::deleteCard(int pos) {
	rival_image_cards.erase(rival_image_cards.begin() + pos);
	rival_value_cards.erase(rival_value_cards.begin() + pos);
	Rival::sortCards();
	//delta -= 120.f;
}

Card Rival::moveCard(const vector<Card> active_cards) {
	Card card_for_move;
    bool flag = false;

    // Fix bug with rival_cards
    if (rival_value_cards.size() == 0) {
    	return card_for_move;
    }

	if (active_cards.size() == 0) {
		card_for_move = rival_value_cards[0];
	    Rival::deleteCard(0);
	}
	else {
		for (Card desk_card : active_cards) {
			for (size_t i = 0; i < rival_value_cards.size(); i ++) {
				if (desk_card.showValue() == rival_value_cards[i].showValue()) {
					card_for_move = rival_value_cards[i];
					Rival::deleteCard(i);
					flag = true;
					break;
				}
			}
			if (flag == true)
			{
				break;
			}
		 }
	}
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

		// Defend by minimum card
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

int Rival::amountCards() const {
	return rival_value_cards.size();
}

void Rival::sortCards() {
	sort(rival_value_cards.begin(), rival_value_cards.end());
	rival_image_cards.clear();
	float delta = 0.f;
    for (size_t i = 0; i < rival_value_cards.size(); i++) {
    	sf::Sprite image_card = rival_value_cards[i].showCard();
    	image_card.setPosition(330.f + delta, 0.f);
    	delta += 120.f;
    	rival_image_cards.push_back(image_card);
    }
}
