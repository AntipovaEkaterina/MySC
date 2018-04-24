#include "myif.h"
#include "myTerm.h"
#include "myBC.h"
#include "mysc.h"

#include <stdio.h>
#include <stdlib.h>

int command;
int operand;
int value;

void showAll() {
mt_clrscr();
displayMemory();
displayAccumulator();
displayCounter();
displayOperation();
displayFlags();
displayMenu();
displayBigCharArea();
bc_Box(26, 1, 26, 2);
}

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
		if (memoryPointer == i - 1) 
			mt_setbgcolor(RED);
		printf("+%04X ", value);
		mt_setbgcolor(DEFAULT);

		if (i % 10 == 0 && i != 0) 
		{
			k++; 
			mt_gotoXY(k, 2);
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

void displayFlags()
{
	bc_Box(10, 63, 3, 18);
	mt_gotoXY(10, 65);
	printf("FLAGS");
	int flagVal;
	mt_gotoXY(25, 1);

	return 0;
}

void displayMenu()
{
	bc_Box(13, 47, 10, 34);
	mt_gotoXY(13, 49);
	printf("MENU");
	mt_gotoXY(15, 49);
	printf("L - LOAD");
	mt_gotoXY(16, 49);
	printf("S - SAVE");
	mt_gotoXY(17, 49);
	printf("R - RUN");
	mt_gotoXY(18, 49);
	printf("T - STEP");
	mt_gotoXY(19, 49);
	printf("I - RESET");//сброс
	mt_gotoXY(20, 49);
	printf("F5 - ACCUMULATOR");
	mt_gotoXY(21, 49);
	printf("F6 - COUNTER");
	mt_gotoXY(25, 1);
	
	return 0;
}

void displayBigCharArea() 
{
	mt_gotoXY(13, 1);
	char buffer[20];//записываем строку

	int y = 2;
	bc_Box(13, 1, 10, 46);
	mt_gotoXY(13, 5);
	printf("BIG CHAR");
	//массив чисел
	BIG[0] = 0;
	BIG[1] = 0;
	sc_memoryGet(memoryPointer, &value);
	sprintf(buffer, "+%04X", value);
	int i;
	for (i = 0; i < 5; ++i, y += 9)// 
	{
		bc_setBig(BIG, buffer[i]);
		bc_PrintBigChar(BIG, 14, y, DEFAULT, DEFAULT);
	}
	mt_gotoXY(25, 1);

	return 0;
}

void displayBox(char *title, int type) 
{
    mt_gotoXY(25, 1);

    printf("%s: ", title);
    if (type == 1) 
    {
    	scanf("%d", &accumValue);
    }

    else if (type == 2) 
    {
    	scanf("%d", &counter);
    	if(counter >= 0 && counter < MEMSIZE) 
    		memoryPointer = counter;
    	else
    	sc_regSet(F_VINX, 1);
    }

    else if (type == 3) 
    {
    	int com = 0, oper = 0, value;
    	sc_memoryGet(memoryPointer, &value);
    	sc_commandDecode(value, &com, &oper);
    	mt_gotoXY(25, 1);
    	printf("ENCODE(COM, OPER): ");
    	scanf("%d %d", &com, &oper);
    	sc_commandEncode(com, oper, &value);
    	sc_memorySet(memoryPointer, value);
    }
}
   


