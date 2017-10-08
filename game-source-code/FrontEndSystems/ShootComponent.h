#ifndef SHOOT_H
#define SHOOT_H
#include "../Vector2D.hpp"
#include "Scene.h"
#include "Projectile.h"

class ShootComponent
{
public:
	/// redundant Constructors that do not conform to the class invariance
	ShootComponent(){}
	/// will be removed once the Template projectile is set up
	ShootComponent(const std::shared_ptr<GraphicObject>& bulletGraphic, GameObjectType bulletType);
	/// correct constructor 
	ShootComponent(std::shared_ptr<Projectile> bullet);
	// Creates a projectile in the specified scene with the provided parameters to meet the components
	/// Scene needs to be moved into the constructor should be the current scene (use of Application Class)
	void Shoot(
		Vector2D<double> target,
		Vector2D<double> startPosition, 
		double shootSpeed,
		Scene& scene
		);
private:
	// the projectile that is copied
	std::shared_ptr<Projectile> _bullet;
	/// Shot speed needs to be part of the shoot component
};

#endif