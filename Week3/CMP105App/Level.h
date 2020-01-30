#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	sf::CircleShape circle;
	float speed1;
	sf::CircleShape circle1;
	float speed;
	sf::CircleShape circle2;
	float speed2;

	bool isMovingRight;
	bool isMovingUp;
	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	
};