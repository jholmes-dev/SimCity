#include "../include/QueueNode.h"

QueueNode::QueueNode(MapCell& sourceCell, int rWorkers, int rGoods)
{
	this->cell = &sourceCell;
	this->reqWorkers = rWorkers;
	this->reqGoods = rGoods;
	setPriority();
}

QueueNode::QueueNode(MapCell& sourceCell)
{
	switch (sourceCell.type)
	{
	case 'I':
		reqWorkers = 2;
		break;
	case 'C':
		reqWorkers = 1;
		reqGoods = 1;
		break;
	}

	this->cell = &sourceCell;
	setPriority();
}

void QueueNode::execute(int* workers, int* goods)
{
	if (*workers >= reqWorkers && *goods >= reqGoods)
	{
		// Adjust population
		*workers -= reqWorkers;
		*goods -= reqGoods;
		cell->population++;

		// Adjust workers or goods depending on this cell's type
		switch (cell->type)
		{
		case 'R':
			(*workers)++;
			break;
		case 'I':
			(*goods)++;
			break;
		}
	}
}

void QueueNode::setPriority()
{
	if (cell->type == 'C') priority += 2000;
	else if (cell->type == 'I') priority += 1000;

	priority += cell->population * 100;
	priority += cell->totalAdjPop;
}
