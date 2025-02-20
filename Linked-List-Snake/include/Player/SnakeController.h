#pragma once
namespace Player {
	
		enum class SnakeState
		{
			ALIVE,
			DEAD,
		};
	class SnakeController {
		const int snakeLength = 10;
		SnakeState currentsnakeSate;
	public:
		SnakeController();
		void Intialize();
		void Update();
		void Render();
		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void SnakeMovement();
		void HandelSnakeCollision();
		void handelReset();
		void Reset();
		void SpawnSnake();
		void SetSnakeState(SnakeState state);
		void ReSpwanSnake();
		SnakeState GetSnakeState();
		~SnakeController();
	};
}