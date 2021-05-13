/*
 * eJob.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef EJOB_EJOB_H_
#define EJOB_EJOB_H_
#define SIZE_J 5
#define VOID -1
#include "../eDate/eDate.h"

typedef struct
{
    int isEmpty;
	int idJob;
	char bicycleBrand[50];
	int inchWheel;
	int idService;
	eDate fecha;
} eJob;

void initialitationJob(eJob listJ[], int sizeJ);

int searchIsEmptyJob(eJob listJ[], int sizeJ, int *position);
#endif /* EJOB_EJOB_H_ */