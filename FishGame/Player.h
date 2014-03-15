#pragma once


class Player
{
public:
	Player();
	sf::Sprite GetSpritePlayer();
	void PressedKeyPlayer( sf::Keyboard::Key key, bool BOOL );
	void PlayerRun();

private:
	sf::Texture texture;
	sf::Sprite playersprite;
	float speed;
	bool left, up, right, down;
	sf::Time time;

};


Player::Player()
{
	left = up = right = down = false;
	speed = 300;
	time = sf::seconds( 1.f/6000.f );
	texture.loadFromFile( "../FishGame/Cat.png" );
	playersprite.setTexture( texture );
	playersprite.setPosition( 300.f, 450.f );
}


sf::Sprite Player::GetSpritePlayer()
{
	return playersprite;
}

void Player::PressedKeyPlayer( sf::Keyboard::Key key, bool BOOL )
{
	if ( key == sf::Keyboard::W )
		up = BOOL;
	if ( key == sf::Keyboard::D )
		right = BOOL;
	if ( key == sf::Keyboard::S )
		down = BOOL;
	if ( key == sf::Keyboard::A )
		left = BOOL;

}

void Player::PlayerRun()
{
	sf::Vector2f movement(0.f,0.f);

	if ( up )
		movement.y -=speed;
	if ( right )
		movement.x +=speed;
	if ( down )
		movement.y +=speed;
	if ( left )
		movement.x -=speed;

	playersprite.move( movement * time.asSeconds() );
}