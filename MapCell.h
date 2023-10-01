#include <iostream>
#include <vector>

class MapCell
{
public:
	/**
	 * Pointer to the map vector
	 */
	std::vector<std::vector<MapCell>>* map;

	/**
	 * The cell's type
	 */
	char type;

	/**
	 * The cell's coordinates within the map vector
	 */
	int row;
	int col;

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
	 */
	MapCell(std::vector<std::vector<MapCell>> &map, char type, int row, int col);

	void updateType(char newType);

	/**
	 * Scans adjacent MapCells and updates the adj variable
	 */
	void updateAdjacent();
};