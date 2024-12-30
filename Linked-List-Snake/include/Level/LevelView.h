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
		
	

	public:
		
		LevelView();
		void initialize();
		void update();
		void render();
		~LevelView();


		void initializeBackground();

	};
}