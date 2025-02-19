#pragma once
#include"SFML/Graphics.hpp"
#include"UI/UIElement/RectangleShapeView.h"
namespace Level {
	class LevelView {
	private:
		sf::Color backGroundColor = sf::Color(255, 218, 185);
		UI::UIElement::RectangleShapeView* backGroundRectangle;
		void IntializeImage();
	public:
		LevelView();
		void Intialize();
		void Update();
		void Render();
		~LevelView();
	};
}