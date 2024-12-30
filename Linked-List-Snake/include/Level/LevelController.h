#pragma once
#include "../../include/Level/LevelModel.h"
#include "../../include/Level/LevelView.h"
namespace Level
{
	class LevelController
	{

		LevelModel* level_model;
		LevelView* level_view;



	public:
		LevelController();
		void initialize();
		void update();
		void render();
		~LevelController();
		float getCellWidth();
		float getCellHeight();
	};
}