#include "myBC.h"
#include "myTerm.h"
#include "mysc.h"
#include "stdio.h"
#include "stdlib.h"

int bc_PrintA (char * str){
	printf(ENTER_MODE);
	printf(str);
	printf(EXIT_MODE);

	return 0;
}

int bc_Box(int x1/*левый верхний угол в строке*/, int y1/*в столбце*/, int x2/*ширина и высота строк*/, int y2/*столбцов*/){
	int i;
	mt_gotoXY(x1, y1);
	bc_PrintA("l");

	for(i = 0; i < y2 - 2; i++)//слева на право линия
		bc_PrintA("q");
		bc_PrintA("k");

	for(i = 1; i <= x2 - 2; i++){//вертикальные линии
		mt_gotoXY(x1 + i, y1);
		bc_PrintA("x");
		mt_gotoXY(x1 + i, y1 + y2 - 1);
		bc_PrintA("x");
	}

	mt_gotoXY(x1 + x2 - 1, y1);
	bc_PrintA("m");
	for (int i = 0; i < y2 - 2; i++)//спава на лево линия 
	
		bc_PrintA("q");
		bc_PrintA("j");
	

	return 0;
}
/*
int bc_PrintBigChar (int [2], int x, int y, enum color, enum color){


}

int bc_SetBigCharpos (int * big, int x, int y, int value){


}

int bc_GetBigCharpos(int * big, int x, int y, int *value){

}

int bc_BigCharWrite (int fd, int * big, int count){


}

int bc_BigCharRead (int fd, int * big, int need_count, int * count){


}

void bc_setBig(int*, int){


}*/