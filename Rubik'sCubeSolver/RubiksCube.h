#pragma once

struct PositionOfCube {
	int upSide;
	int leftSide;
	int frontSide;
	int rightSide;
	int backSide;
	int downSide;
};

class RubiksCube
{
private:
	int sidesCount = 6;
	int cubeSize = 3;
	int sideStickersCount = 9;
	int stickersCount = 54;
	int*** cube;
	char* inputeCube;
	PositionOfCube sidePosition{ 0,1,2,3,4,5 };
public:
	RubiksCube(char* inputeCube);
	~RubiksCube();
	void SetInputeCube(char* inputeCube);
	void PrintCube() const;
	void TurnSide(char side, int turnsAmount);
	int FaceIdentification(char side) const;
	int* NeighborSides(char side) const;
};

