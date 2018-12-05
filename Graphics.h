/*
 * Graphics.h
 *
 *  Created on: 17 июля 2018 г.
 *      Author: связной
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include "Card.h"

using namespace std;

// Загрузка спрайтов
vector<Card> load();

// Загрузка фона игры
vector<sf::Sprite> load_background();

// Загрузка шрифтов и текстов
vector<sf::Text> load_texts();

vector<sf::Sprite> load_cardsBack();

#endif /* GRAPHICS_H_ */
