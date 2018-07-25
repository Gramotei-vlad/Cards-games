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
#include "Game_fool.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
    sf::RenderWindow window(sf::VideoMode(1366, 768), "Card game!", sf::Style::Fullscreen);

    sf::Sprite fon_game = load_background();
    vector<sf::Sprite> cards = load();

    sf::Text play_game = load_texts()[0];
    sf::Text quit_game = load_texts()[1];

    sf::Sound click = load_song();

    bool game_launched = false;

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

            	// Не запускали никакой уровень, мы в меню!
            	if (game_launched == false)
            	{
            		sf::Vector2f pos_text_game = play_game.getPosition();
            		sf::Vector2f pos_text_quit = quit_game.getPosition();

            		// Нажали на кнопку запуска уровня!
            		if (intersection(pos_mouse, pos_text_game) == true)
            		{
            			click.play();
            		    game_launched = true;
            		    game_level_fool(cards);
            		 }

            		 // Нажали на кнопку выхода!
            		 if (intersection(pos_mouse, pos_text_quit) == true)
            		 {
            		     click.play();
            		     window.close();
            		  }

            	}

            }
        }

        window.clear();

        window.draw(fon_game);

        if (game_launched == false)
        {
        	window.draw(play_game);
        	window.draw(quit_game);
        }

        window.display();
    }

    return 0;
}
