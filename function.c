#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>
#include "function.h"

#define MAX_SIZE_NAME 30 
#define MAX_SIZE_STRING 40 
#define SIZE_NUMBER_IN_FILE 3


MusComp *add_in_array(MusComp *ArrayMuCo,int *SizeArray, int *NumberInArray, MusComp ElementMuCo)
 {
	if (*NumberInArray + 1 == *SizeArray) 
	{
		(*SizeArray)  *= 2;
		MusComp	*OldPtrArrayMuCo = ArrayMuCo;
		ArrayMuCo = (MusComp *) realloc(OldPtrArrayMuCo,(*SizeArray)*sizeof(MusComp));
		if (ArrayMuCo == NULL) printf("Error associated with Realloc() in function add_in_array!");
	}
	ArrayMuCo[*NumberInArray] = ElementMuCo;
	return ArrayMuCo;
}

void output_info(MusComp *ArrayMuCo, int NumberInArray)
{
	int i = 0;
	while (i != NumberInArray) 
	{
		MusComp ElementMuCo;
		ElementMuCo = ArrayMuCo[i];
		printf("\n INDEX[%d]\n Bit: %d \n Duration: %d \n Name: %s\n",i, ElementMuCo.bit, ElementMuCo.duration, ElementMuCo.name);
		i++;
	}
}

void find_random_music_composition(MusComp *ArrayMuCo, int NumberInArray, int CountElement) 
{
	int randBit = rand()%5 + 150;
	int randDuration=rand()%20 + 240;
	int OutCount = 1;
	int index = 0;
	printf(" Search for a track with parameters such as:\n Rhythm-> %d +-1 bit/min \n Duration -> %d +-5 second \n",randBit,randDuration);
	while ((OutCount != CountElement+1) && (index < NumberInArray)) 
	{
		if ((abs(ArrayMuCo[index].bit - randBit) <= 1) && (abs(ArrayMuCo[index].duration - randDuration) <= 5)) 
		{
				MusComp ElementMuCo = ArrayMuCo[index];
				printf("\n INDEX[%d]\n Bit: %d \n Duration: %d \n Name: %s\n",OutCount, ElementMuCo.bit, ElementMuCo.duration, ElementMuCo.name);
				OutCount++;
		}
		index++;
	}
	if (OutCount != CountElement + 1) printf("There are no more music tracks with such parameters.");
}

MusComp create_struct_music_composition(char *strin, FILE *fin) 
{
	char sbit[SIZE_NUMBER_IN_FILE+1],sduration[SIZE_NUMBER_IN_FILE+1],sname[MAX_SIZE_NAME];
	MusComp ElementMuCo;
	strncpy(sbit, &strin[0],SIZE_NUMBER_IN_FILE);
	ElementMuCo.bit = atoi(sbit);
	strncpy(sduration, &strin[SIZE_NUMBER_IN_FILE+1],SIZE_NUMBER_IN_FILE);
	ElementMuCo.duration = atoi(sduration);
	strcpy(ElementMuCo.name, &strin[2*(SIZE_NUMBER_IN_FILE+1)]);
	return ElementMuCo;
}