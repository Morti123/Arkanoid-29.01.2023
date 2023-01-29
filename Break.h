#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};

void brickInit(Brick& brick, sf::Color color, sf::Vector2f position) {
	brick.color = color;
	brick.position = position;
	brick.shape.setSize(sf::Vector2f{ BRICK_WIDTH, BRICK_HEIGHT });
	brick.shape.setFillColor(brick.color);
	brick.shape.setPosition(brick.position);
	brick.shape.setOutlineColor(sf::Color::Black);
	brick.shape.setOutlineThickness(1.f);
}

void brickUpdate(Brick& brick) {

}

void brickDraw(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}