#include <stdio.h>
#include <stdlib.h>
#include "mysc.h"


int sc_memoryInit()
{
	int i;
	int accumValue = 0;
	int memoryPointer = 0;
	

	for (i = 0; i < MEMSIZE; i++)
		mem[i] = 0;

	int arr[]= {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76};
	memcpy(COMARR, arr, (sizeof(arr)));
	return 0;
}

int sc_regInit(){
	REG = 0;
	return 0;
}

int sc_memorySet(int address, int value){
	 if(address < 0 || address > MEMSIZE){
	 	sc_regSet(F_VINX, 1);
	 	return -1;
	 }
	 mem[address] = value;
	 sc_regSet(F_VINX, 0);
	 return 0;
}

int sc_memoryGet(int address, int * value){
	if(address < 0 || address > MEMSIZE){
	 	sc_regSet(F_VINX, 1);
	 	return -1;
	 }
	*value = mem[address];
	sc_regSet(F_VINX,0);
	return 0;
}

int sc_memorySave(char *fname){
	FILE *f = fopen(fname,"wb"); //открываем файл на запись 
	fwrite(mem, MEMSIZE, sizeof(mem[0]), f); //записываем содержимое массива мем в размер 100 ячеек по нулевому элементу в файл ф
	fclose(f);
	return 0; 
}

int sc_memoryLoad(char *fname){
	FILE *f = fopen(fname, "rb");
	if (!f)
		return -1;
	fread(mem, MEMSIZE, sizeof(mem[0]),f);
	fclose(f);
	return 0;
}

int sc_regSet(int regflag, int value){
	if(value < 0 || value > 1 || regflag < 1 || regflag > 2) //лобавить больше флагов
		return -1;
	if(value == 0)
		REG &= (~(1 << (regflag - 1)));
	else 
		REG |= (1 << (regflag -1));
	return 0;
}

int sc_regGet(int regflag, int *value){
	if(regflag < 1 || regflag > 2) 
		return -1;

	*value = (REG >>(regflag - 1)) & 0x1; //получение значение опр флага
	return 0;
}

int sc_commandEncode(int command, int operand, int *value){
	int i;
	for(i = 0; i < COMSIZE; i++){
		if((command == COMARR[i]) && (operand >= 0 || operand <= 127)){
			*value = command << 8 | (operand & ENCODE);
			sc_regSet(F_BADCOM, 0);
			return 0;
		}
	}
	sc_regSet(F_BADCOM, 1);
	return -1;
}

int sc_commandDecode(int value, int *command, int *operand){
	if(value == NULL || command == NULL || operand == NULL){
		sc_regSet(F_BADCOM, 1);
		return -1;
	}
	*operand = value & ENCODE;
	*command = value >> 8;
	return 0;
}


void print(){
	int i, j = 1;
	for(i = 0; i < MEMSIZE; i++){
		printf("%04X  ", mem[i]);
		if(j % 10 == 0)
			printf("\n");
		j++;
	}


}