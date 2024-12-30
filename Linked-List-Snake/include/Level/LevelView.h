#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/RectangleShapeView.h"
namespace Level
{
	using namespace UI;
	using namespace UI::UIElement;
	class LevelView
	{

		const sf::Color background_color = sf::Color(180, 200, 160);
		RectangleShapeView* background_rectangle;
		sf::Color border_color = sf::Color::Black;
		float grid_width;
		float grid_height;

		RectangleShapeView* border_rectangle;

	public: 
		


		static const int border_thickness = 10;
		static const int border_offset_left = 40;
		static const int border_offset_top = 40;



		LevelView();
		void initialize();
		void update();
		void render();
		~LevelView();
		float getGridWidth();
		float getGridHeight();
		void initializeBorder();
		void calculateGridExtents();
		void initializeBackground();

	};
}