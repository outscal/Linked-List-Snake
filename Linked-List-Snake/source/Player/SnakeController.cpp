#include "Player/SnakeController.h"
#include "Global/ServiceLocator.h"
#include "Level/LevelService.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;
	using namespace Level;

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

		single_linked_list->initialize(width, height, default_position, default_direction);
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
	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
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

	void SnakeController::processPlayerInput() { }

	void SnakeController::updateSnakeDirection() { }

	void SnakeController::moveSnake() { }

	void SnakeController::processSnakeCollision() { }

	void SnakeController::handleRestart() { }

	void SnakeController::spawnSnake()
	{
		single_linked_list->createHeadNode();
	}

	void SnakeController::reset() {
	}

	void SnakeController::respawnSnake() { }

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	void SnakeController::destroy()
	{
		delete (single_linked_list);
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
	}

	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void SnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}


	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();
			moveSnake();
		}
	}
}
