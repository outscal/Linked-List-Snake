#include "../../include/Level/LevelController.h"
namespace Level
{

	Level::LevelController::LevelController()
	{

		level_model = new LevelModel();
		level_view = new LevelView();
	}

	void Level::LevelController::initialize()
	{
		level_view->initialize();
		level_model->initialize(level_view->getGridWidth(), level_view->getGridHeight());
	}

	void Level::LevelController::update()
	{
		level_view->update();
	}

	void Level::LevelController::render()
	{
		level_view->render();
	}

	Level::LevelController::~LevelController()
	{
		delete level_model;
		delete level_view;
	}

	float LevelController::getCellWidth()
	{
		return level_model->getCellWidth();
	}

	float LevelController::getCellHeight()
	{
		return level_model->getCellHeight();
	}

}
