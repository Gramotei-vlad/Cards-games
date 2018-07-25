/*
 * Graphics.cpp
 *
 *  Created on: 17 июл€ 2018 г.
 *      Author: св€зной
 */

#include "Graphics.h"
#include <iostream>

using namespace std;

// “екстуры дл€ игровых карт, загружаемых последовательно от 6 до туза!

sf::Texture clubs6;
sf::Texture spades6;
sf::Texture diamonds6;
sf::Texture hearts6;

sf::Texture clubs7;
sf::Texture spades7;
sf::Texture diamonds7;
sf::Texture hearts7;

sf::Texture clubs8;
sf::Texture spades8;
sf::Texture diamonds8;
sf::Texture hearts8;

sf::Texture clubs9;
sf::Texture spades9;
sf::Texture diamonds9;
sf::Texture hearts9;

sf::Texture clubs10;
sf::Texture spades10;
sf::Texture diamonds10;
sf::Texture hearts10;

sf::Texture clubsJ;
sf::Texture spadesJ;
sf::Texture diamondsJ;
sf::Texture heartsJ;

sf::Texture clubsQ;
sf::Texture spadesQ;
sf::Texture diamondsQ;
sf::Texture heartsQ;

sf::Texture clubsK;
sf::Texture spadesK;
sf::Texture diamondsK;
sf::Texture heartsK;

sf::Texture clubsA;
sf::Texture spadesA;
sf::Texture diamondsA;
sf::Texture heartsA;

sf::Texture fon1;
sf::Font font;
sf::Text play_text("Play game", font, 50);
sf::Text quit_text("Quit game", font, 50);

vector<sf::Sprite> load() {
	vector<sf::Sprite> cards;

	sf::Sprite six_clubs;
	sf::Sprite six_spades;
	sf::Sprite six_diamonds;
	sf::Sprite six_hearts;

	sf::Sprite seven_clubs;
	sf::Sprite seven_spades;
	sf::Sprite seven_diamonds;
	sf::Sprite seven_hearts;

	sf::Sprite eight_clubs;
	sf::Sprite eight_spades;
	sf::Sprite eight_diamonds;
	sf::Sprite eight_hearts;

	sf::Sprite nine_clubs;
	sf::Sprite nine_spades;
	sf::Sprite nine_diamonds;
	sf::Sprite nine_hearts;

	sf::Sprite ten_clubs;
	sf::Sprite ten_spades;
	sf::Sprite ten_diamonds;
	sf::Sprite ten_hearts;

	sf::Sprite J_clubs;
	sf::Sprite J_spades;
	sf::Sprite J_diamonds;
	sf::Sprite J_hearts;

	sf::Sprite Q_clubs;
	sf::Sprite Q_spades;
	sf::Sprite Q_diamonds;
	sf::Sprite Q_hearts;

	sf::Sprite K_clubs;
	sf::Sprite K_spades;
	sf::Sprite K_diamonds;
	sf::Sprite K_hearts;

	sf::Sprite A_clubs;
	sf::Sprite A_spades;
	sf::Sprite A_diamonds;
	sf::Sprite A_hearts;

	clubs6.loadFromFile("src\\PNG\\Cards\\cardClubs6.png");
	six_clubs.setTexture(clubs6);
	cards.push_back(six_clubs);

	spades6.loadFromFile("src\\PNG\\Cards\\cardSpades6.png");
	six_spades.setTexture(spades6);
	cards.push_back(six_spades);

	diamonds6.loadFromFile("src\\PNG\\Cards\\cardDiamonds6.png");
	six_diamonds.setTexture(diamonds6);
	cards.push_back(six_diamonds);

	hearts6.loadFromFile("src\\PNG\\Cards\\cardHearts6.png");
	six_hearts.setTexture(hearts6);
	cards.push_back(six_hearts);

	clubs7.loadFromFile("src\\PNG\\Cards\\cardClubs7.png");
	seven_clubs.setTexture(clubs7);
	cards.push_back(seven_clubs);

	spades7.loadFromFile("src\\PNG\\Cards\\cardSpades7.png");
	seven_spades.setTexture(spades7);
	cards.push_back(seven_spades);

	diamonds7.loadFromFile("src\\PNG\\Cards\\cardDiamonds7.png");
	seven_diamonds.setTexture(diamonds7);
	cards.push_back(seven_diamonds);

	hearts7.loadFromFile("src\\PNG\\Cards\\cardHearts7.png");
	seven_hearts.setTexture(hearts7);
	cards.push_back(seven_hearts);

	clubs8.loadFromFile("src\\PNG\\Cards\\cardClubs8.png");
	eight_clubs.setTexture(clubs8);
	cards.push_back(eight_clubs);

	spades8.loadFromFile("src\\PNG\\Cards\\cardSpades8.png");
	eight_spades.setTexture(spades8);
	cards.push_back(eight_spades);

	diamonds8.loadFromFile("src\\PNG\\Cards\\cardDiamonds8.png");
	eight_diamonds.setTexture(diamonds8);
	cards.push_back(eight_diamonds);

	hearts8.loadFromFile("src\\PNG\\Cards\\cardHearts8.png");
	eight_hearts.setTexture(hearts8);
	cards.push_back(eight_hearts);

	clubs9.loadFromFile("src\\PNG\\Cards\\cardClubs9.png");
	nine_clubs.setTexture(clubs9);
	cards.push_back(nine_clubs);

	spades9.loadFromFile("src\\PNG\\Cards\\cardSpades9.png");
	nine_spades.setTexture(spades9);
	cards.push_back(nine_spades);

	diamonds9.loadFromFile("src\\PNG\\Cards\\cardDiamonds9.png");
	nine_diamonds.setTexture(diamonds9);
	cards.push_back(nine_diamonds);

	hearts9.loadFromFile("src\\PNG\\Cards\\cardHearts9.png");
	nine_hearts.setTexture(hearts9);
	cards.push_back(nine_hearts);

	clubs10.loadFromFile("src\\PNG\\Cards\\cardClubs10.png");
	ten_clubs.setTexture(clubs10);
	cards.push_back(ten_clubs);

	spades10.loadFromFile("src\\PNG\\Cards\\cardSpades10.png");
	ten_spades.setTexture(spades10);
	cards.push_back(ten_spades);

	diamonds10.loadFromFile("src\\PNG\\Cards\\cardDiamonds10.png");
	ten_diamonds.setTexture(diamonds10);
	cards.push_back(ten_diamonds);

	hearts10.loadFromFile("src\\PNG\\Cards\\cardHearts10.png");
	ten_hearts.setTexture(hearts10);
	cards.push_back(ten_hearts);

	clubsJ.loadFromFile("src\\PNG\\Cards\\cardClubsJ.png");
	J_clubs.setTexture(clubsJ);
	cards.push_back(J_clubs);

	spadesJ.loadFromFile("src\\PNG\\Cards\\cardSpadesJ.png");
	J_spades.setTexture(spadesJ);
	cards.push_back(J_spades);

	diamondsJ.loadFromFile("src\\PNG\\Cards\\cardDiamondsJ.png");
	J_diamonds.setTexture(diamondsJ);
	cards.push_back(J_diamonds);

	heartsJ.loadFromFile("src\\PNG\\Cards\\cardHeartsJ.png");
	J_hearts.setTexture(heartsJ);
	cards.push_back(J_hearts);

	clubsQ.loadFromFile("src\\PNG\\Cards\\cardClubsQ.png");
	Q_clubs.setTexture(clubsQ);
	cards.push_back(Q_clubs);

	spadesQ.loadFromFile("src\\PNG\\Cards\\cardSpadesQ.png");
	Q_spades.setTexture(spadesQ);
	cards.push_back(Q_spades);

	diamondsQ.loadFromFile("src\\PNG\\Cards\\cardDiamondsQ.png");
	Q_diamonds.setTexture(diamondsQ);
	cards.push_back(Q_diamonds);

	heartsQ.loadFromFile("src\\PNG\\Cards\\cardHeartsQ.png");
	Q_hearts.setTexture(heartsQ);
	cards.push_back(Q_hearts);

	clubsK.loadFromFile("src\\PNG\\Cards\\cardClubsK.png");
	K_clubs.setTexture(clubsK);
	cards.push_back(K_clubs);

	spadesK.loadFromFile("src\\PNG\\Cards\\cardSpadesK.png");
	K_spades.setTexture(spadesK);
	cards.push_back(K_spades);

	diamondsK.loadFromFile("src\\PNG\\Cards\\cardDiamondsK.png");
	K_diamonds.setTexture(diamondsK);
	cards.push_back(K_diamonds);

	heartsK.loadFromFile("src\\PNG\\Cards\\cardHeartsK.png");
	K_hearts.setTexture(heartsK);
	cards.push_back(K_hearts);

	clubsA.loadFromFile("src\\PNG\\Cards\\cardClubsA.png");
	A_clubs.setTexture(clubsA);
	cards.push_back(A_clubs);

	spadesA.loadFromFile("src\\PNG\\Cards\\cardSpadesA.png");
	A_spades.setTexture(spadesA);
	cards.push_back(A_spades);

	diamondsA.loadFromFile("src\\PNG\\Cards\\cardDiamondsA.png");
	A_diamonds.setTexture(diamondsA);
	cards.push_back(A_diamonds);

	heartsA.loadFromFile("src\\PNG\\Cards\\cardHeartsA.png");
	A_hearts.setTexture(heartsA);
	cards.push_back(A_hearts);

	return cards;
}

sf::Sprite load_background() {
	sf::Sprite fon;

	fon1.loadFromFile("C:\\Users\\св€зной\\workspace\\Coursera\\src\\PNG\\fon_game.jpg");
	fon.setTexture(fon1);

	return fon;
}

vector<sf::Text> load_texts() {
	if (!font.loadFromFile("C:\\Users\\св€зной\\workspace\\Coursera\\src\\PNG\\arial.ttf"))
		cout << "Font is no";

	play_text.setPosition(550, 300);
	play_text.setFillColor(sf::Color::Red);

	quit_text.setPosition(550, 400);
	quit_text.setFillColor(sf::Color::Red);
	return {play_text, quit_text};
}



