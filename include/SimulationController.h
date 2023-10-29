#pragma once
#include "MapController.h"
#include <string>
#include <fstream>
#include <iostream>

/**
 * Provides general simulation control and functionality
 * 
 */
class SimulationController
{
public:
	/**
	 * The path to the simulation's config file
	 */
	std::string configFilePath = "";

	/**
	 * The path to the simulation's map file
	 */
	std::string mapFilePath = "";

	/**
	 * The simulation step limit
	 */
	int timeLimit = 10;

	/**
	 * The rate at which the simulation's map should be printed
	 */
	int refreshRate = 1;

	/**
	 * The simulation's workers and goods variables
	 */
	int workers = 0;
	int goods = 0;

	/**
	 * The simulation's MapController
	 */
	MapController* mc = NULL;

	/**
	 * The simulation's QueueController
	 */
	QueueController* qc = NULL;

	/**
	 * SimulationController constructor, reads the config file provided and intiialzes the simulation
	 * 
	 * @param configFilePath : The path to the config file
	 */
	SimulationController(std::string path);

	/**
	 * Initializes the simulation
	 * 
	 * @return bool : If config was properly loaded and simuilation is ready
	 */
	bool initialize();

	/**
	 * Handles reading and loading of the config file
	 * 
	 * @return bool : Whether or not the config was loaded correctly
	 */
	bool loadConfig();

	/**
	 * Iterates one step forward through the simulation
	 * 
	 */
	void stepNext();

};