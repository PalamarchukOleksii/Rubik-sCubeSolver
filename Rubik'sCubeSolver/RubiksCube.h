#pragma once

struct PositionOfCube {
	int frontSide;
	int upSide;
	int rightSide;
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
	PositionOfCube pos{ 2,0,3 };
public:
	RubiksCube(char* inputeCube);
	~RubiksCube();
	void SetInputeCube(char* inputeCube);
	void PrintCube() const;
	void RightClockWise();
};

