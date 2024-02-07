#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelService.h"
#include "Event/EventService.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;
	using namespace Level;
	using namespace Event;
	using namespace Time;
	using namespace Sound;
	using namespace Element;
	using namespace Food;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();
		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			moveSnake();
			processSnakeCollision();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}

	void SnakeController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
		}
	}

	void SnakeController::moveSnake()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			single_linked_list->update(current_snake_direction);
			elapsed_duration = 0.f;
		}
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementsCollision();
		processFoodCollision();
	}

	void SnakeController::processBodyCollision()
	{
		if (single_linked_list->processNodeCollision())
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::processElementsCollision()
	{
		ElementService* element_service = ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementsCollision(single_linked_list->getHeadNode()))
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService* food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollision(single_linked_list->getHeadNode(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);

			food_service->destroyFood();
			OnFoodCollected(food_type);

			player_score++;
		}
	}

	void SnakeController::OnFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			single_linked_list->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			break;

		case FoodType::BURGER:
			single_linked_list->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			break;

		case FoodType::CHEESE:
			single_linked_list->insertNodeAt(getRandomBodyPartIndex());
			time_complexity = TimeComplexity::N;
			break;

		case FoodType::APPLE:
			single_linked_list->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			break;

		case FoodType::MANGO:
			single_linked_list->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			break;

		case FoodType::ORANGE:
			single_linked_list->removeNodeAt(getRandomBodyPartIndex());
			time_complexity = TimeComplexity::N;
			break;

		case FoodType::POISION:
			single_linked_list->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			break;

		case FoodType::ALCOHOL:
			current_snake_direction = single_linked_list->reverse();
			time_complexity = TimeComplexity::N;
			break;
		}
	}

	void SnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			single_linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		player_score = 0;
		time_complexity = TimeComplexity::N;
	}

	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	int SnakeController::getPlayerScore()
	{
		return player_score;
	}

	TimeComplexity SnakeController::getTimeComplexity()
	{
		return time_complexity;
	}

	int SnakeController::getSnakeSize()
	{
		return single_linked_list->getLinkedListSize();
	}

	int SnakeController::getRandomBodyPartIndex()
	{
		return std::rand() % (single_linked_list->getLinkedListSize() - 1);
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return single_linked_list->getNodesPositionList();
	}

	void SnakeController::destroy()
	{
		delete (single_linked_list);
	}
}