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

using namespace std;

// Загрузка спрайтов
vector<sf::Sprite> load();

// Загрузка фона игры
vector<sf::Sprite> load_background();

// Загрузка шрифтов и текстов
vector<sf::Text> load_texts();

#endif /* GRAPHICS_H_ */
