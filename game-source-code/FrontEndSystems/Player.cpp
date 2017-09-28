#include "Player.h"
#include "SpriteInfo.h"
#include "../BackEndSystems/GameTime.h"
#include "Projectile.h"

const double SHOOT_DELAY = 0.35; 
const double SHOOT_SPEED = 150;
Player::Player(Vector2D<double>& startPosition, Character playerStats):
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY}
{	
	_position = startPosition;
	auto playerBulletSprite = std::make_shared<SpriteInfo>();
	playerBulletSprite->textureLocation = "resources/Rock.png";
	playerBulletSprite->scale = Vector2f(0.05f,0.05f);
    _objectSize = 25;
	_type = GameObjectType::player;
	_shootComp = ShootComponent(playerBulletSprite, GameObjectType::playerBullet);
}
Player::Player(Vector2D<double>& startPosition, Character playerStats, std::shared_ptr<SpriteInfo> bulletSprite):
PhysicsObject(),
_playerStats{playerStats},
_shootDelay{SHOOT_DELAY},
_shootComp{bulletSprite, GameObjectType::playerBullet}
{
	_type = GameObjectType::player;
    _position = startPosition;
    _objectSize = 25;
}
void Player::Update()
{
	move();
	ShootConditionalCheck();
}

void Player::move()
{
	auto direc = Input::getAxis(Axis::horizontal);
	auto curPos = _position.rtpVector();
	curPos[1] += GameTime::getDeltaTime() * _playerStats.getMoveSpeed() * direc;
	Vector2D<double> newPos{curPos[0], curPos[1], curPos[2], VectorType::rtp};
    _position = newPos;

}
void Player::ShootConditionalCheck()
{
	_shootDelay.reduceTime();
	if(Input::IsButtonPressed(Keys::space) && _shootDelay.DelayFinished())
	{
		Vector2D<double> origin;
		_shootComp.Shoot(origin, _position, SHOOT_SPEED, *_scene);
		_shootDelay.resetDelay();
	}
}


void Player::collisionAction(GameObjectType objectType)
{
    if (objectType == GameObjectType::enemyBullet || objectType == GameObjectType::enemy)
        GameManager::LoadScene(3);
}