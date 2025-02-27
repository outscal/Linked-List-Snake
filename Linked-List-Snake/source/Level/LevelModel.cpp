#include "../../include/Level/LevelModel.h"

namespace Level
{



	LevelModel::LevelModel()
	{
	}

	LevelModel::~LevelModel()
	{
	}

	void LevelModel::initialize(int width, int height)
	{
		cell_width = width / number_of_rows;
		cell_height = height / number_of_rows;
	}

	float LevelModel::getCellWidth()
	{
		return cell_width;
	}

	float LevelModel::getCellHeight()
	{
		return  cell_height;
		
	}

}