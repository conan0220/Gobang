#pragma once
#include <stdlib.h>
#include <time.h>

inline int GetRandom(const int left, const int right)
{
	srand(time(NULL));
	return rand() % (right - left + 1) + left;
}