#include "pch.h"
#include "../include/CommercialCell.h"
#include "../src/CommercialCell.cpp"

class CommercialCellTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		rc = new CommercialCell(map, 'C', 0, 0);
		qc = new QueueController(w, g);

		w = 1;
		g = 1;
		rc->adjPowerPlants = 10;
		rc->adjRoads = 10;
		rc->adjPowerLines = 10;
	}
	void TearDown()
	{
		delete rc;
		delete qc;
	}

	std::vector<std::vector<MapCell*>> map;
	CommercialCell* rc = NULL;
	QueueController* qc = NULL;
	int w = 0;
	int g = 0;
};


TEST_F(CommercialCellTest, ZeroPopGrowth)
{
	rc->population = 0;

	// Adj powerline
	EXPECT_EQ(rc->step(w, g, qc), true);

	// No powerlines
	rc->adjPowerLines = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test population
	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// No available workers
	w = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// No available goods
	w = 1;
	g = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);
}



TEST_F(CommercialCellTest, OnePopGrowth)
{
	rc->population = 1;

	// No adj pop
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test population
	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);
	rc->adjPop[1] = 2;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// No available workers
	w = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// No available goods
	w = 1;
	g = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);
}



TEST_F(CommercialCellTest, TwoPopGrowth)
{
	// Cell should never grow from 2 pop
	rc->population = 2;
	w = 10;
	g = 10;
	rc->adjPowerPlants = 10;
	rc->adjRoads = 10;
	rc->adjPowerLines = 10;
	rc->adjPop[0] = 10;
	rc->adjPop[1] = 10;
	rc->adjPop[2] = 10;
	rc->adjPop[3] = 10;
	rc->adjPop[4] = 10;
	rc->adjPop[5] = 10;
	EXPECT_EQ(rc->step(w, g, qc), false);
}