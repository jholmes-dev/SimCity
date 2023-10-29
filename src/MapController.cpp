#include "../include/MapController.h"

bool MapController::generateMap(std::string path)
{
    std::ifstream mapReader;
    mapReader.open(path);

    if (mapReader.is_open()) 
    {
        std::string mapFileLine;
        int rowIndex = 0;

        while (mapReader) 
        {
            int colIndex = 0;
            std::vector<MapCell*> row;
            std::getline(mapReader, mapFileLine);

            if (mapFileLine.length() <= 0) continue;

            for (int i = 0; i < mapFileLine.length(); i++) {
                if (mapFileLine[i] != ',') {

                    if (mapFileLine[i] == 'R') {
                        ResidentialCell* tempMS = new ResidentialCell(map, mapFileLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }
                    else if (mapFileLine[i] == 'I') {
                        IndustrialCell* tempMS = new IndustrialCell(map, mapFileLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }
                    else if (mapFileLine[i] == 'C') {
                        CommercialCell* tempMS = new CommercialCell(map, mapFileLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }
                    else {
                        MapCell* tempMS = new MapCell(map, mapFileLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }

                    colIndex++;
                }
            }

            map.push_back(row);
            rowIndex++;
        }

    }
    else 
    {
        std::cout << "Could not open file. Is the map file path in the config set correctly?" << std::endl;
        return false;
    }

    return true;

};

void MapController::updateAllAdjacent()
{
	for (int r = 0; r < map.size(); r++)
	{
		for (int c = 0; c < map[0].size(); c++) 
		{
			map[r][c]->updateAdjacent();
		}
	}
}

void MapController::printMap()
{
    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            if (map[r][c]->population > 0) std::cout << map[r][c]->population;
            else std::cout << map[r][c]->type;
        }
        std::cout << std::endl;
    }
}

void MapController::printPollutionMap()
{
    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            std::cout << map[r][c]->pollution << " ";
        }
        std::cout << std::endl;
    }
}


void MapController::stepAll(int& availableWorkers, int& availableGoods, QueueController* queue)
{
    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            map[r][c]->step(availableWorkers, availableGoods, queue);
        }
    }
}

int MapController::getAvailableWorkers()
{
    int numWorkers = 0;

    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            if (map[r][c]->type == 'R') numWorkers += map[r][c]->population;
        }
    }

    return numWorkers;
}

int MapController::getAvailableGoods()
{
    int numGoods = 0;

    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            if (map[r][c]->type == 'I') numGoods += map[r][c]->population;
        }
    }

    return numGoods;
}