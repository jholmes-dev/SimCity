#include "../include/SimulationController.h"

SimulationController::SimulationController(std::string path)
{
    configFilePath = path;
}

bool SimulationController::initialize()
{
    if (!loadConfig()) return false; // Config file did not load properly

    // Initialize map and queue controllers
    mc = new MapController();
    qc = new QueueController(workers, goods);

    // Read map
    if (!mc->generateMap(mapFilePath)) return false;

    return true;
}

bool SimulationController::loadConfig()
{
    // Load config file
    std::ifstream configReader;
    configReader.open(configFilePath);

    // Check that config file was loaded successfully
    if (!configReader.is_open())
    {
        std::cout << "Error reading config file." << std::endl;
        return false;
    }

    // Loop through the config lines and save data
    std::string configLine;
    while (configReader)
    {
        // Read in the config line
        std::getline(configReader, configLine);

        // If the config line is empty we can break
        if (configLine.length() <= 0) break;

        // Find the semicolon in the line
        int lsIndex = configLine.find(":");
        std::string configKey = configLine.substr(0, lsIndex);
        std::string configVal;

        // Check for overflow
        if (configLine.length() > lsIndex + 1)
        {
            configVal = configLine.substr(lsIndex + 1);
        }
        else
        {
            std::cout << "No value found for config key '" << configKey << "'" << std::endl;
            return false;
        }

        // Assign value based on key
        if (configKey == "Region Layout")
        {
            mapFilePath = configVal;
        }
        else if (configKey == "Time Limit")
        {
            timeLimit = stoi(configVal);
        }
        else if (configKey == "Refresh Rate")
        {
            refreshRate = stoi(configVal);
        }
        else
        {
            std::cout << "Config file line mismatch. '" << configKey << "' is not an accepted config key value." << std::endl;
            std::cout << "Accepted config key values: " << "'Region Layout', 'Time Limit', 'Refresh Rate'" << std::endl;
            return false;
        }
    }

    // Check that the required configs were loaded
    if (mapFilePath == "")
    {
        std::cout << "Map file path config key not found." << std::endl;
    }

    return true;
}

void SimulationController::stepNext()
{
    workers = mc->getAvailableWorkers();
    goods = mc->getAvailableGoods();
    qc->processQueue();
    mc->stepAll(workers, goods, qc);
}
