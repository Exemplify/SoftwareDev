#include "GameObject.h"
#include "Scene.h"

// default constructor ensures that every gameobject has a type
GameObject::GameObject(): 
_type{GameObjectType::gameObject}
{}
// copy constructor
GameObject::GameObject(const GameObject& copyObj)
{
	_type = copyObj._type;
	_position = copyObj._position;
	_active = copyObj._active;
	_scene = copyObj._scene;
}
// takes in the starting position for the gameobject 
GameObject::GameObject(Vector2D<double> startingPosition): 
_type{GameObjectType::gameObject},
_position{startingPosition}
{}
// Removes the gameobject from the scene that it exists in
void GameObject::Destroy()
{
	if(_scene != NULL)
	{
		std::shared_ptr<GameObject> thisObj = shared_from_this();
		_scene->DestroyGameObject(thisObj);
	}
	else
	{
		throw(DestroyedObjectOutsideScene());
	}
}
const GraphicObject& GameObject::getGraphicObject() const
{
	return _graphicObject;
} 
// checks the list of gameObjects inside the current scene and returns the first gameobject that matches the GameObjectType
std::shared_ptr<GameObject> GameObject::FindGameObjectByType(GameObjectType searchType)
{
	auto gameObjList = _scene->getGameObjectList();
	/// could be replaced with a std find
	for(auto& GO: gameObjList)
	{
		if(GO->getType() == searchType)
			return GO;
	}
	// returns a NULL pointer if the object is not found
	return NULL;
}