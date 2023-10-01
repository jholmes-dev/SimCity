#include "../include/FileHandler.h"
#include <iostream>

void printMap(std::vector<std::vector<MapCell>> &map)
{
    for (int i = 0; i < (map).size(); i++)
    {
        for (int j = 0; j < (map)[i].size(); j++)
        {
            std::cout << ((map)[i][j]).type;
        }
        std::cout << std::endl;
    }
}

void printAdj(MapCell &mc) 
{
    std::cout << mc.adjPowerLines << std::endl;
    std::cout << mc.adjPowerPlants << std::endl;
    std::cout << mc.adjRoads << std::endl << std::endl;
}

int main() 
{
    std::string configPath = "C:/Users/Ginganian/Desktop/SimCity/data/region1.csv";
    FileHandler fh(configPath);
    std::vector<std::vector<MapCell>> map;
    
    if (!fh.generateMap(map)) {
        return 3;
    }

    map[3][7].updateAdjacent();
    printAdj(map[3][7]);
}