#include "../include/FileHandler.h"

FileHandler::FileHandler(std::string path) 
{
    this->configReader.open(path);
};

bool FileHandler::checkFile() 
{
    return this->configReader.good();
};

bool FileHandler::generateMap(std::vector<std::vector<MapCell>> &map) 
{
    if (this->configReader.is_open()) {

        if (!checkFile()) {
            std::cout << "File read error." << std::endl;
            return false;
        }

        std::string configLine;
        int rowIndex = 0;

        while (this->configReader) {
            int colIndex = 0;
            std::vector<MapCell> row;
            std::getline(this->configReader, configLine);

            if (configLine.length() <= 0) continue;

            for (int i = 0; i < configLine.length(); i++) {
                if (configLine[i] != ',') {
                    MapCell tempMS(map, configLine[i], rowIndex, colIndex);
                    row.push_back(tempMS);
                    colIndex++;
                }
            }

            map.push_back(row);
            rowIndex++;
        }

    }
    else {
        std::cout << "File not open." << std::endl;
        return false;
    }

    return true;

};