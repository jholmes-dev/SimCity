#ifndef MAPCELL_H_
# define MAPCELL_H_
#include "MapCell.h"
#endif

#include <iostream>
#include <vector>

class MapController
{
public:
	/**
	 * Pointer to the vector map
	 */
	std::vector<std::vector<MapCell>>* map;

	/**
	 * Current number of available workers
	 */
	int workers = 0;

	/**
	 * Current number of available goods
	 */
	int goods = 0;

	/**
	 * Class constructor, assigns map to internal variable
	 * 
	 */
	MapController(std::vector<std::vector<MapCell>>& map);

	/**
	 * Loops through all cells and updates their adjacency data
	 * 
	 */
	void updateAllAdjacent();

	/**
	 * Prints the map to the console
	 * 
	 */
	void printMap();

	/**
	 * Executes a step through each 
	 */
};