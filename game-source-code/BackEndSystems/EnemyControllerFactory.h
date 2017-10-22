#ifndef ENEM_CON_FAC_H
#define ENEM_CON_FAC_H
#include "GameObjectFactory.h"
#include "../FrontEndSystems/EnemyController.h"

/**
 * @class EnemyFactory
 * @brief EnemyControllerFactory is responsible for the construction of any EnemyController objects
 */
class EnemyControllerFactory: public GameObjectFactory
{
public:
	/**
	 * @brief Function call used to create an EnemyController Object 
	 * @return Returns an EnemyController Object with the specific characteristics for this game
	 */
	virtual std::shared_ptr<GameObject> getGameObject(const std::shared_ptr<DatabaseInterface>& database) override; 
	virtual GameObjectData getObjectData(const std::shared_ptr<DatabaseInterface>& database) override;
	virtual ~EnemyControllerFactory() {}
};

#endif