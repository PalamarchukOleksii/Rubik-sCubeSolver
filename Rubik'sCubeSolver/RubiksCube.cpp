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

void RubiksCube::RightClockWise()
{
	int sideNum = 4;
	
}