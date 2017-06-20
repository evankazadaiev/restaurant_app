#include "stdafx.h"
#include "printBill.h"
#define STRINGL 50
#define N 7

void printBill(char *arrDishes[STRINGL], int arrTime[N], int arrPrice[N], int arrSelections[N])
{
    int i = 0;
	int totalCost = 0;
	int totalTime = 0;
	FILE *f1 = fopen("Bill.txt","w");
	fprintf(f1,"|--------------------------------|\n");
	fprintf(f1,"|        YOUR CHECK              |\n");
	fprintf(f1,"|--------------------------------|\n");

	for (i = 0; i < N; i += 1)
	{
		if (totalTime < arrTime[i] && arrSelections[i]>0)
			totalTime = arrTime[i];
		totalCost += arrSelections[i] * arrPrice[i];
		if (arrSelections[i] != 0)
		{
			fprintf(f1,"|%-13s |  %-2d x %-2d = $%-4d|\n", arrDishes[i], arrPrice[i], arrSelections[i], arrSelections[i] * arrPrice[i]);
			fprintf(f1,"|--------------------------------|\n");
		}
	}

	fprintf(f1,"Your meals will be ready in %d minutes. \n", totalTime);
	fprintf(f1,"Your total bill is $%d.\n", totalCost);
	fprintf(f1,"|--------------------------------|\n");

	printf("|--------------------------------|\n");
	printf("|        YOUR CHECK              |\n");
	printf("|--------------------------------|\n");

	for (i = 0; i < N; i += 1)
	{
		if (totalTime < arrTime[i] && arrSelections[i]>0)
			totalTime = arrTime[i];
		totalCost += arrSelections[i] * arrPrice[i];
		if (arrSelections[i] != 0)
		{
			printf("|%-13s |  %-2d x %-2d = $%-4d|\n", arrDishes[i], arrPrice[i], arrSelections[i], arrSelections[i] * arrPrice[i]);
			printf("|--------------------------------|\n");
		}
	}

	printf("Your meals will be ready in %d minutes. \n", totalTime);
	printf("Your total bill is $%d.\n", totalCost);
	printf("|--------------------------------|\n");
}
