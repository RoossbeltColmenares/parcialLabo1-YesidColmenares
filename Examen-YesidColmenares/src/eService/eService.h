/*
 * eService.h
 *
 *  Created on: 13 may. 2021
 *      Author: Yesid
 */

#ifndef ESERVICE_ESERVICE_H_
#define ESERVICE_ESERVICE_H_
#define SIZE_S 4

typedef struct
{
	int idService;
	char description[25];
	int price;
} eService;

void hardCodeService(eService service[], int sizeS);

#endif /* ESERVICE_ESERVICE_H_ */
