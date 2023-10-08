#include "../include/QueueController.h"

QueueController::QueueController(int& w, int& g)
{
	this->workers = &w;
	this->goods = &g;
}

void QueueController::insert(QueueNode* node)
{
	// Check if we need to insert node at front of list
	if (head == NULL || node->priority > head->priority)
	{
		node->next = head;
		head = node;
		return;
	}

	// Find priority location for insertion
	QueueNode* currentNode = head;
	while (currentNode->next != NULL && currentNode->next->priority >= node->priority)
	{
		currentNode = currentNode->next;
	}

	node->next = currentNode->next;
	currentNode->next = node;
}

void QueueController::generateEvent(MapCell& cell)
{
	QueueNode* node = new QueueNode(cell);
	insert(node);
}

void QueueController::processQueue()
{
	processQueue(head);
	head = NULL;
}

void QueueController::processQueue(QueueNode* node)
{
	if (node != NULL)
	{
		node->execute(workers, goods);
		processQueue(node->next);
		delete node;
	}
}

void QueueController::printQueue()
{
	QueueNode* currentNode = head;

	if (currentNode == NULL) std::cout << "Queue empty" << std::endl;

	int n = 0;
	while (currentNode != NULL)
	{
		n++;
		std::cout << n << ":" << currentNode->cell->type << ":" << currentNode->priority << std::endl;
		currentNode = currentNode->next;
	}
}