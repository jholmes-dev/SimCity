#pragma once
#include "MapCell.h"
#include "QueueController.h"

class IndustrialCell : public MapCell {
public:
	/**
	 * Use the base class' constructor
	 * 
	 */
	using MapCell::MapCell;

	/**
	 * Iterates this cell through a time step of the simulation
	 *
	 */
	void step(int &availableWorkers, int &availableGoods, QueueController* queue);

	/**
	 * Spread pollution to adjacent cells. Industrial cells are the only cells that pollute
	 * 
	 */
	void pollute();
};