/*
 * nexo.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "nexo.h"
#include "../eJob/eJob.h"
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
		returnValue = TRUE;
	}

	return returnValue;
}

void fillJob(eJob listJ[], eService listS[], int sizeS, eDate date[], int freePosition)
{
	listJ[freePosition].isEmpty = OCCUPIED;
	listJ[freePosition].idJob = freePosition;

	inputString(listJ[freePosition].bicycleBrand, "Enter bicycle Brand: ", "Error, enter bicycle Brand: ");
	inputInt(&listJ[freePosition].inchWheel, "Enter inch Wheel: ", "Error, enter inch Wheel: ");

	printServices(listS, sizeS);
	inputIntR(&listJ[freePosition].idService, "\n\nEnter Service: ", "Error, enter Service: ", listS[0].idService, listS[sizeS - 1].idService);

	inputIntR(&date[freePosition].day, "Enter day: ", "\nError, enter day:", 1, 31);
	inputIntR(&date[freePosition].month, "Enter month: ", "\nError, enter month:", 1, 12);
	inputInt(&date[freePosition].year, "Enter year: ", "\nError, enter year:");
}

int activeProductsPosition(eJob listJ[], int sizeJ, eAuxiliary auxiliary[], int *sizeA)
{
	int returnValue;
	int i;
	int j;

	returnValue = FALSE;

	j = 0;
	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].isEmpty == OCCUPIED)
		{
			auxiliary[j].id = i;
			j++;
			returnValue = TRUE;
		}
	}
	*sizeA = j;
	return returnValue;
}

int modificationJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, int id, int option)
{
	int returnValue;
	int position;

	returnValue = FALSE;

	if (compareIdJob(listJ, sizeJ, &position, id) == TRUE)
	{
		switch (option)
		{
			case 1:
				inputString(listJ[position].bicycleBrand, "Enter bicycle Brand: ", "Error, enter bicycle Brand: ");
				break;
			case 2:
				printServices(listS, sizeS);
				inputIntR(&listJ[position].idService, "\n\nEnter Service: ", "Error, enter Service: ", listS[0].idService, listS[sizeS - 1].idService);
				break;
		}
		returnValue = TRUE;
	}
	return returnValue;
}

void totalMoneyServices(eJob listJ[], int sizeJ, eService listS[], int *totalMoney)
{
	int i;
	int sizeA;
	eAuxiliary auxiliary[SIZE_J];

	activeProductsPosition(listJ, sizeJ, auxiliary, &sizeA);

	for (i = 0; i < sizeA; i++)
	{
		*totalMoney += listS[listJ[auxiliary[i].id].idService-20000].price;
	}
}

