#ifndef ENEM_H
#define ENEM_H
#include "GraphicObject.h"
#include "Character.h"

class Enemy: public GraphicObject
{
public:
	Enemy(Character enem):
	_enemyStats{enem}
	{
		_spriteInfo->textureLocation = "resources/PlayerShield.png";
		_spriteInfo->scale = sf::Vector2f{0.05f,0.05f};
	}
	virtual void Start() override; 
	virtual void Update() override;
private:
	void Move();
	void Initialise();
	
	Character _enemyStats;
};

#endif 