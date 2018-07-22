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
#include "Intersection.h"
#include "Audio.h"

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Card game!", sf::Style::Fullscreen);

    sf::Sprite new_cross_two = load()[0];
    sf::Sprite fon_game = load()[1];

    sf::Text play_game = load_texts()[0];
    sf::Text quit_game = load_texts()[1];

    sf::Sound click = load_song();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            	window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
            	sf::Vector2i pos_mouse = sf::Mouse::getPosition();
            	sf::Vector2f pos_text_game = play_game.getPosition();
                sf::Vector2f pos_text_quit = quit_game.getPosition();

                // Нажали на кнопку запуска уровня!
            	if (intersection(pos_mouse, pos_text_game) == true)
            	{
            		click.play();
            		cout << "Level launched";
            	}

            	// Нажали на кнопку выхода!
            	if (intersection(pos_mouse, pos_text_quit) == true)
            	{
            		click.play();
            		window.close();
            	}
            }
        }

        window.clear();

        window.draw(fon_game);
        window.draw(new_cross_two);
        window.draw(play_game);
        window.draw(quit_game);

        window.display();
    }

    return 0;
}
