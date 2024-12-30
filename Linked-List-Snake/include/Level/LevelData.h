#pragma once
#include "../../include/Level/LevelService.h"
namespace Level
{
	enum  class LevelNumber;
	


	struct LevelData
	{
		LevelNumber level_index;

		LevelData(LevelNumber ind)
		{
			level_index = ind;
		}

		
	};

}