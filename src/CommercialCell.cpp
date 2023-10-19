#include "../include/CommercialCell.h"

/**
 * If a cell has a population of 0, is adjacent to a powerline in the current time step, there is at least 1 available worker, 
 * and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available 
 * worker and available good are assigned to that job
 * 
 * If a cell has a population of 0, is adjacent to at least one cell with a population of at least 1, there is at least 1 
 * available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time 
 * step and the available worker and available good are assigned to that job
 * 
 * If a cell has a population of 1, is adjacent to at least two cells with a population of at least 1, there is at least 1 
 * available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time 
 * step and the available worker and available good are assigned to that job
 **/

bool CommercialCell::step(int& availableWorkers, int& availableGoods, QueueController* queue)
{
	bool growth = false;
	MapCell::updateAdjacent();

	switch (population)
	{
	case 0:
		if (adjPowerLines >= 1 && availableWorkers >= 1 && availableGoods >= 1) {
			queue->generateEvent(*this);
			growth = true;
		}
		else if (adjPop[1] >= 1 && availableWorkers >= 1 && availableGoods >= 1) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	case 1:
		if (adjPop[1] >= 2 && availableWorkers >= 1 && availableGoods >= 1) {
			queue->generateEvent(*this);
			growth = true;
		}
		break;
	}

	return growth;
}
