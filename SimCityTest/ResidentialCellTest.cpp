#include "pch.h"
#include "../include/ResidentialCell.h"
#include "../src/ResidentialCell.cpp"

class ResidentialCellTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		rc = new ResidentialCell(map, 'R', 0, 0);
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
	ResidentialCell* rc = NULL;
	QueueController* qc = NULL;
	int w = 0;
	int g = 0;
};


TEST_F(ResidentialCellTest, ZeroPopGrowth)
{
	rc->population = 0;

	// Adj powerline
	EXPECT_EQ(rc->step(w, g, qc), true);

	// No powerlines or pop
	rc->adjPowerLines = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Adjacent population
	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), true);
	rc->adjPop[1] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);
}



TEST_F(ResidentialCellTest, OnePopGrowth)
{
	rc->population = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test adjacent population
	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), false);

	rc->adjPop[1] = 2;
	EXPECT_EQ(rc->step(w, g, qc), true);

	rc->adjPop[1] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);
}



TEST_F(ResidentialCellTest, TwoPopGrowth)
{
	rc->population = 2;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test adjacent population
	rc->adjPop[2] = 3;
	EXPECT_EQ(rc->step(w, g, qc), false);

	rc->adjPop[2] = 4;
	EXPECT_EQ(rc->step(w, g, qc), true);

	rc->adjPop[2] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);
}



TEST_F(ResidentialCellTest, ThreePopGrowth)
{
	rc->population = 3;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test adjacent population
	rc->adjPop[3] = 5;
	EXPECT_EQ(rc->step(w, g, qc), false);

	rc->adjPop[3] = 6;
	EXPECT_EQ(rc->step(w, g, qc), true);

	rc->adjPop[3] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);
}



TEST_F(ResidentialCellTest, FourPopGrowth)
{
	rc->population = 4;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Test adjacent population
	rc->adjPop[4] = 7;
	EXPECT_EQ(rc->step(w, g, qc), false);

	rc->adjPop[4] = 8;
	EXPECT_EQ(rc->step(w, g, qc), true);

	rc->adjPop[4] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);
}



TEST_F(ResidentialCellTest, FivePopGrowth)
{
	rc->population = 5;
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