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
	eAuxiliary auxiliary[SIZE_A];

	int optionEntered;
	int whileCondition;
	int returnValueId;
	int returnValueOption;

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
				if (addJob(listJ, SIZE_J, listS, SIZE_S, date, SIZE_D) == TRUE)
				{
					system("cls");
					printf("! DATA UPLOADED SUCCESSFULLY !\n");
				}
				else
				{
					system("cls");
					printf("! There is no space available to store more Jobs !\n");
				}
				break;

			case 2:
				system("cls");
				if (thereAreJobs(listJ, SIZE_J)== TRUE)
				{
					inputIntR(&returnValueOption, "Enter 1 to modify the bicycle brand,\nEnter 2 to modify the service: ", "Error, enter 1 to modify the bicycle brand,\nError, Enter 2 to modify the service: ", 1, 2);
					system("cls");
					printJobs(listJ, SIZE_J, listS, date, auxiliary);
					inputInt(&returnValueId, "\nEnter the ID to modify: ", "\nError, enter the ID to modify: ");

					if (modificationJob(listJ, SIZE_J, listS, SIZE_S, returnValueId, returnValueOption) == TRUE)
					{
						system("cls");
						printf("! MODIFICATED SUCCESSFULLY !\n");
					}
					else
					{
						system("cls");
						printf("! The specified ID does not exist !\n");
					}
				}
				else
				{
					printf("\n! There are no jobs in the database  !\n");
				}
				break;

			case 3:
				system("cls");
				break;

			case 4:
				system("cls");
				printJobs(listJ, SIZE_J, listS, date, auxiliary);
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
