#include "../include/MapController.h"

MapController::~MapController()
{
    // Delete all map cells
    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            delete map[r][c];
        }
    }
}

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
            if (map[r][c]->population > 0) std::cout << map[r][c]->population << " ";
            else std::cout << map[r][c]->type << " ";
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

void MapController::printCombinedMap()
{
    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            // Print cell type if pop is 0, otherwise print cell pop
            if (map[r][c]->population > 0) std::cout << map[r][c]->population;
            else std::cout << map[r][c]->type;

            // Print pollution if the cell has any
            if (map[r][c]->pollution > 0) std::cout << "(" << map[r][c]->pollution << ")";

            std::cout << "\t";
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

    updateMapInfo();
}

int MapController::getTotalPollution()
{
    int totPollution = 0;

    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            totPollution += map[r][c]->pollution;
        }
    }

    return totPollution;
}

int MapController::getTotalPopulation()
{
    int totPop = 0;

    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            totPop += map[r][c]->population;
        }
    }

    return totPop;
}

void MapController::updateMapInfo()
{
    totalPollution = 0;
    totalPopulation = 0;

    for (int r = 0; r < map.size(); r++)
    {
        for (int c = 0; c < map[0].size(); c++)
        {
            totalPollution += map[r][c]->pollution;
            totalPopulation += map[r][c]->population;
        }
    }
}