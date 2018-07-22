/*
 * Graphics.cpp
 *
 *  Created on: 17 июля 2018 г.
 *      Author: связной
 */

#include "Graphics.h"
#include <iostream>

using namespace std;

sf::Texture card1;
sf::Texture fon1;
sf::Font font;
sf::Text play_text("Play game", font, 50);
sf::Text quit_text("Quit game", font, 50);

vector<sf::Sprite> load() {
	sf::Sprite new_card;
	sf::Sprite fon;

	card1.loadFromFile("src\\PNG\\Cards\\cardClubs2.png");
	new_card.setTexture(card1);

	fon1.loadFromFile("C:\\Users\\связной\\workspace\\Coursera\\src\\PNG\\fon_game.jpg");
	fon.setTexture(fon1);

	return {new_card, fon};
}

vector<sf::Text> load_texts() {
	if (!font.loadFromFile("C:\\Users\\связной\\workspace\\Coursera\\src\\PNG\\arial.ttf"))
		cout << "Font is no";

	play_text.setPosition(550, 300);
	play_text.setFillColor(sf::Color::Red);

	quit_text.setPosition(550, 400);
	quit_text.setFillColor(sf::Color::Red);
	return {play_text, quit_text};
}



