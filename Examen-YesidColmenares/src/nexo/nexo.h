/*
 * nexo.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef NEXO_NEXO_H_
#define NEXO_NEXO_H_
#include "../eDate/eDate.h"
#include "../eJob/eJob.h"
#include "../eService/eService.h"
#include "../dataEntry/input.h"
#include <stdio.h>

int addJob(eJob listJ[], int sizeJ, eService listS[], int sizeS, eDate date[], int sizeD);

void fillJob(eJob listJ[], eService listS[], int sizeS, eDate date[], int freePosition);

#endif /* NEXO_NEXO_H_ */
