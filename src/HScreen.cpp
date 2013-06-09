#include "HScreen.h"

HScreen* HScreen::instance;
sf::Color HScreen::BACKGROUND_COLOR = sf::Color(255, 255, 255);
sf::View HScreen::view;

HScreen::HScreen()
{
	const float SCALE = 4;

	instance = this;
	screen = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window");
	view = sf::View(sf::Vector2f(SCREEN_WIDTH / 2 / SCALE, SCREEN_HEIGHT / 2 / SCALE), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	view.zoom(1/SCALE);
	screen->setView(view);
}


HScreen::~HScreen()
{
}

HScreen* HScreen::getInstance()
{
	return instance;
}

sf::RenderWindow* HScreen::getScreen()
{
	return getInstance()->screen;
}

void HScreen::setView(double centerX, double centerY)
{
    view.setCenter(static_cast<float>(centerX), static_cast<float>(centerY));
    HScreen::getScreen()->setView(view);
}

sf::View HScreen::getView()
{
    return view;
}
