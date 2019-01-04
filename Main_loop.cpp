//============================================================================
// Name        : Main_loop.cpp
// Author      : Vladislav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

#include "Graphics.h"
#include "Utils.h"
#include "Audio.h"
#include "Player.h"
#include "Rival.h"
#include "Game.h"
#include "Round.h"
#include "DrawGame.h"
#include "AudioGame.h"
#include "TestFramework.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Card game!", sf::Style::Fullscreen);

	AudioGame AudioGame1;
	DrawGame DrawGame1;

	bool show_settings = false;

	AudioGame1.playMainMusic();

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				show_settings = false;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				// Get a mouse position
				// Check a text position

				sf::Vector2i pos_mouse = sf::Mouse::getPosition();

				vector<sf::Text> game_texts = DrawGame1.gameTexts();
				sf::Vector2f pos_text_game = game_texts[0].getPosition();
				sf::Vector2f pos_text_controller = game_texts[1].getPosition();
				sf::Vector2f pos_text_quit = game_texts[2].getPosition();

				if (intersection(pos_mouse, pos_text_game) == true) {
					AudioGame1.playClick();
					Round Round1;
					Round1.run(window, DrawGame1, AudioGame1);
				}

				if (intersection(pos_mouse, pos_text_controller) == true) {
					AudioGame1.playClick();
					show_settings = true;
				}

				if (intersection(pos_mouse, pos_text_quit) == true) {
					AudioGame1.playClick();
					DrawGame1.close(window);
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				DrawGame1.close(window);
			}

		}

		DrawGame1.clear(window);
		DrawGame1.showBackground(window);
		if (show_settings == false) {
			DrawGame1.showMenu(window);
		}
		else {
			DrawGame1.showSettings(window);
		}
		DrawGame1.display(window);
	}

    return 0;
}
