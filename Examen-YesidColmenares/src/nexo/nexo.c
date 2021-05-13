/*
 * nexo.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "nexo.h"
#define OCCUPIED 1
#define FALSE 0
#define TRUE 1

int addJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eDate date[], int sizeD)
{
	int returnValue;
	int freePosition;

	returnValue = FALSE;
	if (searchIsEmptyJob(listJ, sizeJ, &freePosition) == TRUE)
	{
		fillJob(listJ, listS, sizeS, date, freePosition);
	}

	return returnValue;
}

void fillJob(eJob listJ[], eService listS[], int sizeS, eDate date[], int freePosition)
{
	listJ[freePosition].isEmpty = OCCUPIED;
	listJ[freePosition].idJob = freePosition;

	inputString(listJ[freePosition].bicycleBrand, "Enter bicycle Brand: ", "Error, enter bicycle Brand: ");
	inputInt(&listJ[freePosition].inchWheel, "\nEnter inch Wheel: ", "Error, enter inch Wheel: ");

	printServices(listS, sizeS);
	inputIntR(&listJ[freePosition].idService, "\n\nEnter Service: ", "Error, enter Service: ", listS[0].idService, listS[sizeS - 1].idService);

	inputIntR(&date[freePosition].day, "\nEnter day: ", "\nError, enter day:",1,31);
	inputIntR(&date[freePosition].month, "\nEnter month: ", "\nError, enter month:",1,12);
	inputInt(&date[freePosition].year, "\nEnter year: ", "\nError, enter year:");
}
