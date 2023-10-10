#include <iostream>
#include "RubiksCube.h"

int main() {
	system("color 8");
	char startCube[] = { 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g',
		'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y' };
	RubiksCube cube(startCube);
	cube.makeAlgorithm({ "L'", "F2", "D2", "R", "B2", "U2", "F2", "U2", "L", "D2", "R2", "B", "D'", "L'", "R2", "D2", "B", "D2", "L", "R2", "U" });
	cube.printCube();
	return 0;
}