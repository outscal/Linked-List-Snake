#include "../../include/Level/LevelService.h"
#include"../../include/Level/LevelController.h"
namespace Level {
	Level::LevelService::LevelService()
	{
		levelController = new LevelController();
	}
	void LevelService::Initialize()
	{
		levelController->Intialize();
	}
	void LevelService::Update()
	{
		levelController->Update();
	}
	void LevelService::Render()
	{
		levelController->Render();
	}
	LevelService::~LevelService()
	{
		delete(levelController);
	}
}
