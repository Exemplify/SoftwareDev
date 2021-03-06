#ifndef SPIRAL_ENEM_FAC_H
#define SPIRAL_ENEM_FAC_H
#include "EnemyFactory.h"

/**
 * @class SpiralEnemyFactory
 * @brief Generates an Enemy that has a Spiral Movement Pattern
 */
class SpiralEnemyFactory: public EnemyFactory
{
public:
	virtual std::shared_ptr<MovableInterface> getMovableType(const GameObjectData& data) override;
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
};

#endif