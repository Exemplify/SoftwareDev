#ifndef PROJ_H
#define PROJ_H
#include "GraphicObject.h"

class Projectile: public GraphicObject
{
public:
	Projectile(std::shared_ptr<SpriteInfo> spriteInfo);
	Projectile(const Projectile& copyProjectile);
	virtual void Update() override;
	void Initialise(Vector2D<double> startingPos, Vector2D<double> direction, double moveSpeed);
private:
	Vector2D<double> _direction;
	double _moveSpeed;
	void DestroySelf();
	void Move();
};

#endif
