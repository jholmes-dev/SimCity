#pragma once
#include "MapCell.h"
#include "QueueController.h"

class ResidentialCell : public MapCell {
public:
	using MapCell::MapCell;

	/**
	 * Iterates this cell through a time step of the simulation
	 *
	 * @return : Whether or not the cell grew in the current time step
	 */
	bool step(int& availableWorkers, int& availableGoods, QueueController* queue);
};