#include "LDraw.h"

void LDraw::DrawRect(double x, double y, double w, double h, sf::Color color)
{
	sf::RectangleShape rect(sf::Vector2f(static_cast<float>(w), static_cast<float>(h)));
	rect.setFillColor(color);
	rect.setPosition(static_cast<float>(x), static_cast<float>(y));
	HScreen::getScreen()->draw(rect);
}
void LDraw::DrawCircle(double x, double y, double r, sf::Color color)
{
	sf::CircleShape circle(static_cast<float>(r));
	circle.setFillColor(color);
	circle.setPosition(static_cast<float>(x), static_cast<float>(y));
    HScreen::getScreen()->draw(circle);
}

void LDraw::DrawImage(sf::Image* img, double x, double y)
{
    sf::Texture tex;
	tex.loadFromImage(*img);
	sf::Sprite s;
	s.setTexture(tex, true);
	s.setPosition(static_cast<float>(x), static_cast<float>(y));
    HScreen::getScreen()->draw(s);
}

void LDraw::DrawSprite(Spr* spr, double imageIndex, double x, double y)
{
    sf::Sprite s;
	s.setTexture(*(spr->tex), true);
	s.setPosition(static_cast<float>(x - spr->origX), static_cast<float>(y - spr->origY));
	s.setTextureRect(sf::IntRect(static_cast<int>(imageIndex * spr->imageWidth), 0, static_cast<int>((imageIndex + 1) * spr->imageWidth), spr->imageHeight));
    HScreen::getScreen()->draw(s);
}
