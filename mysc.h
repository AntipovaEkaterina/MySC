#ifndef MYSC_H
#define MYSC_H

#define MEMSIZE 100 //размер памяти
#define COMSIZE 38 //кл-во команд 
#define F_VINX 1 //флаг выход за границы  
#define F_BADCOM 2 //плохая команда
#define ENCODE 127 

int mem[MEMSIZE]; 
int COMARR[COMSIZE]; 

int REG; //общий регистр
int sc_memoryInit();
int sc_memorySet(int , int);
int sc_memoryGet(int, int *);
int sc_memorySave(char *);
int sc_memoryLoad(char *);
int sc_regInit (void);
int sc_regSet (int, int);
int sc_regGet (int, int *);
int sc_commandEncode(int, int, int *);
int sc_commandDecode (int, int *, int *);

void print();//вывод памяти

#endif  
