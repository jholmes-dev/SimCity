#include "../include/SimulationController.h"

SimulationController::SimulationController(std::string path)
{
    configFilePath = path;
}

SimulationController::~SimulationController()
{
    delete qc; 
    delete mc;
}

bool SimulationController::initialize()
{
    if (!loadConfig()) return false; // Config file did not load properly

    // Initialize map and queue controllers
    mc = new MapController();
    qc = new QueueController(workers, goods);

    // Read map
    if (!mc->generateMap(mapFilePath)) return false;

    // Step simulation once to initialize queue
    stepNext();

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

void SimulationController::runFullSimulation()
{
    for (int i = 0; i < timeLimit - 1; i++)
    {
        // Print simulation info at refresh rate
        if (i % refreshRate == 0)
        {
            printFullStepInfo();
        }

        // Save variables to check if there is no change between steps
        int prevPop = mc->totalPopulation;
        int prevW = workers;
        int prevG = goods;

        // Step single
        stepNext();

        // Compare sim states. Stop sim if there's no change
        if (prevPop == mc->totalPopulation && prevW == workers && prevG == goods)
        {
            std::cout << "No change between sim steps. Simulation stopped." << std::endl << std::endl;
            break;
        }
    }
    
    // Output final state
    std::cout << "Final state:" << std::endl;
    printFullStepInfo();
}

void SimulationController::stepNext()
{
    qc->processQueue();
    mc->stepAll(workers, goods, qc); 
    simStep++;
}

void SimulationController::printFullStepInfo()
{
    std::cout << "---------------------------------------------------------" << std::endl;
    printStepInfo();
    std::cout << std::endl;
    mc->printCombinedMap();
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}

void SimulationController::printStepInfo()
{
    std::cout << "** Simulation Step " << simStep << " **" << std::endl;
    std::cout << "Workers\tGoods\tPop\tPoll" << std::endl;
    std::cout << workers << "\t" << goods << "\t" << mc->totalPopulation << "\t" << mc->totalPollution << std::endl;
}
