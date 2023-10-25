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

	// Nothing adjacent
	EXPECT_EQ(rc->step(w, g, qc), false);

	// With available resources, but nothing else
	w = 10;
	g = 10;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Add adjacent power plants
	rc->adjPowerPlants = 10;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Add adjacent roads
	rc->adjRoads = 10;
	EXPECT_EQ(rc->step(w, g, qc), false);

	// Add adjacent power line
	rc->adjPowerLines = 1;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// Remove workers and goods
	w = 0;
	g = 0;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// Multiple power lines
	rc->adjPowerLines = 100;
	EXPECT_EQ(rc->step(w, g, qc), true);

	// Remove powerlines, test adjacent population
	rc->adjPowerLines = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);

	rc->adjPop[1] = 1;
	EXPECT_EQ(rc->step(w, g, qc), true);

	rc->adjPop[1] = 10;
	EXPECT_EQ(rc->step(w, g, qc), true);

	rc->adjPop[1] = 0;
	EXPECT_EQ(rc->step(w, g, qc), false);
}