#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Bat {
	sf::RectangleShape shape;
	float speedX = 0.f;
};

void batInit(Bat& bat) {
	bat.shape.setSize(BAT_SIZE);
	bat.shape.setFillColor(BAT_COLOR);
	bat.shape.setPosition(BAT_START_POS);
}

void batReboundHorizontal(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { bat.shape.move(-5, 0); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { bat.shape.move(5, 0); }
	if (bat.shape.getPosition().x <= 0) {
		bat.shape.setPosition(0.f, WINDOW_HEIGHT - 2 * BAT_HEIGHT);
	}
	if (bat.shape.getPosition().x + BAT_WIDTH >= WINDOW_WIDTH) {
		bat.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, WINDOW_HEIGHT - 2 * BAT_HEIGHT);
	}
}
void batUpdate(Bat& bat) {
	batReboundHorizontal(bat);
}

void batDraw(sf::RenderWindow& window, Bat bat) {
	window.draw(bat.shape);
}