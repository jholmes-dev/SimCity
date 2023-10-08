#pragma once
#include "MapCell.h"

class CommercialCell : public MapCell {
public:
	using MapCell::MapCell;

	/**
	 * Iterates this cell through a time step of the simulation
	 *
	 */
	void step();
};