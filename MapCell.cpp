#include "MapCell.h"

MapCell::MapCell(std::vector<std::vector<MapCell>> &map, char type, int row, int col)
{
	this->map = &map;
	this->type = type;
	this->row = row;
	this->col = col;
}

void MapCell::updateType(char newType)
{
	this->type = newType;
}

void MapCell::updateAdjacent() 
{
	for (int r = row - 1; r <= row + 1; r++) {
		if (r < 0 || r >= (*map).size()) continue; // Out of bounds checking

		for (int c = col - 1; c <= col + 1; c++) {
			if (c < 0 || c >= (*map)[0].size() || (r == row && c == col)) continue; // Out of bounds checking + skipping self

			switch ((*map)[r][c].type)
			{
			case '-':
				adjRoads++;
				break;
			case 'T':
				adjPowerLines++;
				break;
			case '#':
				adjRoads++;
				adjPowerLines++;
				break;
			case 'P':
				adjPowerPlants++;
				break;
			case 'R':
			case 'I':
			case 'C':
				break;
			}
		}
	}
}