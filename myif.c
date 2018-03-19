#include "myif.h"
#include "myTerm.h"
#include "myBC.h"
#include "mysc.h"

#include <stdio.h>
#include <stdlib.h>

int command;
int operand;
int value;

void displayMemory(){
	int i;
	int k = 2;

	bc_Box(1, 1, 12, 62);
	mt_gotoXY(1, 5);
	printf("MEMORY");

	mt_gotoXY(2, 2);

	for (i = 1; i <= 100; i++)//печать памяти 
	{
		sc_memoryGet(i - 1, &value);
		printf("+%04X ", value);

		if (i % 10 == 0 && i != 0) 
		{
			k++; mt_gotoXY(k, 2);
		}	
	}
	return 0;
}

void displayAccumulator()
{
	bc_Box(1, 63, 3, 18);
	mt_gotoXY(1, 65);
	printf("ACCUM");

	mt_gotoXY(2, 69);

	if (accumValue >= 0)
	{
		printf("+%04X", accumValue); 
		mt_gotoXY(2, 69);
	}
	else {
		printf("-%04X", (-1) * accumValue); 
		mt_gotoXY(2, 69);
	}

	mt_gotoXY(25, 1);
	return 0;
}
	
void displayCounter(){
	bc_Box(4, 63, 3, 18);
	mt_gotoXY(4, 65);
	printf("COUNTER");
	
	counter = memoryPointer;//счетчик = ячейка
	mt_gotoXY(5, 69);
	printf("+%04X", counter);
	mt_gotoXY(25, 1);
	
	return 0;
}

void displayOperation() 
{
	bc_Box(7, 63, 3, 18);
	mt_gotoXY(7, 65);
	printf("OPERATION");
	mt_gotoXY(8, 65);
	sc_memoryGet(memoryPointer, &value);
	mt_gotoXY(25, 1);

	return 0;
}