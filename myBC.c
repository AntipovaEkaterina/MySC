#include "myTerm.h"
#include "mysc.h"
#include "stdio.h"
#include "stdlib.h"
#include "myBC.h"

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

int bc_PrintBigChar(int big[2], int x, int y, enum Color fgcolor, enum Color bgcolor){
	int Buf;
	int BitBuf;
	int BigBuf;
	char str[8] = {0};//куда преобразуем строку в цифры

	mt_setfgcolor(fgcolor);
	mt_setbgcolor(bgcolor);

	int i, j, k;
	for (i = 0; i < 2; i++)
	{
		BigBuf = big[i];

		for (int j = 0; j < 4; j++)//проход по строкам
		{
			BigBuf = big[i] >> (j * 8);
			Buf = BigBuf & 255;

			for (int k = 0; k < 8; k++)//получение битов из буфера 
			{
				BitBuf = (Buf & (1 << k)) >> k;
				if (BitBuf == 1)
				{
					str[k] = 'a';
				}else {
					str[k] = ' ';
				}
				mt_gotoXY(x + (i * 4) + j, y);
				bc_PrintA(str);
			}
		}
	}
	mt_gotoXY(25, 1);

	return 0;

}

int bc_SetBigCharPos(int *big, int x, int y, int value) 
{
	if (x < 0 || x > 7 || y < 0 || y > 7 || value > 1 || value < 0) 
		return -1;
	
	int index = 0;

	if (x > 3) 
		index = 1;

	if (value == 1) 
		big[index] |= 1 << (x * 8 + y);
	else if (value == 0) 
		big[index] &= ~(1 << (x * 8 + y));
	
	return 0;
}

int bc_GetBigCharpos(int * big, int x, int y, int *value)//для получения значения опр-го бита
{
	if (x < 0 || x > 7 || y < 0 || y > 7) 
		return -1;

	int index = 0;
	if (x > 3) 
		index = 1;

	*value = ((big[index] >> (x * 8)) >> y) & 1;

return 0;

}

int bc_BigCharWrite (int fd, int * big, int count)
{
	int result;
	while (count > 0) 
	{
		if ((result = write(fd, big, sizeof(int) * 2)) == -1) 
			return -1;
		count--;
	}

return 0;

}

int bc_BigCharRead (int fd, int * big, int need_count, int * count)
{
	while (need_count > 0) 
	{
		int result;
		if ((result = read(fd, big, sizeof(int) * 2)) == -1) 
			return -1;
		
		need_count--;
		*count = *count + 1;
	}

return 0;

}
	void bc_setBig(int *BIG, int value) {
	switch (value) {
        case '+':
            BIG[0] = 2115508224;
            BIG[1] = 6168;
            break;
        case '0':
            BIG[0] = -1313766913;
            BIG[1] = -8289919;
            break;
        case '1':
            BIG[0] = -1057427232;
            BIG[1] = -1061109568;
            break;
        case '2':
            BIG[0] = -8355586;
            BIG[1] = -16708351;
            break;
        case '3':
            BIG[0] = -25132808;
            BIG[1] = -25124736;
            break;
        case '4':
            BIG[0] = -8289920;
            BIG[1] = -2139049856;
            break;
        case '5':
            BIG[0] = -16711169;
            BIG[1] = -8343424;
            break;
        case '6':
            BIG[0] = -16711297;
            BIG[1] = -8277631;
            break;
        case '7':
            BIG[0] = -1061109505;
            BIG[1] = -1061109568;
            break;
        case '8':
            BIG[0] = -8289793;
            BIG[1] = -8281727;
            break;
        case '9':
            BIG[0] = -2120121857; 
            BIG[1] = -25132801;
            break;
        case 'A':
            BIG[0] = -8289793; 
            BIG[1] = -2122219135;
            break;
        case 'B':
            BIG[0] = -14606017; 
            BIG[1] = -8286847;
            break;
        case 'C':
            BIG[0] = 16843516;
            BIG[1] = -66977535;
            break;
        case 'D':
            BIG[0] = -1925111521; 
            BIG[1] = 522273153;
            break;
        case 'E':
            BIG[0] = 1057030655;
            BIG[1] = -16711423;
            break;
        case 'F':
            BIG[0] = 1057030655; 
            BIG[1] = 16843009;
            break;
        default:
            BIG[0] = 0;
            BIG[1] = 0;
            break;
	}
}


