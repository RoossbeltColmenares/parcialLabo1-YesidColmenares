/*
 * print.c
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "print.h"
#include <stdio.h>

void printJobs(eJob listJ[], int sizeJ, eService listS[], eDate date[], eAuxiliary auxiliary[])
{
	int i;
	int sizeJobOccupied;

	activeProductsPosition(listJ, sizeJ, auxiliary, &sizeJobOccupied);

	printf(" ID       BICYCLEBRAND     INCHWHEEL       SERVICE              DATE");
	for (i = 0; i < sizeJobOccupied; i++)
	{
		printf("\n%3d %18s %13d %13s %10d/%d/%d", listJ[auxiliary[i].id].idJob, listJ[auxiliary[i].id].bicycleBrand, listJ[auxiliary[i].id].inchWheel, listS[listJ[auxiliary[i].id].idService - 20000].description, date[auxiliary[i].id].day,
				date[auxiliary[i].id].month, date[auxiliary[i].id].year);
	}
}

void printServices(eService listS[], int sizeS)
{
	int i;
	printf("\nID            SERVICE      PRICE");
	for (i = 0; i < sizeS; i++)
	{
		printf("\n%5d %15s %10d", listS[i].idService, listS[i].description, listS[i].price);
	}
}

void printTotalServices(int totalMoney)
{
	printf("Total money for services rendered: %d", totalMoney);
}
