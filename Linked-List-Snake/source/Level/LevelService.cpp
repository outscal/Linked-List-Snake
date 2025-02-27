#include "../../include/Level/LevelService.h"

namespace Level
{



	void LevelService::createLevelController()
	{
		level_controller = new LevelController();
	}

	LevelService::LevelService()
	{
	
		level_controller = nullptr;
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	LevelService::~LevelService()
	{

		delete(level_controller);
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
	}

}