#ifndef SPR_INF_H
#define SPR_INF_H

#include <string>
#include <SFML/Graphics.hpp>
/// need to remove the sf namespace, loads too much information that doesnt get used
using namespace sf;
/// Neeeds complete Restructuring 
/// SpriteInfo should be form part of the DisplayManager and SpriteData should be part of the Gameobject
struct SpriteInfo
{
	Sprite sprite;
	Texture texture;
};


#endif 