#ifndef GAMEPLAY_1_H
#define GAMEPLAY_1_H

#include "StateMachine.h"

namespace Slimes
{

	void initializeGame(GameStateMachine& gameState);

	void updateGame(GameStateMachine& gameState);

	void drawGame();

	void closeGame();

} //namespace Slimes

#endif //GAMEPLAY_1_H

