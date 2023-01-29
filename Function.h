#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(BAT_SIZE);
	bat.setFillColor(BAT_COLOR);
	bat.setPosition(BAT_START_POS);
}


bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	float batX = bat.getPosition().x;
	float batY = bat.getPosition().y;
	return (point.x >= batX && point.x <= batX + BAT_WIDTH)
		&& (point.y >= batY && point.y <= batY + BAT_HEIGHT);
}