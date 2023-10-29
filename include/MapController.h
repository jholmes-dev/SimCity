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
	 * Total population of the map
	 */
	int totalPopulation = 0;

	/**
	 * Total pollution on the map
	 */
	int totalPollution = 0;

	/**
	 * Destructor
	 * 
	 */
	~MapController();

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
	 * Prints the pollution map to the console
	 *
	 */
	void printPollutionMap();

	/**
	 * Prints a combined version of the cell and pollution map
	 * 
	 */
	void printCombinedMap();

	/**
	 * Iterates a single step through the simulation
	 * 
	 */
	void stepAll(int& availableWorkers, int& availableGoods, QueueController* queue);

	/**
	 * Returns the total pollution on the map
	 * 
	 */
	int getTotalPollution();

	/**
	 * Returns the total population of the map cells
	 *
	 */
	int getTotalPopulation();

	/**
	 * Scans the map and updates the local pop and poll variables
	 *
	 */
	void updateMapInfo(); 
};