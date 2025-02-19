#pragma once
#include"../../include/Level/LevelNumber.h"
namespace Level {
	class LevelController;
	class LevelService {
	private:
		; LevelController* levelController;
	public:
		LevelService();
		void Initialize();
		void Update();
		void Render();
		~LevelService();
	};
}