#include "GamePlay_1.h"
#include "GameConstants.h"
#include "Slime.h"

namespace Slimes
{

const int slimeAmount = 10;
Slime slimes[slimeAmount];

static void checkCollisionPointCircle();


void InitializeGame(GameStateMachine& gameState)
{
    srand(static_cast<unsigned>(time(0)));

    InitializeAllSlimes();

}

void InitializeAllSlimes()
{
    int radius = 20;
    for (int i = 0; i < slimeAmount; i++)
    {
        float randomX = rand() % (SCREEN_WIDTH - (radius * 2)); // Evitar bordes (radio * 2)
        float randomY = rand() % (SCREEN_HEIGHT - (radius * 2));
        sf::Vector2f randomPos = { randomX, randomY };
        sf::Vector2f randomVelocity = { static_cast<float>(rand() % 10), static_cast<float>(rand() % 10) };

        InitializeSlime(slimes[i], static_cast<float>(radius), randomPos, randomVelocity);
    }
}

void UpdateGame(GameStateMachine& gameState)
{
    for (int i = 0; i < slimeAmount; i++)
    {
        UpdateSlime(slimes[i]);
    }
    //updateSlimes(slimes);
    //checkMouseSlimeCollision();
}

void DrawGame(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);

    // Draw slimes
    for (int i = 0; i < slimeAmount; i++)
    {
        if (slimes[i].isActive)
        {
            DrawSlime(slimes[i], window);
        }
    }
}

void CloseGame()
{

}



static void checkCollisionPointCircle()
{
    
}

} //namespace Slimes