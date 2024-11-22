#include "SceneManager.h"
#include <SFML/Window.hpp>
#include <iostream>

namespace Slimes
{

GameStateMachine gameState;

static void initialize();

static void update(sf::Event event);

static void draw();

static void close();


void runProgram()
{
	sf::Window window(sf::VideoMode(800, 600), "SlimeClicker");
	window.setSize(sf::Vector2u(800, 600));
	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{

			initialize();

			update(event);

			draw();

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	
	
	close();
}

static void initialize()
{
	//InitWindow(800, 600, "BOKITA");

	//initializeMenu(gameState);
	//initializeGame(gameState);

	gameState.currentState = GAME_STATES::RUNNING;
	gameState.nextState = GAME_STATES::RUNNING;
}


static void update(sf::Event event)
{
	switch (gameState.currentState)
	{
	case Slimes::GAME_STATES::MENU:
		
		break;
	case Slimes::GAME_STATES::PAUSED:

		break;
	case Slimes::GAME_STATES::RUNNING:
		if (event.type == sf::Event::KeyPressed)
		{
			std::cout << "the escape key was pressed" << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "the right button was pressed" << std::endl;
				std::cout << "mouse x: " << event.mouseButton.x << std::endl;
				std::cout << "mouse y: " << event.mouseButton.y << std::endl;
			}
		}

		break;
	case Slimes::GAME_STATES::GAMEOVER:

		break;
	case Slimes::GAME_STATES::CREDITS:

		break;
	default:
		break;
	}

	gameState.currentState = gameState.nextState;
}

static void draw()
{
	switch (gameState.currentState)
	{
	case Slimes::GAME_STATES::MENU:

		break;
	case Slimes::GAME_STATES::PAUSED:

		break;
	case Slimes::GAME_STATES::RUNNING:

		break;
	case Slimes::GAME_STATES::GAMEOVER:

		break;
	case Slimes::GAME_STATES::CREDITS:

		break;
	default:
		break;
	}
}

static void close()
{
	//CloseWindow();
}

} // namespace Slimes