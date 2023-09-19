#include "RubiksCube.h"
#include <iostream>
#include "ConsoleInfo.h"

RubiksCube::RubiksCube(char* inputeCube)
{
	cube = nullptr;
	try {
		cube = new int** [sidesCount];
		if (!cube) {
			throw;
		}
		for (int i = 0;i < sidesCount;i++) {
			cube[i] = new int* [cubeSize];
			if (!cube[i]) {
				throw;
			}
			for (int j = 0;j < cubeSize;j++) {
				cube[i][j] = new int[cubeSize];
				if (!cube[i][j]) {
					throw;
				}
			}
		}	
		SetInputeCube(inputeCube);
	}
	catch(std::exception& ex){
		this->~RubiksCube();
		std::cout << "Rubik's Cube COnstructor. Allocation Error!" << std::endl;
		std::cout << ex.what() << std::endl;
		throw;
	}
}

RubiksCube::~RubiksCube()
{
	if (cube) {
		for (int i = 0; i < sidesCount;i++) {
			if (cube[i]) {
				for (int j = 0;j < cubeSize;j++) {
					delete[] cube[i][j];
				}
				delete[] cube[i];
			}
		}
		delete[] cube;
	}
}

void RubiksCube::SetInputeCube(char* inputeCube)
{
	for (int i = 0;i < sidesCount;i++) {
		for (int j = 0;j < cubeSize;j++) {
			for (int k = 0; k < cubeSize;k++) {
				switch (inputeCube[i * 9 + j * 3 + k]) {
				case 'w': cube[i][j][k] = 0;
					break;
				case 'o': cube[i][j][k] = 1;
					break;
				case 'g': cube[i][j][k] = 2;
					break;
				case 'r': cube[i][j][k] = 3;
					break;
				case 'b': cube[i][j][k] = 4;
					break;
				case 'y': cube[i][j][k] = 5;
					break;
				}
			}
		}
	}
}

void RubiksCube::PrintCube() const
{
	COORD coord;
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
				SetConsoleTextAttribute(stdOutPutHandle, colors[cube[i][j][k]]);
				std::cout << char(219) << char(219);
			}
		}
	}
}

void RubiksCube::TurnSide(char side, int turnsAmount)
{
	int sideNum = FaceIdentification(side);
	int turnCount = turnsAmount;
	if (turnCount == -1) {
		turnCount = 3;
	}
	int** tempSide = nullptr;
	try {
		tempSide = new int* [cubeSize];
		if (!tempSide) {
			throw;
		}
		for (int i = 0;i < cubeSize;i++) {
			tempSide[i] = new int[cubeSize];
			if (!tempSide[i]) {
				throw;
			}
		}
	}
	catch (std::exception& ex) {
		if (tempSide) {
			for (int i = 0;i < cubeSize;i++) {
				if (tempSide) {
					delete[] tempSide[i];
				}
			}
			delete[] tempSide;
		}
		std::cout << ex.what() << std::endl;
		throw;
	}

	for (int k = 0;k < turnCount;k++) {
		for (int i = 0;i < cubeSize;i++) {
			for (int j = 0;j < cubeSize;j++) {
				tempSide[i][j] = cube[sideNum][2 - j][i];
			}
		}
		for (int i = 0;i < cubeSize;i++) {
			for (int j = 0;j < cubeSize;j++) {
				cube[sideNum][i][j] = tempSide[i][j];
			}
		}
	}

	for (int i = 0;i < cubeSize;i++) {
		delete[] tempSide[i];
	}
	delete[] tempSide;

	int* neighborSideSequence = NeighborSides(side);
	bool row = false;
	bool cols = false;
	if (neighborSideSequence[5]==1) {
		row = true;
	}
	else if(neighborSideSequence[5] == 2) {
		cols = true;
	}
	int tempLine[3];
	int movedLine[3];
	for (int i = 0;i < 4;i++) {
		if (!i) {
			for (int j = 0;j < 3;j++) {
				if (row) {
					movedLine[j] = cube[neighborSideSequence[i]][neighborSideSequence[4]][j];
				}
				if (cols) {
					movedLine[j] = cube[neighborSideSequence[i]][2 - j][neighborSideSequence[4]];
				}
			}
		}
		if (i == 3) {
			i = -1;
		}
		for (int j = 0;j < 3;j++) {
			if (row) {
				tempLine[j] = cube[neighborSideSequence[i+1]][neighborSideSequence[4]][j];
				cube[neighborSideSequence[i + 1]][neighborSideSequence[4]][j] = movedLine[j];
				movedLine[j] = tempLine[j];
			}
			if (cols) {
				tempLine[j] = cube[neighborSideSequence[i+1]][2 - j][neighborSideSequence[4]];
				cube[neighborSideSequence[i + 1]][2 - j][neighborSideSequence[4]] = movedLine[j];
				movedLine[j] = tempLine[j];
			}
		}
		if (i == -1) {
			break;
		}
	}
}

int RubiksCube::FaceIdentification(char side) const
{
	switch (std::tolower(side)) {
	case 'u': return sidePosition.upSide;
		break;
	case 'd': return sidePosition.downSide;
		break;
	case 'f': return sidePosition.frontSide;
		break;
	case 'b': return sidePosition.backSide;
		break;
	case 'l': return sidePosition.leftSide;
		break;
	case 'r': return sidePosition.rightSide;
		break;
	}
}

int* RubiksCube::NeighborSides(char side) const
{
	switch (std::tolower(side)) {
	case 'u': {
		int neighborSides[] = { FaceIdentification('f'),FaceIdentification('l'),FaceIdentification('b'),FaceIdentification('r'),0,1 };
		return neighborSides;
	}
			break;
	case 'd': {
		int neighborSides[] = { FaceIdentification('f'),FaceIdentification('r'),FaceIdentification('b'),FaceIdentification('l'),2,1 };
		return neighborSides;
	}
			break;
	case 'f': {
		int neighborSides[] = { FaceIdentification('u'),FaceIdentification('r'),FaceIdentification('d'),FaceIdentification('l'),2,1 };
		return neighborSides;
	}
			break;
	case 'b': {
		int neighborSides[] = { FaceIdentification('u'),FaceIdentification('l'),FaceIdentification('d'),FaceIdentification('r'),0,1 };
		return neighborSides;
	}
			break;
	case 'l': {
		int neighborSides[] = { FaceIdentification('u'),FaceIdentification('f'),FaceIdentification('d'),FaceIdentification('b'),0,2 };
		return neighborSides;
	}
			break;
	case 'r': {
		int neighborSides[] = { FaceIdentification('u'),FaceIdentification('b'),FaceIdentification('d'),FaceIdentification('f'),2,2 };
		return neighborSides;
	}
			break;
	}
}