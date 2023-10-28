#include "pch.h"
#include "../include/IndustrialCell.h"
#include "../src/IndustrialCell.cpp"

class IndustrialCellTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		rc = new IndustrialCell(map, 'I', 0, 0);
		qc = new QueueController(w, g);

		w = 2;
		g = 2;
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
	IndustrialCell* rc = NULL;
	QueueController* qc = NULL;
	int w = 0;
	int g = 0;
};


TEST_F(IndustrialCellTest, ZeroPopGrowth)
{
	rc->population = 0;

	// Adj power line
	EXPECT_EQ(rc->step(w, g, qc), true);

	// No powerlines or pop
	rc->adjPowerLines = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test population
	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), true);
	rc->adjPop[1] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// Insufficient workers
	w = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// No available workers
	w = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);
}



TEST_F(IndustrialCellTest, OnePopGrowth)
{
	rc->population = 1;

	// No adj pop
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test population
	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);
	rc->adjPop[1] = 2;
	EXPECT_EQ(rc->step(w, g, qc), true);
	rc->adjPop[1] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// Insufficient workers
	w = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// No available workers
	w = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);
}



TEST_F(IndustrialCellTest, TwoPopGrowth)
{
	rc->population = 2;

	// No adj pop
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test population
	rc->adjPop[2] = 3;
	EXPECT_EQ(rc->step(w, g, qc), false);
	rc->adjPop[2] = 4;
	EXPECT_EQ(rc->step(w, g, qc), true);
	rc->adjPop[2] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// Insufficient workers
	w = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// No available workers
	w = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);
}



TEST_F(IndustrialCellTest, ThreePopGrowth)
{
	// Cell should never grow from 3 pop
	rc->population = 3;
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