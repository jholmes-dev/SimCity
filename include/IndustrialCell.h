#ifndef MAPCELLS_H_
# define MAPCELLS_H_
#include "MapCell.h"
#include "ResidentialCell.h"
#include "CommercialCell.h"
#include "IndustrialCell.h"
#endif

class IndustrialCell : public MapCell {
public:
	using MapCell::MapCell;

	/**
	 * Iterates this cell through a time step of the simulation
	 *
	 */
	void step(const int &workers, const int &goods);
};