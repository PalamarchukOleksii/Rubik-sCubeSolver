#pragma once
#include <windows.h>

HANDLE stdOutPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

int colors[] = { FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, FOREGROUND_INTENSITY | FOREGROUND_RED,
		FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_BLUE, FOREGROUND_GREEN | FOREGROUND_RED };