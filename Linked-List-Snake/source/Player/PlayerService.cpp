#include "../../include/Player/PlayerService.h"

namespace Player
{
	
	PlayerService::PlayerService()
	{
		snake_controller = nullptr;
		createController();
	}
	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}
	PlayerService::~PlayerService()
	{
		delete(snake_controller);
	}
	void PlayerService::initialize()
	{
		snake_controller->initialize();
	}
	void PlayerService::update()
	{
		snake_controller->update();
	}
	void PlayerService::render()
	{
		snake_controller->render();
	}
	void PlayerService::spawnPlayer()
	{
		snake_controller->spawnSnake();
	}
}