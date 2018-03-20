#ifndef MYTERN_H
#define MYTERN_H

#include <sys/ioctl.h> 

#define CLR_SCR "\E[H\E[J" 
#define GOTO "\E[%d;%dH" //переход к ккой-либ точке:строка;столбец
#define BG_COLOR "\E[4%dm" //цвет фона
#define FG_COLOR "\E[3%dm"//цвет текста

enum Color {DEFAULT = 9, BLACK = 0, WHITE = 7, GREEN = 2, RED = 1};

//прототипы

int mt_clrscr ();
int mt_gotoXY (int, int);
int mt_getscreensize (int *, int *);
int mt_setfgcolor (enum Color);
int mt_setbgcolor (enum Color);

#endif