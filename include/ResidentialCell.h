#pragma once
#include "MapCell.h"
#include "QueueController.h"

class ResidentialCell : public MapCell {
public:
	using MapCell::MapCell;

	/**
	 * Iterates this cell through a time step of the simulation
	 *
	 */
	void step(int& availableWorkers, int& availableGoods, QueueController* queue);
};