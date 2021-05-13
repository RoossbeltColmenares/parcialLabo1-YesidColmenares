/*
 * eJob.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "eJob.h"
#define FALSE 0
#define TRUE 1

void initialitationJob(eJob listJ[], int sizeJ)
{
	int i;
	for (i = 0; i < sizeJ; i++)
	{
		listJ[i].idJob = VOID;
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