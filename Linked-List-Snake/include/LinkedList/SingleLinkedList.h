#pragma once
#include <SFML/System/Vector2.hpp>
#include "Player/Node.h"
#include "Player/Direction.h"

namespace LinkedList
{
	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();
	};

	void SingleLinkedList::render() {
		Node* cur_node = head_node;

		while (cur_node != nullptr) {     // Traverse through the linked list and render each node's body part
			cur_node->body_part.render();
			cur_node = cur_node->next;
		}
	}
}