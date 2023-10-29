#include "../include/SimulationController.h"
#include "../include/MapController.h"
#include "../include/QueueController.h"
#include <iostream>

int main() 
{
    // Splash
    std::cout << "******************************" << std::endl;
    std::cout << "********** SIM CITY **********" << std::endl;
    std::cout << "***** By: Jeffrey Holmes *****" << std::endl;
    std::cout << "******************************" << std::endl;

    // Prompt user for the config file
    std::string configPath;
    std::cout << "Enter config file path: ";
    std::cin >> configPath;

    // Initialize the SimulationController, which will handle all simulation actions
    SimulationController sc(configPath);
    if (!sc.initialize()) return -1; // Config file did not load properly    

    // Output available commands
    std::cout << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << "\ta: Runs the full simulation to the end" << std::endl;
    std::cout << "\tn: Manually steps the simulation once" << std::endl;
    std::cout << "\tm: Prints the map" << std::endl;
    std::cout << "\tp: Prints the pollution map" << std::endl;
    std::cout << "\te: Prints the current queue" << std::endl;
    std::cout << "\tq: Quits the program" << std::endl << std::endl;

    // Loop for user input
    char input = 'q';
    do
    {
        std::cout << "Enter a command: ";
        std::cin >> input;

        switch (input)
        {
        case 'a': // Auto run the simulation

            break;
        case 'n': // Next simulation step
            sc.stepNext();
            break;
        case 'm': // Print map
            sc.mc->printMap();
            break;
        case 'p': // Print pollution map
            sc.mc->printPollutionMap();
            break;
        case 'e': // Print queue
            sc.qc->printQueue();
            break;
        case 'q': // Quit program
            break;
        default:
            std::cout << "Not a valid input." << std::endl;
        }

        std::cout << std::endl;
    } while (input != 'q');

    // Loop through simulation
    //for (int i = 0; i < sc.timeLimit; i++)
    //{}
}