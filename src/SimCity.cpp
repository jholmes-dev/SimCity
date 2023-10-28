#include "../include/SimulationController.h"
#include "../include/MapController.h"
#include "../include/QueueController.h"
#include <iostream>

int main() 
{
    // Prompt user for the config file
    std::string configPath;
    std::cout << "Enter config file path: ";
    std::cin >> configPath;

    // Initialize the SimulationController, which will handle all simulation actions
    SimulationController sc(configPath);
    if (!sc.loadConfig()) return -1; // Config file did not load properly


    // Read map, and initialize simulation variables
    MapController mc;
    if (!mc.generateMap(mapFilePath)) return 0;
    int workers = 0;
    int goods = 0;
    QueueController qc(workers, goods);

    // Print initial map
    mc.printMap();
    std::cout << std::endl;

    // Loop through simulation
    for (int i = 0; i < timeLimit; i++)
    {
        workers = mc.getAvailableWorkers();
        goods = mc.getAvailableGoods();
        mc.stepAll(workers, goods, &qc);
        qc.printQueue();
        qc.processQueue();
        mc.printMap();
        std::cout << std::endl;

    }
}