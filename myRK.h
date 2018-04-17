#ifndef MYRK_H
#define MYRK_H

enum Keys {UP, DOWN, LEFT, RIGHT, F5, F6, ESC, ENTER, LOAD, SAVE, RUN, STEP, RESET, QUIT, EDIT, NONE};

void termInit();//инициализация терминала
void defaultTermSettings(struct termios *);//возвращает терминал к тому состоянию что было в начале работы
int rk_readKey(enum Keys *key);
int rk_myTermSave(struct termios *);//сохраняет текущие параметры терминала;
int rk_myTermRestore(struct termios *);//восстанавливает сохранѐнные параметры терминала.
int rk_myTermRegime(struct termios const*, int, int, int, int, int);//Устанавливает конкретные режимы работы
#endif