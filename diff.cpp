#include "diff.h"
diff::diff(float width, float hight)
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf")) {}

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Blue);
	mainMenu[0].setString("easy");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, hight / (Max_main_menu + 1)));

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("medium");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(sf::Vector2f(width / 2 - 50, hight / (Max_main_menu + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("hard");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(sf::Vector2f(width / 2 - 50, hight / (Max_main_menu + 1) * 3));

	mainMenuSelected = 0;
}

void diff::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++) {
		window.draw(mainMenu[i]);
	}
}

void diff::moveDown() {
	if (mainMenuSelected + 1 <= Max_main_menu) {
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3) {
			mainMenuSelected = 0;

		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);
	}
}
void diff::moveUp() {
	if (mainMenuSelected - 1 >= -1) {
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1) {
			mainMenuSelected = 2;

		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);
	}
}
