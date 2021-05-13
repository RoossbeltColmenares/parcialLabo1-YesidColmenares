/*
 * nexo.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef NEXO_NEXO_H_
#define NEXO_NEXO_H_
#include "../dataEntry/input.h"
#include "../print/print.h"
#define TRUE 1
#define FALSE 0
#include <stdio.h>

int addJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eDate date[], int sizeD);

void fillJob(eJob listJ[], eService listS[], int sizeS, eDate date[], int freePosition);

int activeProductsPosition(eJob listJ[], int sizeJ, eAuxiliary auxiliary[], int *sizeA);

int modificationJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, int id, int option);

void totalMoneyServices(eJob listJ[], int sizeJ, eService listS[], int *totalMoney);

#endif /* NEXO_NEXO_H_ */
