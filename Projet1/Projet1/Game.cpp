#include "Game.h"

const float Game::PlayerSpeed = 200;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Z-RPG")
{
	//Synchro vertical
	mWindow.setVerticalSyncEnabled(true);
	try
	{		
		mTexture.Load(Textures::Lanscape, "Desert.png");
		mTexture.Load(Textures::Airplane, "Eagle.png");
		mFont.Load(Fonts::Menu, "Sansation.ttf");
	}
	catch (std::runtime_error& e)
	{
		std::cout << "Exception :" << e.what() << std::endl;
	}
	mAirplane.setTexture(mTexture.Get(Textures::Airplane));

	sf::Vector2u planePosition;
	planePosition = mTexture.Get(Textures::Airplane).getSize();

	mAirplane.setOrigin(sf::Vector2f(planePosition.x / 2., planePosition.y / 2));
	mAirplane.setPosition(mWindow.getSize().x / 2., mWindow.getSize().y / 2);
	
	mLandscape.setTexture(mTexture.Get(Textures::Lanscape));

	mStatsText.setFont(mFont.Get(Fonts::Menu));
	mStatsText.setCharacterSize(22);
	mStatsText.setPosition(sf::Vector2f(32.f, 32.f));
}

Game::~Game()
{
	mWindow.close();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		EventProcessing();
		sf::Event event;
		sf::Time timeSinceLastUpdate = clock.restart();
		
		timeSinceLastUpdate += TimePerFrame;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			Update(timeSinceLastUpdate);
		}
		UpdateStatistics(timeSinceLastUpdate);
		Render();
	}
}

void Game::EventProcessing()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;
		default:
			break;
		}
	}
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Z)
		mMovingUp = isPressed;
	if (key == sf::Keyboard::S)
		mMovingDown = isPressed;
	if (key == sf::Keyboard::Q)
		mMovingLeft = isPressed;
	if (key == sf::Keyboard::D)
		mMovingRight = isPressed;
}

void Game::Update(sf::Time delaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (mMovingUp)
		movement.y -= PlayerSpeed;
	if (mMovingDown)
		movement.y += PlayerSpeed;
	if (mMovingLeft)
		movement.x -= PlayerSpeed;
	if (mMovingRight)
		movement.x += PlayerSpeed;

	mAirplane.move(movement * delaTime.asSeconds());
}

void Game::UpdateStatistics(sf::Time tempsEcoulee)
{
	mStatsUpdateTime += tempsEcoulee;
	mStatsNumFrames += 1;

	if (mStatsUpdateTime >= sf::seconds(1.0f))
	{
		mStatsText.setString(
			"Frames / Second = " + std::to_string(mStatsNumFrames) + "\n" +
			"Time / Update = " + std::to_string((mStatsUpdateTime.asMicroseconds() / mStatsNumFrames)) + "us");

		mStatsUpdateTime -= sf::seconds(1.0f);
		mStatsNumFrames = 0;
	}
}

void Game::Render()
{
	mWindow.clear();
	mWindow.draw(mLandscape);
	mWindow.draw(mAirplane);
	mWindow.draw(mStatsText);
	mWindow.display();
}