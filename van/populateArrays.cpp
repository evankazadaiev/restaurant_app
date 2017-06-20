#include "stdafx.h"
#include "populateArrays.h"
#define STRINGL 50
#define N 7
void populateArrays(char *arrDishes[STRINGL], int arrTime[N], int arrPrice[N], int arrSelections[N])
{
    int i = 0;
	for (i = 0; i < N; i += 1)
	{
		arrTime[i] = 30 + (5 * i);
		arrPrice[i] = 5 + (2 * i);
		arrSelections[i] = 0;
	}

}
