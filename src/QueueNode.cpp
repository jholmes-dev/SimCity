#include "../include/QueueNode.h"

QueueNode::QueueNode(MapCell& sourceCell, int workers, int goods)
{
	this->cell = &sourceCell;
	this->reqWorkers = workers;
	this->reqGoods = goods;
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
	std::cout << "Executed node: " << priority << std::endl;
	if (*workers >= reqWorkers && *goods >= reqGoods)
	{
		*workers -= reqWorkers;
		*goods -= reqGoods;
		cell->population++;
	}
}

void QueueNode::setPriority()
{
	if (cell->type == 'C') priority += 2000;
	else if (cell->type == 'I') priority += 1000;

	priority += cell->population * 100;
	priority += cell->totalAdjPop;
}
