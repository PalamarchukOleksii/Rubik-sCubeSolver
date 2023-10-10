#include "RubiksCube.h"
#include <iostream>
#include "ConsoleInfo.h"

void RubiksCube::turnStickersClockWise(int side)
{
	char tempCube[9]{};
	tempCube[0] = cube[side * 9 + 6];
	tempCube[1] = cube[side * 9 + 3];
	tempCube[2] = cube[side * 9 + 0];
	tempCube[3] = cube[side * 9 + 7];
	tempCube[4] = cube[side * 9 + 4];
	tempCube[5] = cube[side * 9 + 1];
	tempCube[6] = cube[side * 9 + 8];
	tempCube[7] = cube[side * 9 + 5];
	tempCube[8] = cube[side * 9 + 2];

	for (int i = 0;i < 9;i++) {
		cube[side * 9 + i] = tempCube[i];
	}
}

void RubiksCube::turnStickersCounterClockWise(int side)
{
	char tempCube[9]{};
	tempCube[6] = cube[side * 9 + 0];
	tempCube[3] = cube[side * 9 + 1];
	tempCube[0] = cube[side * 9 + 2];
	tempCube[7] = cube[side * 9 + 3];
	tempCube[4] = cube[side * 9 + 4];
	tempCube[1] = cube[side * 9 + 5];
	tempCube[8] = cube[side * 9 + 6];
	tempCube[5] = cube[side * 9 + 7];
	tempCube[2] = cube[side * 9 + 8];

	for (int i = 0;i < 9;i++) {
		cube[side * 9 + i] = tempCube[i];
	}
}

void RubiksCube::turnStickersTwoTimes(int side)
{
	int temp;
	for (int i = 0;i < 5;i++) {
		temp = cube[side * 9 + i];
		cube[side * 9 + +i] = cube[side * 9 + 8 - i];
		cube[side * 9 + 8 - i] = temp;
	}
}

RubiksCube::RubiksCube(char* inputeCube)
{
	setInputeCube(inputeCube);
}

RubiksCube::~RubiksCube()
{
}

void RubiksCube::setInputeCube(char* inputeCube)
{
	for (int i = 0;i < stickersCount;i++) {
		switch (inputeCube[i]) {
		case 'w': cube[i] = 0;
			break;
		case 'o': cube[i] = 1;
			break;
		case 'g': cube[i] = 2;
			break;
		case 'r': cube[i] = 3;
			break;
		case 'b': cube[i] = 4;
			break;
		case 'y': cube[i] = 5;
			break;
		}
	}
}

void RubiksCube::printCube() const
{
	COORD coord{};
	for (int i = 0;i < sidesCount;i++) {
		for (int j = 0;j < cubeSize;j++) {
			for (int k = 0; k < cubeSize;k++) {
				if (!i) {
					coord.X = cubeSize * 2 + k % 3 * 2;
					coord.Y = j;
				}
				else if (i == 5) {
					coord.X = cubeSize * 2 + k % 3 * 2;
					coord.Y = j + cubeSize * 2;
				}
				else {
					coord.X = cubeSize * (i - 1) * 2 + k % 3 * 2;
					coord.Y = j + cubeSize;
				}
				SetConsoleCursorPosition(stdOutPutHandle, coord);
				SetConsoleTextAttribute(stdOutPutHandle, colors[cube[i * 9 + j * 3 + k]]);
				std::cout << char(219) << char(219);
			}
		}
	}
}

void RubiksCube::makeAlgorithm(std::vector<std::string> algorithm)
{
	for (int i = 0;i < algorithm.size();i++) {
		if (algorithm[i] == "R") {
			turnRightClockWise();
			continue;
		}
		if (algorithm[i] == "R'") {
			turnRightCounterClockWise();
			continue;
		}
		if (algorithm[i] == "R2") {
			turnRightTwoTimes();
			continue;
		}
		if (algorithm[i] == "L") {
			turnLeftClockWise();
			continue;
		}
		if (algorithm[i] == "L'") {
			turnLeftCounterClockWise();
			continue;
		}
		if (algorithm[i] == "L2") {
			turnLeftTwoTimes();
			continue;
		}
		if (algorithm[i] == "U") {
			turnUpClockWise();
			continue;
		}
		if (algorithm[i] == "U'") {
			turnUpCounterClockWise();
			continue;
		}
		if (algorithm[i] == "U2") {
			turnUpTwoTimes();
			continue;
		}
		if (algorithm[i] == "D") {
			turnDownClockWise();
			continue;
		}
		if (algorithm[i] == "D'") {
			turnDownCounterClockWise();
			continue;
		}
		if (algorithm[i] == "D2") {
			turnDownTwoTimes();
			continue;
		}
		if (algorithm[i] == "F") {
			turnFrontClockWise();
			continue;
		}
		if (algorithm[i] == "F'") {
			turnFrontCounterClockWise();
			continue;
		}
		if (algorithm[i] == "F2") {
			turnFrontTwoTimes();
			continue;
		}
		if (algorithm[i] == "B") {
			turnBackClockWise();
			continue;
		}
		if (algorithm[i] == "B'") {
			turnBackCounterClockWise();
			continue;
		}
		if (algorithm[i] == "B2") {
			turnBackTwoTimes();
			continue;
		}
	}
}

void RubiksCube::turnUpClockWise()
{
	turnStickersClockWise(0);

	int tempFront[3]{}, tempBack[3]{}, tempLeft[3]{}, tempRight[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i];
		tempBack[i] = cube[4 * sideStickersCount + i];
		tempLeft[i] = cube[1 * sideStickersCount + i];
		tempRight[i] = cube[3 * sideStickersCount + i];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i] = tempRight[i];
		cube[4 * sideStickersCount + i] = tempLeft[i];
		cube[1 * sideStickersCount + i] = tempFront[i];
		cube[3 * sideStickersCount + i] = tempBack[i];
	}
}

void RubiksCube::turnUpCounterClockWise()
{
	turnStickersCounterClockWise(0);

	int tempFront[3]{}, tempBack[3]{}, tempLeft[3]{}, tempRight[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i];
		tempBack[i] = cube[4 * sideStickersCount + i];
		tempLeft[i] = cube[1 * sideStickersCount + i];
		tempRight[i] = cube[3 * sideStickersCount + i];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i] = tempLeft[i];
		cube[4 * sideStickersCount + i] = tempRight[i];
		cube[1 * sideStickersCount + i] = tempBack[i];
		cube[3 * sideStickersCount + i] = tempFront[i];
	}
}

void RubiksCube::turnUpTwoTimes()
{
	turnStickersTwoTimes(0);

	int tempFront[3]{}, tempBack[3]{}, tempLeft[3]{}, tempRight[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i];
		tempBack[i] = cube[4 * sideStickersCount + i];
		tempLeft[i] = cube[1 * sideStickersCount + i];
		tempRight[i] = cube[3 * sideStickersCount + i];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i] = tempBack[i];
		cube[4 * sideStickersCount + i] = tempFront[i];
		cube[1 * sideStickersCount + i] = tempRight[i];
		cube[3 * sideStickersCount + i] = tempLeft[i];
	}
}

void RubiksCube::turnDownClockWise()
{
	turnStickersClockWise(5);

	int tempFront[3]{}, tempBack[3]{}, tempLeft[3]{}, tempRight[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i + 6];
		tempBack[i] = cube[4 * sideStickersCount + i + 6];
		tempLeft[i] = cube[1 * sideStickersCount + i + 6];
		tempRight[i] = cube[3 * sideStickersCount + i + 6];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i + 6] = tempLeft[i];
		cube[4 * sideStickersCount + i + 6] = tempRight[i];
		cube[1 * sideStickersCount + i + 6] = tempBack[i];
		cube[3 * sideStickersCount + i + 6] = tempFront[i];
	}
}

void RubiksCube::turnDownCounterClockWise()
{
	turnStickersCounterClockWise(5);

	int tempFront[3]{}, tempBack[3]{}, tempLeft[3]{}, tempRight[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i + 6];
		tempBack[i] = cube[4 * sideStickersCount + i + 6];
		tempLeft[i] = cube[1 * sideStickersCount + i + 6];
		tempRight[i] = cube[3 * sideStickersCount + i + 6];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i + 6] = tempRight[i];
		cube[4 * sideStickersCount + i + 6] = tempLeft[i];
		cube[1 * sideStickersCount + i + 6] = tempFront[i];
		cube[3 * sideStickersCount + i + 6] = tempBack[i];
	}
}

void RubiksCube::turnDownTwoTimes()
{
	turnStickersTwoTimes(5);

	int tempFront[3]{}, tempBack[3]{}, tempLeft[3]{}, tempRight[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i + 6];
		tempBack[i] = cube[4 * sideStickersCount + i + 6];
		tempLeft[i] = cube[1 * sideStickersCount + i + 6];
		tempRight[i] = cube[3 * sideStickersCount + i + 6];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i + 6] = tempBack[i];
		cube[4 * sideStickersCount + i + 6] = tempFront[i];
		cube[1 * sideStickersCount + i + 6] = tempRight[i];
		cube[3 * sideStickersCount + i + 6] = tempLeft[i];
	}
}

void RubiksCube::turnLeftClockWise()
{
	turnStickersClockWise(1);

	int tempFront[3]{}, tempBack[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i * 3];
		tempBack[i] = cube[4 * sideStickersCount + 8 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + i * 3];
		tempDown[i] = cube[5 * sideStickersCount + i * 3];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i * 3] = tempUp[i];
		cube[4 * sideStickersCount + 8 - (i * 3)] = tempDown[i];
		cube[0 * sideStickersCount + i * 3] = tempBack[i];
		cube[5 * sideStickersCount + i * 3] = tempFront[i];
	}
}

void RubiksCube::turnLeftCounterClockWise()
{
	turnStickersCounterClockWise(1);

	int tempFront[3]{}, tempBack[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i * 3];
		tempBack[i] = cube[4 * sideStickersCount + 8 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + i * 3];
		tempDown[i] = cube[5 * sideStickersCount + i * 3];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i * 3] = tempDown[i];
		cube[4 * sideStickersCount + 8 - (i * 3)] = tempUp[i];
		cube[0 * sideStickersCount + i * 3] = tempFront[i];
		cube[5 * sideStickersCount + i * 3] = tempBack[i];
	}
}

void RubiksCube::turnLeftTwoTimes()
{
	turnStickersTwoTimes(1);

	int tempFront[3]{}, tempBack[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i * 3];
		tempBack[i] = cube[4 * sideStickersCount + 8 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + i * 3];
		tempDown[i] = cube[5 * sideStickersCount + i * 3];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i * 3] = tempBack[i];
		cube[4 * sideStickersCount + 8 - (i * 3)] = tempFront[i];
		cube[0 * sideStickersCount + i * 3] = tempDown[i];
		cube[5 * sideStickersCount + i * 3] = tempUp[i];
	}
}

void RubiksCube::turnRightClockWise()
{
	turnStickersClockWise(3);

	int tempFront[3]{}, tempBack[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i * 3 + 2];
		tempBack[i] = cube[4 * sideStickersCount + 6 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + i * 3 + 2];
		tempDown[i] = cube[5 * sideStickersCount + i * 3 + 2];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i * 3 + 2] = tempDown[i];
		cube[4 * sideStickersCount + 6 - (i * 3)] = tempUp[i];
		cube[0 * sideStickersCount + i * 3 + 2] = tempFront[i];
		cube[5 * sideStickersCount + i * 3 + 2] = tempBack[i];
	}
}

void RubiksCube::turnRightCounterClockWise()
{
	turnStickersCounterClockWise(3);

	int tempFront[3]{}, tempBack[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i * 3 + 2];
		tempBack[i] = cube[4 * sideStickersCount + 6 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + i * 3 + 2];
		tempDown[i] = cube[5 * sideStickersCount + i * 3 + 2];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i * 3 + 2] = tempUp[i];
		cube[4 * sideStickersCount + 6 - (i * 3)] = tempDown[i];
		cube[0 * sideStickersCount + i * 3 + 2] = tempBack[i];
		cube[5 * sideStickersCount + i * 3 + 2] = tempFront[i];
	}
}

void RubiksCube::turnRightTwoTimes()
{
	turnStickersTwoTimes(3);

	int tempFront[3]{}, tempBack[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempFront[i] = cube[2 * sideStickersCount + i * 3 + 2];
		tempBack[i] = cube[4 * sideStickersCount + 6 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + i * 3 + 2];
		tempDown[i] = cube[5 * sideStickersCount + i * 3 + 2];
	}

	for (int i = 0; i < 3; i++) {
		cube[2 * sideStickersCount + i * 3 + 2] = tempBack[i];
		cube[4 * sideStickersCount + 6 - (i * 3)] = tempFront[i];
		cube[0 * sideStickersCount + i * 3 + 2] = tempDown[i];
		cube[5 * sideStickersCount + i * 3 + 2] = tempUp[i];
	}
}

void RubiksCube::turnFrontClockWise()
{
	turnStickersClockWise(2);

	int tempRight[3]{}, tempLeft[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempLeft[i] = cube[1 * sideStickersCount + 8 - (i * 3)];
		tempRight[i] = cube[3 * sideStickersCount + i * 3];
		tempUp[i] = cube[0 * sideStickersCount + i + 6];
		tempDown[i] = cube[5 * sideStickersCount + 2 - i];
	}

	for (int i = 0; i < 3; i++) {
		cube[1 * sideStickersCount + 8 - (i * 3)] = tempDown[i];
		cube[3 * sideStickersCount + i * 3] = tempUp[i];
		cube[0 * sideStickersCount + i + 6] = tempLeft[i];
		cube[5 * sideStickersCount + 2 - i] = tempRight[i];
	}
}

void RubiksCube::turnFrontCounterClockWise()
{
	turnStickersCounterClockWise(2);

	int tempRight[3]{}, tempLeft[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempLeft[i] = cube[1 * sideStickersCount + 8 - (i * 3)];
		tempRight[i] = cube[3 * sideStickersCount + i * 3];
		tempUp[i] = cube[0 * sideStickersCount + i + 6];
		tempDown[i] = cube[5 * sideStickersCount + 2 - i];
	}

	for (int i = 0; i < 3; i++) {
		cube[1 * sideStickersCount + 8 - (i * 3)] = tempUp[i];
		cube[3 * sideStickersCount + i * 3] = tempDown[i];
		cube[0 * sideStickersCount + i + 6] = tempRight[i];
		cube[5 * sideStickersCount + 2 - i] = tempLeft[i];
	}
}

void RubiksCube::turnFrontTwoTimes()
{
	turnStickersTwoTimes(2);

	int tempRight[3]{}, tempLeft[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempLeft[i] = cube[1 * sideStickersCount + 8 - (i * 3)];
		tempRight[i] = cube[3 * sideStickersCount + i * 3];
		tempUp[i] = cube[0 * sideStickersCount + i + 6];
		tempDown[i] = cube[5 * sideStickersCount + 2 - i];
	}

	for (int i = 0; i < 3; i++) {
		cube[1 * sideStickersCount + 8 - (i * 3)] = tempRight[i];
		cube[3 * sideStickersCount + i * 3] = tempLeft[i];
		cube[0 * sideStickersCount + i + 6] = tempDown[i];
		cube[5 * sideStickersCount + 2 - i] = tempUp[i];
	}
}

void RubiksCube::turnBackClockWise()
{
	turnStickersClockWise(4);

	int tempRight[3]{}, tempLeft[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempLeft[i] = cube[1 * sideStickersCount + i * 3];
		tempRight[i] = cube[3 * sideStickersCount + 8 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + 2 - i];
		tempDown[i] = cube[5 * sideStickersCount + i + 6];
	}

	for (int i = 0; i < 3; i++) {
		cube[1 * sideStickersCount + i * 3] = tempUp[i];
		cube[3 * sideStickersCount + 8 - (i * 3)] = tempDown[i];
		cube[0 * sideStickersCount + 2 - i] = tempRight[i];
		cube[5 * sideStickersCount + i + 6] = tempLeft[i];
	}
}

void RubiksCube::turnBackCounterClockWise()
{
	turnStickersCounterClockWise(4);

	int tempRight[3]{}, tempLeft[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempLeft[i] = cube[1 * sideStickersCount + i * 3];
		tempRight[i] = cube[3 * sideStickersCount + 8 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + 2 - i];
		tempDown[i] = cube[5 * sideStickersCount + i + 6];
	}

	for (int i = 0; i < 3; i++) {
		cube[1 * sideStickersCount + i * 3] = tempDown[i];
		cube[3 * sideStickersCount + 8 - (i * 3)] = tempUp[i];
		cube[0 * sideStickersCount + 2 - i] = tempLeft[i];
		cube[5 * sideStickersCount + i + 6] = tempRight[i];
	}
}

void RubiksCube::turnBackTwoTimes()
{
	turnStickersTwoTimes(4);

	int tempRight[3]{}, tempLeft[3]{}, tempUp[3]{}, tempDown[3]{};

	for (int i = 0; i < 3; i++) {
		tempLeft[i] = cube[1 * sideStickersCount + i * 3];
		tempRight[i] = cube[3 * sideStickersCount + 8 - (i * 3)];
		tempUp[i] = cube[0 * sideStickersCount + 2 - i];
		tempDown[i] = cube[5 * sideStickersCount + i + 6];
	}

	for (int i = 0; i < 3; i++) {
		cube[1 * sideStickersCount + i * 3] = tempRight[i];
		cube[3 * sideStickersCount + 8 - (i * 3)] = tempLeft[i];
		cube[0 * sideStickersCount + 2 - i] = tempDown[i];
		cube[5 * sideStickersCount + i + 6] = tempUp[i];
	}
}