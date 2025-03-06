#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../include/LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		SnakeState current_snake_state;
		LinkedList::SingleLinkedList* single_linked_list;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_snake_direction;

		const float movement_frame_duration = 0.1f;
		float elapsed_duration;

		const float restart_duration = 2.0f;
		float restart_counter;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollission();
		void handleRestart();
		void reset();

		void createLinkedList();

		void delayedUpdate();
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

	};
}