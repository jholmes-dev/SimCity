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
	/**
	 * Reference to the cell that owns this event
	 */
	MapCell& cell;

	/**
	 * The amount of resources required for this event to be able to execute
	 */
	int reqWorkers;
	int reqGoods;

	/**
	 * Attempts to execute the event. If resources for the event are not available
	 * then no action will be taken
	 * 
	 */
	void execute();
};