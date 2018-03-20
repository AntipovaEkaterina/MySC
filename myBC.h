#ifndef MYBC_H
#define MYBC_H

#define ENTER_MODE "\E(0"
#define EXIT_MODE "\E(B"

int BIG[2];

int bc_PrintA (char * str);
int bc_Box(int x1, int y1, int x2, int y2);
int bc_PrintBigChar (int big[2], int x, int y, enum Color fgcolor, enum Color bgcolor);
int bc_SetBigCharpos (int * big, int x, int y, int value);
int bc_GetBigCharpos(int * big, int x, int y, int *value);
int bc_BigCharWrite (int fd, int * big, int count);
int bc_BigCharRead (int fd, int * big, int need_count, int * count);
/*void bc_setBig(int*, int);//установка значения массива в уже готовые наборы
*/
#endif	