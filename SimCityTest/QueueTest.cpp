#include "pch.h"
#include "../include/QueueController.h"
#include "../src/QueueController.cpp"
#include "../include/QueueNode.h"
#include "../src/QueueNode.cpp"
#include "../include/MapCell.h"
#include "../src/MapCell.cpp"


class QueueControllerTest : public ::testing::Test
{
protected:
	void SetUp()  
	{
		mc = new MapCell(map, 'I', 0, 0);
		qc = new QueueController(w, g);
		n1 = new QueueNode(*mc);
		n2 = new QueueNode(*mc);
		n3 = new QueueNode(*mc);
		n4 = new QueueNode(*mc);
		n5 = new QueueNode(*mc);

		n1->priority = 1000;
		n2->priority = 500;
		n3->priority = 1293;
		n4->priority = 1293;
		n5->priority = 0;

		qc->insert(n1);
		qc->insert(n2);
		qc->insert(n3);
		qc->insert(n4);
		qc->insert(n5);
	}

	void TearDown() override 
	{
		delete mc;
		delete qc;
		delete n1;
		delete n2;
		delete n3;
		delete n4;
		delete n5;
	}

	std::vector<std::vector<MapCell*>> map;
	MapCell* mc = NULL;
	QueueController* qc = NULL;
	int w = 0;
	int g = 0;

	QueueNode* n1 = NULL;
	QueueNode* n2 = NULL;
	QueueNode* n3 = NULL;
	QueueNode* n4 = NULL;
	QueueNode* n5 = NULL;
};

TEST_F(QueueControllerTest, TestInsertionOrder)
{
	EXPECT_EQ(qc->head, n3);
	EXPECT_EQ(qc->head->next, n4);
	EXPECT_EQ(qc->head->next->next, n1);
	EXPECT_EQ(qc->head->next->next->next, n2);
	EXPECT_EQ(qc->head->next->next->next->next, n5);
}