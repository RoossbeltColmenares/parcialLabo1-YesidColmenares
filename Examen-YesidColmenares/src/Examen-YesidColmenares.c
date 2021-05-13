/*
 ============================================================================
 Name        : Examen-YesidColmenares.c
 Author      : Yesid Colmenares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexo/nexo.h"

int main(void)
{
	setbuf(stdout, NULL);

	eJob listJ[SIZE_J];
	eDate date[SIZE_D];
	eService listS[SIZE_S];

	int optionEntered;
	int whileCondition;

	initialitationJob(listJ, SIZE_J);
	hardCodeService(listS, SIZE_S);
	do
	{
		printf("\n-------------------WELCOM TO OUR DATA SYSTEM--------------------");
		printf("\n1. Add job");
		printf("\n2. Modify job");
		printf("\n3. Remove job");
		printf("\n4. Job list");
		printf("\n5. List of services");
		printf("\n6. Total");
		printf("\n7. Exit");

		inputIntR(&optionEntered, "\nEnter option: ", "\nError, enter option: ", 1, 12);
		switch (optionEntered)
		{
			case 1:
				system("cls");
				addJob(listJ, SIZE_J, listS, SIZE_S, date, SIZE_D);
				break;

			case 2:
				system("cls");
				break;

			case 3:
				system("cls");
				break;

			case 4:
				system("cls");
				break;

			case 5:
				system("cls");
				break;

			case 6:
				system("cls");
				break;

			case 7:
				system("cls");
				whileCondition = 7;
				break;
		}
	} while (whileCondition != 7);
}
