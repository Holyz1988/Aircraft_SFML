#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	void SetVelocity(sf::Vector2f velocity);
	void SetVelocity(float velocityX, float velocityY);
	sf::Vector2f GetVelocity();
private:
	sf::Vector2f mVelocity;
};

#include "Entity.inl"
