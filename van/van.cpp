#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "populateArrays.h"
#include "printBill.h"
#define STRINGL 50
#define N 7

int main()
{
	int arrTime[N];
	int arrPrice[N];
	int arrSelections[N];
	char *arrDishes[] = { "Cheese Fries","Beef","Fish","Pork","Chicken","Italian pizza","Buffalo Wings" };
	populateArrays(arrDishes, arrTime, arrPrice, arrSelections);
	char respond;
	char buffer[127];
	int selection = 0;
	printf("Welcome to our restaurant! Here you can eat the most delicious food \nin the world. Would you like to order something?\nEnter (Y/N):\n");
	do
	{
		scanf("%127s", &buffer);
		if (strlen(buffer) != 1)
		{
			printf("Error! Try again\n");
			continue;
		}
		else
		{
			respond = buffer[0];
		}
		switch (respond)
		{
		case 'Y': printf("We're glad to hear it. Wait a little bit, after a few seconds you can see our \nmenu.\n");
		Sleep(rand()%2000+2000);
        system("cls");
            printf("|---------------------------------------------------|\n");
			printf("|MENU OF OUR RESTAURANT                             |\n");
			printf("|---------------------------------------------------|\n");
			printf("|      Dish       |Cooking time(min)|    Price($)   |\n");
			printf("|                 |                 |               |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 1.Cheese Fries  |       30        |       5       |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 2.Beef          |       35        |       7       |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 3.Fish          |       40        |       9       |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 4.Pork          |       45        |       11      |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 5.Chicken       |       50        |       13      |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 6.Italian pizza |       55        |       15      |\n");
			printf("|-----------------|-----------------|---------------|\n");
			printf("| 7.Buffalo Wings |       60        |       17      |\n");
			printf("|-----------------|-----------------|---------------|\n");


			printf("What would you like to eat? Select number from the menu(8 to finish ordering)\n");
			while (((scanf("%d", &selection)) != 1) || (selection > N))
			{
				while (getchar() != '\n');
				fprintf(stderr, "Error! Please, try again!\n");
			}

			do
			{
				arrSelections[selection - 1] += 1;
				printf("Would you like anything else? Select number from the menu(%d to finish ordering)\n", N + 1);
				while ((scanf("%d", &selection)) != 1 || (selection>8))
				{
					while (getchar() != '\n');
					fprintf(stderr, "Error! Please, try again!\n");
				}

			} while (selection != N + 1);

        system("cls");

			printBill(arrDishes, arrTime, arrPrice, arrSelections);


			break;
		case 'N': printf("Ok! Tell us if you want something. Bye\n");
			break;
		default: printf("What? Please, use Y/N to answer my questions\n");
			printf("Enter Y or N, please\n");
			break;
		}
	} while (respond != 'Y');
	system("pause");
	return 0;
}
