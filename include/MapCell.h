#pragma once

#include <iostream>
#include <vector>

class QueueController;

class MapCell
{
public:
	/**
	 * Pointer to the map vector
	 */
	std::vector<std::vector<MapCell*>>* map;

	/**
	 * The cell's current population
	 */
	int population = 0;

	/**
	 * The cell's current pollution 
	 */
	int pollution = 0;

	/**
	 * The cell's type
	 * 
	 * R represents a residential zone
	 * I represents an industrial zone
	 * C represents a commercial zone
	 * - represents a road
	 * T represents a powerline
	 * # represents a powerline over a road
	 * P represents a power plant
	 * 
	 * The cell's type can also be space (" "), representing an empty cell
	 */
	char type;

	/**
	 * The cell's coordinates within the map vector
	 */
	int row; // y
	int col; // x

	/** 
	 * The cell's total adjacent population
	 */
	int totalAdjPop = 0;

	/**
	 * Array containing the number of adjacent MapCells that contain at least the index value in population.
	 * For example, adjPop[3] contains how many adjacent MapCells have a population of at least 3
	 */
	int adjPop[6] = { 0, 0, 0, 0, 0, 0 };

	/**
	 * Number of adjacent MapCells that contain power plants
	 */
	int adjPowerPlants = 0;

	/**
	 * Number of adjacent MapCells that contain power lines
	 */
	int adjPowerLines = 0;

	/**
	 * Number of adjacent MapCells that contain roads
	 */
	int adjRoads = 0;

	/**
	 * Class constructor
	 * 
	 */
	MapCell(std::vector<std::vector<MapCell*>> &map, char type, int row, int col);

	/**
	 * Updates the cell's type with the provided type
	 * 
	 * @param newType : The character type to be assigned
	 */
	void updateType(char newType);

	/**
	 * Scans adjacent MapCells and updates the local adjacency variables
	 * 
	 */
	void updateAdjacent();

	/**
	 * Prints the cell's current adjacency details to the console
	 * 
	 */
	void printAdjDetails();

	/**
	 * Iterates this cell through a time step of the simulation
	 *
	 */
	virtual void step(int& availableWorkers, int& availableGoods, QueueController* queue);

};