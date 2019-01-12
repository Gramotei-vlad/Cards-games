/*
 * Intersection.cpp
 *
 *  Created on: 21 июля 2018 г.
 *      Author: связной
 */
#include "Utils.h"
#include <iostream>
using namespace std;

bool intersection(sf::Vector2i pos_mouse, sf::Vector2f pos_text) {
	if (pos_text.x + 235 >= pos_mouse.x && pos_text.x <= pos_mouse.x
		&& pos_text.y + 50 >= pos_mouse.y && pos_text.y <= pos_mouse.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool intersection_card(sf::Vector2i pos_mouse, sf::Vector2f pos_card) {
	if (pos_card.x + 140 >= pos_mouse.x && pos_card.x <= pos_mouse.x
		&& pos_card.y + 190 >= pos_mouse.y && pos_card.y <= pos_mouse.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool operator==(const sf::Sprite& a, const sf::Sprite& b) {
	return a.getPosition().x == b.getPosition().x && a.getPosition().y == b.getPosition().y;
}

bool operator<(const Card& a, const Card& b) {
	return a.showTrumpValue() < b.showTrumpValue();

}

bool operator==(const Card& a, const Card& b) {
	return a.showTrumpValue() == b.showTrumpValue() && a.showSuit() == b.showSuit();
}

int find_card(vector<sf::Sprite> sprites, sf::Sprite picture) {
	int pos = 0;
	for (sf::Sprite sprite : sprites) {
		if (sprite == picture) {
			return pos;
		}
		pos += 1;
	}
	return -1;
}
