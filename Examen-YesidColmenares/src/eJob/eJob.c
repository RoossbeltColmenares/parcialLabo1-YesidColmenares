/*
 * eJob.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "eJob.h"
#include "../eAuxiliary/eAuxiliary.h"
#include "../nexo/nexo.h"
#define FALSE 0
#define TRUE 1
#define OCCUPIED 1

void initialitationJob(eJob listJ[], int sizeJ)
{
	int i;
	for (i = 0; i < sizeJ; i++)
	{
		listJ[i].isEmpty = VOID;
	}
}

int searchIsEmptyJob(eJob listJ[], int sizeJ, int *position)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].isEmpty == VOID)
		{
			*position = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int thereAreJobs(eJob listJ[], int sizeJ)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].isEmpty == OCCUPIED)
		{
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int compareIdJob(eJob listJ[], int sizeJ, int *position, int id)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeJ; i++)
	{
		if (listJ[i].idJob == id)
		{
			*position = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int removeJob(eJob listJ[], int sizeJ, int id)
{
	int returnValue;
	int position;

	returnValue = FALSE;
	if (compareIdJob(listJ, sizeJ, &position, id) == TRUE)
	{
		listJ[position].isEmpty = VOID;
		listJ[position].idJob = VOID;
		returnValue = TRUE;
	}
	return returnValue;
}

int ageLowToHighJob(eJob listJ[], int sizeJ, eDate date[], int sizeD)
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eAuxiliary auxiliary[sizeJ];
	eJob cpy;

	activeProductsPosition(listJ, sizeJ, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA - 1; i++)
	{
		for (j = i + 1; j < sizeA; j++)
		{
			if (date[auxiliary[i].id].year < date[auxiliary[j].id].year)
			{
				cpy = listJ[auxiliary[j].id];
				listJ[auxiliary[j].id] = listJ[auxiliary[i].id];
				listJ[auxiliary[i].id] = cpy;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

int originalOrderJob(eJob listJ[], int sizeJ)
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eAuxiliary auxiliary[sizeJ];
	eJob cpy;

	activeProductsPosition(listJ, sizeJ, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA - 1; i++)
	{
		for (j = i + 1; j < sizeA; j++)
		{
			if (listJ[auxiliary[i].id].idJob < listJ[auxiliary[j].id].idJob)
			{
				cpy = listJ[auxiliary[j].id];
				listJ[auxiliary[j].id] = listJ[auxiliary[i].id];
				listJ[auxiliary[i].id] = cpy;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

