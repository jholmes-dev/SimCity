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
	std::vector<std::vector<MapCell>> map;

	/**
	 * Current number of available workers
	 */
	int workers = 0;

	/**
	 * Current number of available goods
	 */
	int goods = 0;

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
};