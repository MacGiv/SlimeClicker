#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H


namespace Slimes
{

enum class GAME_STATES { MENU, PAUSED, RUNNING, GAMEOVER, CREDITS };

struct GameStateMachine
{
	GAME_STATES currentState;
	GAME_STATES nextState;
};

} // namespace Slimes
#endif // !STATE_MACHINE_H




