#include "../include/MapController.h"

MapController::MapController(std::vector<std::vector<MapCell>>& map)
{
	this->map = &map;
}

void MapController::updateAllAdjacent()
{
	for (int r = 0; r < (*map).size(); r++)
	{
		for (int c = 0; c < (*map)[0].size(); c++) 
		{
			(*map)[r][c].updateAdjacent();
		}
	}
}

void MapController::printMap()
{
	for (int r = 0; r < (*map).size(); r++)
	{
		for (int c = 0; c < (*map)[0].size(); c++)
		{
			std::cout << (*map)[r][c].type;
		}
		std::cout << std::endl;
	}
}
