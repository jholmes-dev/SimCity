#include "../include/MapController.h"
#include <iostream>

int main() 
{
    std::string configPath = "C:/Users/Ginganian/Desktop/College/CSCE2110/SimCity/SimCity/data/region1.csv";
    MapController mc;
    mc.generateMap(configPath);
    
    mc.printMap();
    
    mc.updateAllAdjacent();
    mc.map[3][5].printAdjDetails();
}