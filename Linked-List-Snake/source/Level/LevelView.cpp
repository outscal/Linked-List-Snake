#include "Global/ServiceLocator.h"
#include "../../include/Level/LevelView.h"

namespace Level
{
	using namespace UI::UIElement;
	using namespace Global;

	LevelView::LevelView()
	{
		background_rectangle = new RectangleShapeView();
	}

	void LevelView::initialize()
	{
		initializeBackground();
		
	}

	void LevelView::update()
	{
		background_rectangle->update();
	}

	void LevelView::render()
	{
		background_rectangle->render();
	}

	LevelView::~LevelView()
	{
		delete(background_rectangle);
	}

	void LevelView::initializeBackground()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()
			->getGraphicService()
			->getGameWindow();

		sf::Vector2f background_size = sf::Vector2f(game_window->getSize().x, game_window->getSize().y);
		background_rectangle->initialize(background_size, sf::Vector2f(0, 0), 0, background_color);
		background_rectangle->show();
	}

}