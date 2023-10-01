#ifndef MAPCELL_H_
# define MAPCELL_H_
#include "MapCell.h"
#endif


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class FileHandler 
{
private:
    std::ifstream configReader;

public:

    /**
     * Constructor for FileHandler class. Takes file path string and reads in the input file at the path destination
     *
     * @param path config file path
    */
    FileHandler(std::string path);

    /**
     * Checks if file was loaded correctly, and is not empty
     *
     */
    bool checkFile();

    /**
     * Reads the map file and generates a 2D vector with its data
     *
     */
    bool generateMap(std::vector<std::vector<MapCell>>&);
};