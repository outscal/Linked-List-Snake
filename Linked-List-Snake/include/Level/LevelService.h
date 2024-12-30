#pragma once
#include "../../include/Level/LevelController.h"
#include "../../include/Level/LevelNumber.h"
namespace Level
{
	

	class LevelService
	{
		LevelNumber current_level;
		LevelController* level_controller;
		void createLevelController();
	public:
		LevelService();
		void initialize();
		void update();
		void render();
		~LevelService();


		void createLevel(LevelNumber level_to_load);
	};
}