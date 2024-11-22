#ifndef SLIME_H
#define SLIME_H

#include <SFML/Graphics.hpp>

namespace Slimes 
{

struct Slime 
{
    sf::CircleShape circle;
    sf::Vector2f pos;
    sf::Vector2f velocity;
    bool isActive;
};

void InitializeSlime(Slime& slime, float radius, sf::Vector2f position, sf::Vector2f velocity);
void UpdateSlime(Slime& slime, float deltaTime);
void DrawSlime(Slime& slime, sf::RenderWindow& window);

} // namespace Slimes

#endif // SLIME_H
