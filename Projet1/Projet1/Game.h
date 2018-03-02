#pragma once

#include <iostream>
#include <string>

#include "RessourceHolder.hpp"
//#include "AirCraft.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void EventProcessing(); // Gestion des evènements de la fenêtre (alt+f4, etc)
	void Update(sf::Time delaTime);
	void Render();
	void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void UpdateStatistics(sf::Time tempsEcoulee);
	 
private:
	sf::RenderWindow mWindow;
	sf::Sprite mAirplane;
	sf::Sprite mLandscape;
	sf::Text mStatsText;
	sf::Time mStatsUpdateTime;

	int mStatsNumFrames;
	bool mMovingUp = false;
	bool mMovingDown = false;
	bool mMovingLeft = false;
	bool mMovingRight = false;

	//TextureHolder mTexture;
	//FontsHolder mFont;

	AssetsManager<sf::Texture, Textures::ID> mTexture;
	AssetsManager<sf::Font, Fonts::ID> mFont;

	static const float PlayerSpeed;
	static const sf::Time TimePerFrame;
};

