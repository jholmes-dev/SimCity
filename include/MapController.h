#pragma once
#include "MapCell.h"
#include "ResidentialCell.h"
#include "CommercialCell.h"
#include "IndustrialCell.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class MapController
{
public:
	/**
	 * Pointer to the vector map
	 */
	std::vector<std::vector<MapCell*>> map;

	/**
	 * Reads the map file and generates a 2D vector with its data
	 *
	 */
	bool generateMap(std::string);

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
	 * Iterates a single step through the simulation
	 * 
	 */
	void stepAll(int& availableWorkers, int& availableGoods, QueueController* queue);

	/**
	 * Returns the current number of available workers
	 * 
	 */
	int getAvailableWorkers();

	/**
	 * Returns the current number of available goods
	 *
	 */
	int getAvailableGoods();
};