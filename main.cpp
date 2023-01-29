#include "settings.h" 
#include "Function.h" 
#include "Textobj.h" 
#include "BALL.h" 
#include "BAT.h" 
#include <ctime>
#include "brickRow.h"
#include "Break.h" 
using namespace sf;
int main()
{
		srand(time(nullptr));
		RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
		window.setFramerateLimit(FPS);
		Ball ball;
		ballInit(ball);
		Bat bat;
		batInit(bat);
		TextObj scoreText;
		textInit(scoreText, ball.score);
		BrickField field;
		brickFieldInint(field);
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if (ball.shape.getPosition().y >= (WINDOW_HEIGHT - 2 * BALL_RADIUS)) {
				ball.speedy = -ball.speedy;
				window.close();
			}
				if (k <= 0) {
					window.close();
				}
			ballUpdate(ball);
			textUpdate(scoreText, ball.score);
			batUpdate(bat);
			brickFieldUpdate(field);

			float ballX = ball.shape.getPosition().x;
			float ballY = ball.shape.getPosition().y;

			Vector2f midTop{ ballX + BALL_RADIUS, ballY };
			Vector2f midLeft{ ballX , ballY + BALL_RADIUS };
			Vector2f midBottom{ ballX + BALL_RADIUS, ballY + 2 * BALL_RADIUS };
			Vector2f midRight{ ballX + 2 * BALL_RADIUS, ballY + BALL_RADIUS };
			if (pointInRect(bat.shape, midLeft)) {
				ball.speedx = -ball.speedx;
				ball.score++;
			}
			if (pointInRect(bat.shape, midRight)) {
				ball.speedx = -ball.speedx;
				ball.score++;
			}
			if (pointInRect(bat.shape, midBottom)) {
				ball.speedy = -ball.speedy;
				ball.score++;
			}
			if (pointInRect(bat.shape, midTop)) {
				ball.speedy = -ball.speedy;
				ball.score++;
			}

			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					if (pointInRect(field.arr[i][j].shape, midBottom)) {
						ball.speedy = -ball.speedy;
						field.arr[i][j].shape.move(0.f, down);
						k--;
					}
					if (pointInRect(field.arr[i][j].shape, midTop)) {
						ball.speedy = -ball.speedy;
						field.arr[i][j].shape.move(0.f, down);
						k--;
					}
				}
			}
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					if (pointInRect(field.arr[i][j].shape, midLeft)) {
						ball.speedy = -ball.speedy;
						field.arr[i][j].shape.move(0.f, down);
						k--;
					}
					if (pointInRect(field.arr[i][j].shape, midRight)) {
						ball.speedy = -ball.speedy;
						field.arr[i][j].shape.move(0.f, down);
						k--;
					}
				}
			}

			window.clear();
			
			batDraw(window, bat);
			textDraw(window, scoreText);
			brickFieldDraw(window, field);
			ballDraw(window, ball);
			
			window.display();
		}
		return 0;
	}