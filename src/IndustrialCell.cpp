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

bool IndustrialCell::step(int& availableWorkers, int& availableGoods, QueueController* queue)
{
	bool growth = false;
	MapCell::updateAdjacent();

	switch (population)
	{
	case 0:
		if (adjPowerLines >= 1 && availableWorkers >= 2) {
			queue->generateEvent(*this);
			growth = true;
		}
		else if (adjPop[1] >= 1 && availableWorkers >= 2) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 1:
		if (adjPop[1] >= 2 && availableWorkers >= 2) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 2:
		if (adjPop[2] >= 4 && availableWorkers >= 2) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	}

	pollute();
	return growth;
}

void IndustrialCell::pollute()
{
	// Distance spread will be population - 1
	int distance = population - 1;

	// Loop through cells
	// Starting cell will be (x-dist, y-dist)
	// Ending cell will be (x+dist, y+dist)
	for (int r = row - distance; r <= row + distance; r++) {
		if (r < 0 || r >= (*map).size()) continue; // Out of bounds checking

		for (int c = col - distance; c <= col + distance; c++) {
			if (c < 0 || c >= (*map)[0].size()) continue; // Out of bounds checking

			// Each cell will receive pollution of population - max(abs(r - row), abs(c - col))
			// Where r & c are the current iterated cell, and row & col are the source cell
			int curPoll = population - std::max(abs(r - row), abs(c - col));
			(*map)[r][c]->pollution += curPoll;

		}
	}
}