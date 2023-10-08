#pragma once
#include "MapCell.h"

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
	void step(const int &workers, const int &goods);

	/**
	 * Spread pollution to adjacent cells. Industrial cells are the only cells that pollute
	 * 
	 */
	void pollute();
};