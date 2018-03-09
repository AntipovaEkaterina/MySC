#include "myTerm.h"

int mt_clrscr (){
	printf(CLR_SCR);
}

int mt_gotoXY (int X, int Y){
	printf(GOTO, X,Y);
}

int mt_getscreensize (int *x, int *y){
	struct winsize ws;

	if (!ioctl(1, TIOCGWINSZ, &ws)){
		*x = ws.ws_row;//число строк
		*y = ws.ws_col;//число столбцов
		return 0;
	} else {
		return (-1);
	}	
}

int mt_setfgcolor(enum Color color){
	printf(FG_COLOR, color);
}

int mt_setbgcolor(enum Color color){
	printf(BG_COLOR, color);
}


