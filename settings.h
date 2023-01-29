#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float BAT_WIDTH = 100.f;
const float BAT_HEIGHT = 20.f;
const float BAT_OFFSET = 20.f;
const sf::Vector2f BAT_SIZE(100.f, 20.f);
const float BAT_SPEED = 5.f;
const sf::Color BAT_COLOR{ sf::Color::White };
const sf::Vector2f BAT_START_POS{ (WINDOW_WIDTH - BAT_WIDTH) / 2,
WINDOW_HEIGHT - BAT_OFFSET - BAT_HEIGHT };

const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ sf::Color::White};
const sf::Vector2f BALL_START_POS{
	(WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,
	(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2
};

const int CHAR_SIZE = 48;
const sf::Vector2f TEXT_START_POS{ 10.f, 0.f };

const float BRICK_WIDTH = 40.f;
const float BRICK_HEIGHT = 20.f;

const int ROWS = 8;
const int COLUMNS = 20;
float k = 160;
const float down = 900.f;
