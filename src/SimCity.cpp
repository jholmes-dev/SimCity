#include "../include/MapController.h"
#include "../include/QueueController.h"
#include <iostream>

int main() 
{
    int workers = 99;
    int goods = 99;

    std::string configPath = "C:/Users/Ginganian/Desktop/SimCity/data/region1.csv";
    MapController mc;
    if (!mc.generateMap(configPath)) return 0;
    QueueController qc(workers, goods);
    mc.printMap();
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        mc.stepAll(workers, goods, &qc);
        qc.printQueue();
        qc.processQueue();
        mc.printMap();
        std::cout << std::endl;

    }
}