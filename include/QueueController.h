#pragma once
#include "./QueueNode.h";

/**
 * A linked list data structure that contains QueueNodes, which contain growth
 * requests from MapCells. 
 * 
 * QueueNodes are inserted in priority order, and can be considered sorted
 * at all times
 */
class QueueController
{
	/**
	 * The lists' head node
	 */
	QueueNode& head = nullptr;

};

