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
sf::Text win_text("You are a winner!", font, 50);
sf::Text lose_text("You are a loser!", font, 50);
sf::Text no_winners("Whoo! No winners!", font, 50);
sf::Text confirmation_text("Are you sure? Y/N", font, 50);
sf::Text controller_text("Info", font, 50);
sf::Text setting_1("Finish a round  <<Enter>>", font, 50);
sf::Text setting_2("Take cards  <<R>>", font, 50);
sf::Texture cardBack1;

vector<Card>  load() {
	vector<Card> cards;

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
	Card new_six_1(6, "clubs", six_clubs);
	cards.push_back(new_six_1);

	spades6.loadFromFile("src\\PNG\\Cards\\cardSpades6.png");
	six_spades.setTexture(spades6);
	Card new_six_2(6, "spades", six_spades);
	cards.push_back(new_six_2);

	diamonds6.loadFromFile("src\\PNG\\Cards\\cardDiamonds6.png");
	six_diamonds.setTexture(diamonds6);
	Card new_six_3(6, "diamonds", six_diamonds);
	cards.push_back(new_six_3);

	hearts6.loadFromFile("src\\PNG\\Cards\\cardHearts6.png");
	six_hearts.setTexture(hearts6);
	Card new_six_4(6, "hearts", six_hearts);
	cards.push_back(new_six_4);

	clubs7.loadFromFile("src\\PNG\\Cards\\cardClubs7.png");
	seven_clubs.setTexture(clubs7);
	Card new_seven_1(7, "clubs", seven_clubs);
	cards.push_back(new_seven_1);

	spades7.loadFromFile("src\\PNG\\Cards\\cardSpades7.png");
	seven_spades.setTexture(spades7);
	Card new_seven_2(7, "spades", seven_spades);
	cards.push_back(new_seven_2);

	diamonds7.loadFromFile("src\\PNG\\Cards\\cardDiamonds7.png");
	seven_diamonds.setTexture(diamonds7);
	Card new_seven_3(7, "diamonds", seven_diamonds);
	cards.push_back(new_seven_3);

	hearts7.loadFromFile("src\\PNG\\Cards\\cardHearts7.png");
	seven_hearts.setTexture(hearts7);
	Card new_seven_4(7, "hearts", seven_hearts);
	cards.push_back(new_seven_4);

	clubs8.loadFromFile("src\\PNG\\Cards\\cardClubs8.png");
	eight_clubs.setTexture(clubs8);
	Card new_eight_1(8, "clubs", eight_clubs);
	cards.push_back(new_eight_1);

	spades8.loadFromFile("src\\PNG\\Cards\\cardSpades8.png");
	eight_spades.setTexture(spades8);
	Card new_eight_2(8, "spades", eight_spades);
	cards.push_back(new_eight_2);

	diamonds8.loadFromFile("src\\PNG\\Cards\\cardDiamonds8.png");
	eight_diamonds.setTexture(diamonds8);
	Card new_eight_3(8, "diamonds", eight_diamonds);
	cards.push_back(new_eight_3);

	hearts8.loadFromFile("src\\PNG\\Cards\\cardHearts8.png");
	eight_hearts.setTexture(hearts8);
	Card new_eight_4(8, "hearts", eight_hearts);
	cards.push_back(new_eight_4);

	clubs9.loadFromFile("src\\PNG\\Cards\\cardClubs9.png");
	nine_clubs.setTexture(clubs9);
	Card new_nine_1(9, "clubs", nine_clubs);
	cards.push_back(new_nine_1);

	spades9.loadFromFile("src\\PNG\\Cards\\cardSpades9.png");
	nine_spades.setTexture(spades9);
	Card new_nine_2(9, "spades", nine_spades);
	cards.push_back(new_nine_2);

	diamonds9.loadFromFile("src\\PNG\\Cards\\cardDiamonds9.png");
	nine_diamonds.setTexture(diamonds9);
	Card new_nine_3(9, "diamonds", nine_diamonds);
	cards.push_back(new_nine_3);

	hearts9.loadFromFile("src\\PNG\\Cards\\cardHearts9.png");
	nine_hearts.setTexture(hearts9);
	Card new_nine_4(9, "hearts", nine_hearts);
	cards.push_back(new_nine_4);

	clubs10.loadFromFile("src\\PNG\\Cards\\cardClubs10.png");
	ten_clubs.setTexture(clubs10);
	Card new_ten_1(10, "clubs", ten_clubs);
	cards.push_back(new_ten_1);

	spades10.loadFromFile("src\\PNG\\Cards\\cardSpades10.png");
	ten_spades.setTexture(spades10);
	Card new_ten_2(10, "spades", ten_spades);
	cards.push_back(new_ten_2);

	diamonds10.loadFromFile("src\\PNG\\Cards\\cardDiamonds10.png");
	ten_diamonds.setTexture(diamonds10);
	Card new_ten_3(10, "diamonds", ten_diamonds);
	cards.push_back(new_ten_3);

	hearts10.loadFromFile("src\\PNG\\Cards\\cardHearts10.png");
	ten_hearts.setTexture(hearts10);
	Card new_ten_4(10, "hearts", ten_hearts);
	cards.push_back(new_ten_4);

	clubsJ.loadFromFile("src\\PNG\\Cards\\cardClubsJ.png");
	J_clubs.setTexture(clubsJ);
	Card new_J_1(11, "clubs", J_clubs);
	cards.push_back(new_J_1);

	spadesJ.loadFromFile("src\\PNG\\Cards\\cardSpadesJ.png");
	J_spades.setTexture(spadesJ);
	Card new_J_2(11, "spades", J_spades);
	cards.push_back(new_J_2);

	diamondsJ.loadFromFile("src\\PNG\\Cards\\cardDiamondsJ.png");
	J_diamonds.setTexture(diamondsJ);
	Card new_J_3(11, "diamonds", J_diamonds);
	cards.push_back(new_J_3);

	heartsJ.loadFromFile("src\\PNG\\Cards\\cardHeartsJ.png");
	J_hearts.setTexture(heartsJ);
	Card new_J_4(11, "hearts", J_hearts);
	cards.push_back(new_J_4);

	clubsQ.loadFromFile("src\\PNG\\Cards\\cardClubsQ.png");
	Q_clubs.setTexture(clubsQ);
	Card new_Q_1(12, "clubs", Q_clubs);
	cards.push_back(new_Q_1);

	spadesQ.loadFromFile("src\\PNG\\Cards\\cardSpadesQ.png");
	Q_spades.setTexture(spadesQ);
	Card new_Q_2(12, "spades", Q_spades);
	cards.push_back(new_Q_2);

	diamondsQ.loadFromFile("src\\PNG\\Cards\\cardDiamondsQ.png");
	Q_diamonds.setTexture(diamondsQ);
	Card new_Q_3(12, "diamonds", Q_diamonds);
	cards.push_back(new_Q_3);

	heartsQ.loadFromFile("src\\PNG\\Cards\\cardHeartsQ.png");
	Q_hearts.setTexture(heartsQ);
	Card new_Q_4(12, "hearts", Q_hearts);
	cards.push_back(new_Q_4);

	clubsK.loadFromFile("src\\PNG\\Cards\\cardClubsK.png");
	K_clubs.setTexture(clubsK);
	Card new_K_1(13, "clubs", K_clubs);
	cards.push_back(new_K_1);

	spadesK.loadFromFile("src\\PNG\\Cards\\cardSpadesK.png");
	K_spades.setTexture(spadesK);
	Card new_K_2(13, "spades", K_spades);
	cards.push_back(new_K_2);

	diamondsK.loadFromFile("src\\PNG\\Cards\\cardDiamondsK.png");
	K_diamonds.setTexture(diamondsK);
	Card new_K_3(13, "diamonds", K_diamonds);
	cards.push_back(new_K_3);

	heartsK.loadFromFile("src\\PNG\\Cards\\cardHeartsK.png");
	K_hearts.setTexture(heartsK);
	Card new_K_4(13, "hearts", K_hearts);
	cards.push_back(new_K_4);

	clubsA.loadFromFile("src\\PNG\\Cards\\cardClubsA.png");
	A_clubs.setTexture(clubsA);
	Card new_A_1(14, "clubs", A_clubs);
	cards.push_back(new_A_1);

	spadesA.loadFromFile("src\\PNG\\Cards\\cardSpadesA.png");
	A_spades.setTexture(spadesA);
	Card new_A_2(14, "spades", A_spades);
	cards.push_back(new_A_2);

	diamondsA.loadFromFile("src\\PNG\\Cards\\cardDiamondsA.png");
	A_diamonds.setTexture(diamondsA);
	Card new_A_3(14, "diamonds", A_diamonds);
	cards.push_back(new_A_3);

	heartsA.loadFromFile("src\\PNG\\Cards\\cardHeartsA.png");
	A_hearts.setTexture(heartsA);
	Card new_A_4(14, "hearts", A_hearts);
	cards.push_back(new_A_4);

	return cards;
}

vector<sf::Sprite> load_background() {
	sf::Sprite fon;
	vector<sf::Sprite> fons;

	fon1.loadFromFile("C:\\Users\\св€зной\\workspace\\Coursera\\src\\PNG\\fon_game.jpg");
	fon.setTexture(fon1);

	fons.push_back(fon);

	return fons;
}

vector<sf::Text> load_texts() {
	if (!font.loadFromFile("C:\\Users\\св€зной\\workspace\\Coursera\\src\\PNG\\arial.ttf"))
		cout << "Font is no";

	play_text.setPosition(550, 200);
	play_text.setFillColor(sf::Color::Cyan);

	win_text.setPosition(500, 300);
	win_text.setFillColor(sf::Color::Green);

	lose_text.setPosition(500, 300);
	lose_text.setFillColor(sf::Color::Red);

	quit_text.setPosition(550, 400);
	quit_text.setFillColor(sf::Color::Red);

	controller_text.setPosition(550, 300);
	controller_text.setFillColor(sf::Color::Blue);

	setting_1.setPosition(500, 300);
	setting_1.setFillColor(sf::Color::Blue);

	setting_2.setPosition(500, 400);
	setting_2.setFillColor(sf::Color::Blue);

	no_winners.setPosition(500, 300);
	no_winners.setFillColor(sf::Color::Yellow);

	confirmation_text.setPosition(500, 300);
	confirmation_text.setFillColor(sf::Color::Red);

	return {play_text, quit_text, controller_text, setting_1, setting_2,
		win_text, lose_text, confirmation_text, no_winners};
}

vector<sf::Sprite> load_cardsBack() {
	sf::Sprite cardBack;

	cardBack1.loadFromFile("C:\\Users\\св€зной\\workspace\\Coursera\\src\\PNG\\Cards\\cardBack_blue1.png");
	cardBack.setTexture(cardBack1);
	return {cardBack};
}



