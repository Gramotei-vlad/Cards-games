/*
 * Graphics.h
 *
 *  Created on: 17 ���� 2018 �.
 *      Author: �������
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include "Card.h"

using namespace std;

// �������� ��������
vector<Card> load();

// �������� ���� ����
vector<sf::Sprite> load_background();

// �������� ������� � �������
vector<sf::Text> load_texts();

vector<sf::Sprite> load_cardsBack();

#endif /* GRAPHICS_H_ */
