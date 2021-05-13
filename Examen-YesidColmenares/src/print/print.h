/*
 * print.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#include "../eAuxiliary/eAuxiliary.h"
#include "../eDate/eDate.h"
#include "../eJob/eJob.h"
#include "../eService/eService.h"
#include "../nexo/nexo.h"

#ifndef PRINT_PRINT_H_
#define PRINT_PRINT_H_

void printJobs(eJob listJ[], int sizeJ, eService listS[], eDate listD[], eAuxiliary auxiliary[]);

void printServices(eService listS[], int sizeS);

void printTotalServices(int totalMoney);

#endif /* PRINT_PRINT_H_ */
