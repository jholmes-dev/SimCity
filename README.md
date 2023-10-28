# Sim City

This project takes a city layout input in the format of a CSV, and simulates city growth over a given amount of time.

## Project requirements

- Read in and store simulation configuration, and initial region
- Output initial region state
- Simulation should hault when there is no change between two, consecutive time steps, or the time limit has been reached, whichever comes first
- Each cell must change states based on the given rules
- Output the final region state, including regional population and pollution
- Allow the user to input coordinates for zone analysis, provided the user with detailed information on the sub zone selected

## Config File

The program reads in a config file specified by the user. The config file should contain the following 3 keys:
* "Region Layout" : The path and filename of the map to be loaded for the simulation.
* "Time Limit" : The max amount of simulation steps to iterate through
* "Refresh Rate" : How many steps between displaying the simulation map in the console

Example config file:
```
Region Layout:data/region1.csv
Time Limit:20
Refresh Rate:1
```

## Cell rules

### Residential
- If a cell has a population of 0 and is adjacent to a powerline in the current time step, that cell’s population will increase by 1 in the next time step
- If a cell has a population of 0 and is adjacent to at least one cell with a population of at least 1, that cell’s population will increase by 1 in the next time step
- If a cell has a population of 1 and is adjacent to at least two cells with a population of at least 1, that cell’s population will increase by 1 in the next time step
- If a cell has a population of 2 and is adjacent to at least four cells with a population of at least 2, that cell’s population will increase by 1 in the next time step
- If a cell has a population of 3 and is adjacent to at least six cells with a population of at least 3, that cell’s population will increase by 1 in the next time step
- If a cell has a population of 4 and is adjacent to at least eight cells with a population of at least 4, that cell’s population will increase by 1 in the next time step
- The residential population provides workers to the industrial and commercial zones, but each worker can only have one job

### Industrial

- If a cell has a population of 0, is adjacent to a powerline in the current time step, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job
- If a cell has a population of 0, is adjacent to at least one cell with a population of at least 1, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job
- If a cell has a population of 1, is adjacent to at least two cells with a population of at least 1, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job
- If a cell has a population of 2, is adjacent to at least four cells with a population of at least 2, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job
- A cell produces pollution equal to its population, and pollution spreads to all adjacent cells at a rate of one less unit of pollution per cell away from the source
- The industrial population provides goods to the commercial zones, at a rate of one good per population, but each good can only be sold at one commercial cell

### Commercial

- If a cell has a population of 0, is adjacent to a powerline in the current time step, there is at least 1 available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available worker and available good are assigned to that job
- If a cell has a population of 0, is adjacent to at least one cell with a population of at least 1, there is at least 1 available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available worker and available good are assigned to that job
- If a cell has a population of 1, is adjacent to at least two cells with a population of at least 1, there is at least 1 available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available worker and available good are assigned to that job