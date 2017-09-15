#include "Scene.h"

using gameObj_ptr = std::shared_ptr<GameObject>;

void Scene::SceneUpdate()
{
	for(auto GO : _gameObject_list)
	{
		GO->Update();
	}
}
const std::vector<gameObj_ptr> Scene::getGameObjectList()
{
	return _gameObject_list;
}