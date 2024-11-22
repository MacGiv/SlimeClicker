#include "SceneManager.h"
#include "GamePlay_1.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

namespace Slimes
{

GameStateMachine gameState;

static void Initialize();

static void Update(sf::Event event);

static void Draw(sf::RenderWindow& window);

static void Close();


void runProgram()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SlimeClicker");
	window.setSize(sf::Vector2u(800, 600));
	window.setFramerateLimit(60);


	Initialize();

	while (window.isOpen())
	{
		// El evento es como una entidad que maneja todo, a el le preguntas cosas como:
		// Evento, se apreto una tecla?  
		// Evento, se apreto el boton del mouse derecho?  
		// Evento, se cerro la ventana con la x de la esquina?? :O  
		// Si, todo se le pregunta, una vez creado es el que sabe como se hace todo lo importante  
		window.clear();

		sf::Event event;

		while (window.pollEvent(event))
		{

			Update(event);

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		Draw(window);
	}
	
	Close();
}

static void Initialize()
{
	InitializeGame(gameState);

	gameState.currentState = GAME_STATES::RUNNING;
	gameState.nextState = GAME_STATES::RUNNING;
}


static void Update(sf::Event event)
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
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "the left button was pressed" << std::endl;
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

static void Draw(sf::RenderWindow& window)
{
	window.clear();
	
	switch (gameState.currentState)
	{
	case Slimes::GAME_STATES::MENU:

		break;
	case Slimes::GAME_STATES::PAUSED:

		break;
	case Slimes::GAME_STATES::RUNNING:
		DrawGame(window);
		break;
	case Slimes::GAME_STATES::GAMEOVER:

		break;
	case Slimes::GAME_STATES::CREDITS:

		break;
	default:
		break;
	}

	window.display();


}

static void Close()
{
	//CloseWindow();
}

} // namespace Slimes