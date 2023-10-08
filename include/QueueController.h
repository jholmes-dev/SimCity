#pragma once
#include "QueueNode.h"

/**
 * A linked list data structure that contains QueueNodes, which contain growth
 * requests from MapCells. 
 * 
 * QueueNodes are inserted in priority order, and can be considered sorted
 * at all times
 */
class QueueController
{
public:
	/**
	 * The queue's head node
	 */
	QueueNode* head = NULL;

	/**
	 * References to available workers and goods
	 */
	int* workers;
	int* goods;

	/**
	 * Constructor, sets references to workers and goods
	 * 
	 */
	QueueController(int& w, int& g);

	/**
	 * Inserts a given node into the queue
	 * 
	 * @param *node : Pointer to the node being inserted
	 */
	void insert(QueueNode* node);

	/**
	 * Creates and inserts a QueueNode given a MapCell
	 * 
	 * @param &cell : Reference to the MapCell related to the queue event
	 */
	void generateEvent(MapCell& cell);

	/**
	 * Loops through and executes each queue node, then removes it from the queue
	 * 
	 */
	void processQueue();
	void processQueue(QueueNode* node);

	/**
	 * Prints the queue to the console
	 * 
	 */
	void printQueue();
};