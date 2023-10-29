#pragma once
#include "MapCell.h"

#include <vector>

/**
 * A single node within the event queue. Managed by QueueController.
 * This node holds all data related to a growth event, and can handle
 * it's own execution.
 */
class QueueNode
{
public:
	/**
	 * The next node in the linked list
	 */
	QueueNode* next = NULL;

	/**
	 * Reference to the cell that owns this event
	 */
	MapCell* cell;

	/**
	 * The amount of resources required for this event to be able to execute
	 */
	int reqWorkers = 0;
	int reqGoods = 0;

	/**
	 * This queue node's priority, calculated as follows:
	 * 
	 * Commercial Cell:		+2000
	 * Industrial Cell:		+1000
	 * Cell Pop X=(0-5):	+ X00
	 * Adj Pop X=(0-40):    +  XX
	 * 
	 * The cell is inserted after any tie priorities, as queue events are added 
	 * from lower->higher coordinate values
	 */
	int priority = 0;

	/**
	 * Constructor, handles variable assignment and priority calculation
	 * 
	 * @param &cell : Reference to the MapCell that created the node
	 * @param rWorkers : The required workers for cell growth
	 * @param rGoods : The required goods for cell growth
	 */
	QueueNode(MapCell& cell, int rWorkers, int rGoods);

	/**
	 * Constructor, accepts only cell reference, and sets workers & goods based off of cell's type
	 *
	 * @param &cell : Reference to the MapCell that created the node
	 */
	QueueNode(MapCell& cell);

	/**
	 * Calculates this node's priority from the parent cell's attributes
	 * 
	 */
	void setPriority();

	/**
	 * Attempts to execute the event. If resources for the event are not available
	 * then no action will be taken
	 * 
	 * @param workers : Pointer to the pool of available workers
	 * @param goods : Pointer to the pool of available goods
	 */
	void execute(int* workers, int* goods);
};