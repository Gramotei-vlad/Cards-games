/*
 * Intersection.cpp
 *
 *  Created on: 21 июля 2018 г.
 *      Author: связной
 */
#include "Intersection.h"
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


