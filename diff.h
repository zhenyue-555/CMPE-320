#pragma once
#define Max_main_menu 3
#include "SFML/Graphics.hpp"
class diff
{
public:
	diff(float width, float hight);
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	int mainMenuPressed() {
		return mainMenuSelected;
	}
private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
};