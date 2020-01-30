#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;


	circle.setRadius(30);
	circle.setPosition(1, 550);
	circle.setFillColor(sf::Color::Green);
	speed1 = 100.f;

	circle1.setRadius(30);
	circle1.setPosition(1, 200);
	circle1.setFillColor(sf::Color::Magenta);
	speed = 100.f;

	circle2.setRadius(30);
	circle2.setPosition(1, 20);
	circle2.setFillColor(sf::Color::Black);
	speed2 = 200.f;

	// initialise game objects

}

Level::~Level()
{
}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up)) 
	{
		
		if (circle1.getPosition().y > 0) 
		{
			circle1.move(0, speed * dt * (-1));
		}
	
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{

		if (circle1.getPosition().y + (2*circle1.getRadius()) < window->getSize().y)
		{
			circle1.move(0, speed * dt);
		}

	}

	if (input->isKeyDown(sf::Keyboard::Right))
	{

		if (circle1.getPosition().x + (2 * circle1.getRadius()) < window->getSize().x) 
		{
			circle1.move(speed * dt, 0);
		}

	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{

		if (circle1.getPosition().x > 0)
		{
			circle1.move(speed * dt*(-1), 0);
		}

	}

	if (input->isKeyDown(sf::Keyboard::Add))
	{

		speed2++;

	}
	if (input->isKeyDown(sf::Keyboard::Subtract))
	{

		speed2--;

	}
}

// Update game objects
void Level::update(float dt)

{

	//isMovingRight

	//isMovingUp

	if (isMovingRight == true) 
	{
		circle2.move(speed2 * dt, 0);
	}
	else 
	{
		circle2.move(speed2 * dt*(-1), 0);
	}

	if (isMovingUp == true)
	{
		circle2.move(0,speed2 * dt*(-1));
	}
	else
	{
		circle2.move(0,speed2 * dt );
	}

	if (circle2.getPosition().x + (2 * circle2.getRadius()) > window->getSize().x )
	{
		isMovingRight = false;
	}
	else if (circle2.getPosition().x <0) 
	{
	
		isMovingRight = true;
	}

	if (circle2.getPosition().y + (2 * circle2.getRadius()) > window->getSize().y)
	{
		isMovingUp = true;
	}
	else if (circle2.getPosition().y < 0) 
	{
		isMovingUp = false;
	}


	if (circle.getPosition().x + (2 * circle.getRadius()) > window->getSize().x || circle.getPosition().x < 0)
	{
		speed1 *= (-1);
	}

	circle.move(speed1* dt, 0);
}
// Render level
void Level::render()
{
	beginDraw();

	window->draw(circle);
	window->draw(circle1);
	window->draw(circle2);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}