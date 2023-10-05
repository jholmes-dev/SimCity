#include "../include/IndustrialCell.h"

/**
 * If a cell has a population of 0, is adjacent to a powerline in the current time step, and there are
 * at least 2 available workers, that cell’s population will increase by 1 in the next time step and the 
 * available workers are assigned to that job
 *
 * If a cell has a population of 0, is adjacent to at least one cell with a population of at least 1, 
 * and there are at least 2 available workers, that cell’s population will increase by 1 in the next 
 * time step and the available workers are assigned to that job
 *
 * If a cell has a population of 1, is adjacent to at least two cells with a population of at least 1, 
 * and there are at least 2 available workers, that cell’s population will increase by 1 in the next time 
 * step and the available workers are assigned to that job
 *
 * If a cell has a population of 2, is adjacent to at least four cells with a population of at least 2, 
 * and there are at least 2 available workers, that cell’s population will increase by 1 in the next time 
 * step and the available workers are assigned to that job
 *
 * A cell produces pollution equal to its population, and pollution spreads to all adjacent cells at a rate 
 * of one less unit of pollution per cell away from the source
 *
 * The industrial population provides goods to the commercial zones, at a rate of one good per population, 
 * but each good can only be sold at one commercial cell
**/

void IndustrialCell::step(const int &workers, const int &goods)
{
	MapCell::updateAdjacent();

	if (population == 0) {}
}
