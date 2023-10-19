#include "../include/ResidentialCell.h"

/**
 * If a cell has a population of 0 and is adjacent to a powerline in the current time step, 
 * that cell’s population will increase by 1 in the next time step
 * 
 * If a cell has a population of 0 and is adjacent to at least one cell with a population 
 * of at least 1, that cell’s population will increase by 1 in the next time step
 * 
 * If a cell has a population of 1 and is adjacent to at least two cells with a population 
 * of at least 1, that cell’s population will increase by 1 in the next time step
 * 
 * If a cell has a population of 2 and is adjacent to at least four cells with a population 
 * of at least 2, that cell’s population will increase by 1 in the next time step
 * 
 * If a cell has a population of 3 and is adjacent to at least six cells with a population 
 * of at least 3, that cell’s population will increase by 1 in the next time step
 * 
 * If a cell has a population of 4 and is adjacent to at least eight cells with a population 
 * of at least 4, that cell’s population will increase by 1 in the next time step
 *
 * The residential population provides workers to the industrial and commercial zones, but 
 * each worker can only have one job
 **/

bool ResidentialCell::step(int& availableWorkers, int& availableGoods, QueueController* queue)
{
	bool growth = false;
	MapCell::updateAdjacent();

	switch (population)
	{
	case 0:
		if (adjPowerLines >= 1) {
			queue->generateEvent(*this);
			growth = true;
		}
		else if (adjPop[1] >= 1) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 1:
		if (adjPop[1] >= 2) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 2:
		if (adjPop[2] >= 4) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 3:
		if (adjPop[3] >= 6) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 4:
		if (adjPop[4] >= 8) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	}

	return growth;
}