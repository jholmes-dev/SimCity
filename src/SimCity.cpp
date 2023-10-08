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

    //return 0;
    //QueueController qc(workers, goods);
    //qc.generateEvent(mc.map[2][0]);
    //qc.generateEvent(mc.map[2][1]);
    //qc.generateEvent(mc.map[5][4]);
    //qc.generateEvent(mc.map[1][5]);
    //qc.generateEvent(mc.map[3][2]);
    //qc.generateEvent(mc.map[1][1]);
    //qc.printQueue();
    //qc.processQueue();
}