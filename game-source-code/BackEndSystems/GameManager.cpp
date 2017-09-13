#include "GameManager.h"

GameManager::GameManager():
_gameWindow(),
_dispManager(&_gameWindow),
_eventManager(&_gameWindow)
{
	// Creates the initial sfml window 
	_gameWindow.create(
		VideoMode(_defaultSetup.screenWidth,_defaultSetup.screenHeight),
		_defaultSetup.game_name);
		
	// Sets the game window to be inactive so that the display
	// can be done in a seperate thread
	
	_gameWindow.setVerticalSyncEnabled(true);
    _gameWindow.setActive(false);
}
void GameManager::GameLoop()
{
	// initialise physics and display threads 
	_dispManager.InitialiseThread();
	
	while (_gameWindow.isOpen())
	{
		_eventManager.EventLoop();
		
	}
}

