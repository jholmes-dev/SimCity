#include "../include/MapCell.h"

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
				
				int switchPop = ((*map)[r][c].population >= 5) ? 5 : (*map)[r][c].population;

				switch (switchPop)
				{
				case 5:
					adjPop[5]++;
				case 4:
					adjPop[4]++;
				case 3:
					adjPop[3]++;
				case 2:
					adjPop[2]++;
				case 1:
					adjPop[1]++;
				case 0:
					adjPop[0]++;
				}

				break;
			}
		}
	}
}

void MapCell::printAdjDetails()
{
	std::cout << "Adjacency for cell: " << row << "," << col << "; of type: " << type << ";" << std::endl;
	std::cout << "PP:" << adjPowerPlants << "; PL:" << adjPowerLines << "; R:" << adjRoads << "; Pop: [" << adjPop[0] << ", " << adjPop[1] << ", " << adjPop[2] << ", " << adjPop[3] << ", " << adjPop[4] << ", " << adjPop[5] << "];" << std::endl;
}
