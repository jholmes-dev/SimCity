#include "../include/MapController.h"

bool MapController::generateMap(std::string path)
{
    std::ifstream configReader;
    configReader.open(path);

    if (configReader.is_open()) {

        std::string configLine;
        int rowIndex = 0;

        while (configReader) {
            int colIndex = 0;
            std::vector<MapCell> row;
            std::getline(configReader, configLine);

            if (configLine.length() <= 0) continue;

            for (int i = 0; i < configLine.length(); i++) {
                if (configLine[i] != ',') {

                    if (configLine[i] == 'R') {
                        ResidentialCell tempMS(map, configLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }
                    else if (configLine[i] == 'I') {
                        IndustrialCell tempMS(map, configLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }
                    else if (configLine[i] == 'C') {
                        CommercialCell tempMS(map, configLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }
                    else {
                        MapCell tempMS(map, configLine[i], rowIndex, colIndex);
                        row.push_back(tempMS);
                    }

                    colIndex++;
                }
            }

            map.push_back(row);
            rowIndex++;
        }

    }
    else {
        std::cout << "File not open." << std::endl;
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
			map[r][c].updateAdjacent();
		}
	}
}

void MapController::printMap()
{
	for (int r = 0; r < map.size(); r++)
	{
		for (int c = 0; c < map[0].size(); c++)
		{
			std::cout << map[r][c].type;
		}
		std::cout << std::endl;
	}
}