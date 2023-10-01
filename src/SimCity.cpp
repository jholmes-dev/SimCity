#include "../include/FileHandler.h"
#include "../include/MapController.h"
#include <iostream>


int main() 
{
    std::string configPath = "C:/Users/Ginganian/Desktop/SimCity/data/region1.csv";
    FileHandler fh(configPath);
    std::vector<std::vector<MapCell>> map;
    MapController mc(map);
    
    if (!fh.generateMap(*mc.map)) return 0;
    
    mc.printMap();
    mc.updateAllAdjacent();

    (*mc.map)[3][5].printAdjDetails();
   
}