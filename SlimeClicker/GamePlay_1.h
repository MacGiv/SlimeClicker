#ifndef GAMEPLAY_1_H
#define GAMEPLAY_1_H

#include <SFML/Graphics.hpp>

#include "StateMachine.h"

namespace Slimes
{

	void InitializeGame(GameStateMachine& gameState);

	void UpdateGame(GameStateMachine& gameState);

	void DrawGame(sf::RenderWindow& window);

	void CloseGame();

} //namespace Slimes

#endif //GAMEPLAY_1_H

