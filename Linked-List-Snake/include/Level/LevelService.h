#pragma once
#include "../../include/Level/LevelController.h"
#include "../../include/Level/LevelNumber.h"

namespace Level
{
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void spawnPlayer();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_load);
		float getCellWidth();
		float getCellHeight();
	};
}