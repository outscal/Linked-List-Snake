#pragma once
namespace Level
{
	class LevelController
	{
	public:
		LevelController();
		void initialize();
		void update();
		void render();
		~LevelController();
	};
}