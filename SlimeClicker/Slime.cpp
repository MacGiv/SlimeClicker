#include "Slime.h"
#include "GameConstants.h"


namespace Slimes 
{

void InitializeSlime(Slime& slime, float radius, sf::Vector2f position, sf::Vector2f velocity) 
{
    slime.circle.setRadius(radius);
    slime.circle.setFillColor(sf::Color::Cyan);
    slime.circle.setPosition(position);
    slime.pos = position;
    slime.velocity = velocity;
    slime.isActive = true;
}

void UpdateSlime(Slime& slime) 
{
    if (slime.isActive)
    {
        slime.pos += slime.velocity; // * deltaTime
        slime.circle.setPosition(slime.pos);

        float radius = slime.circle.getRadius();

        if (slime.pos.x < 0 || slime.pos.x > SCREEN_WIDTH - radius * 2 ||
            slime.pos.y < 0 || slime.pos.y > SCREEN_HEIGHT - radius * 2)
        {
            slime.isActive = false;
        }
    }
     

    
}

void DrawSlime(Slime& slime, sf::RenderWindow& window) 
{
    if (slime.isActive) 
    {
        window.draw(slime.circle);
    }
}

} // namespace Slimes