/*
 * Intersection.h
 *
 *  Created on: 21 ���� 2018 �.
 *      Author: �������
 */

#ifndef INTERSECTION_H_
#define INTERSECTION_H_
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"

using namespace std;

// �������� ����, ����� �� ������ � ������� ������

bool intersection(sf::Vector2i pos_mouse, sf::Vector2f pos_text);

// ����� �� ������ � ������� �����
bool intersection_card(sf::Vector2i pos_mouse, sf::Vector2f pos_card);


bool operator==(const sf::Sprite& a, const sf::Sprite& b);

int find_card(vector<sf::Sprite> sprites, sf::Sprite picture);


#endif /* INTERSECTION_H_ */
