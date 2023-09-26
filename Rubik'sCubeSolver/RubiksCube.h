#pragma once
#include <string>
#include <vector>

class RubiksCube
{
private:
	int sidesCount = 6;
	int cubeSize = 3;
	int sideStickersCount = 9;
	int stickersCount = 54;
	int cube[54];
	char inputeCube[54];

	void turnStickersClockWise(int side);
	void turnStickersCounterClockWise(int side);
	void turnStickersTwoTimes(int side);

	void setInputeCube(char* inputeCube);
public:
	RubiksCube(char* inputeCube);
	~RubiksCube();
	void printCube() const;

	void makeAlgorithm(std::vector<std::string> algorithm);

	void turnUpClockWise();
	void turnUpCounterClockWise();
	void turnUpTwoTimes();

	void turnDownClockWise();
	void turnDownCounterClockWise();
	void turnDownTwoTimes();

	void turnLeftClockWise();
	void turnLeftCounterClockWise();
	void turnLeftTwoTimes();

	void turnRightClockWise();
	void turnRightCounterClockWise();
	void turnRightTwoTimes();

	void turnFrontClockWise();
	void turnFrontCounterClockWise();
	void turnFrontTwoTimes();

	void turnBackClockWise();
	void turnBackCounterClockWise();
	void turnBackTwoTimes();
};

