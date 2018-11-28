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

using namespace std;

// �������� ��������
vector<sf::Sprite> load();

// �������� ���� ����
vector<sf::Sprite> load_background();

// �������� ������� � �������
vector<sf::Text> load_texts();

#endif /* GRAPHICS_H_ */
