#pragma once


class Game
{
public:
	Game();
	void Run();
	
private:
	void Render();
	void ProcEvent();
	void Update();

	sf::RenderWindow window;
	sf::Texture background;
	sf::Sprite spriteback;

	Player player;
};


Game::Game()
	:window( sf::VideoMode(700, 550), "sdfDSF" )
{
	background.loadFromFile( "../FishGame/background.png" );
	spriteback.setTexture( background );
	spriteback.setPosition (0.f, 0.f );
}


void Game::Run()
{
	sf::Time time = sf::Time::Zero;
	sf::Time consttime = sf::seconds( 1.f/6000.f );
	sf::Clock clock;
	
	
	while ( window.isOpen() )
	{
		ProcEvent();
		time += clock.restart();
		while ( time > consttime )
		{
			time -= consttime;
			ProcEvent();
			Update();
		}
		Render();
	}
	
}

void Game::ProcEvent()
{
	sf::Event event;
	while ( window.pollEvent( event ))
	{
		switch ( event.type )
		{
		case sf::Event::KeyPressed:
			player.PressedKeyPlayer( event.key.code, true );
			break;
		case sf::Event::KeyReleased:
			player.PressedKeyPlayer( event.key.code, false );
			break;
		case sf::Event::Closed:
			window.close();
			}
	}

}

void Game::Update()
{
	player.PlayerRun();
}


void Game::Render()
{
	window.clear();
	
	window.draw( spriteback );
	window.draw( player.GetSpritePlayer() );
	window.display();
}


