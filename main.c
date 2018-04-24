#include <stdio.h>
#include <stdlib.h>
#include "mysc.h"
#include "myTerm.h"
#include "myBC.h"
#include "myif.h"
#include "myRK.h"

#define CLR_SCR "\E[H\E[J" //очистка всей консоли

int main()
{
	enum Keys key = NONE;

	sc_memoryInit();
	sc_regInit();
	termInit();

	while(key != QUIT)
	{
		showAll();
		rk_readKey(&key);

		if (key == RIGHT) 
			if (memoryPointer < 99) 
				++memoryPointer;
		if (key == LEFT) 
			if (memoryPointer > 0) 
				--memoryPointer;
		if (key == UP) 
			if (memoryPointer - 10 >= 0) 
				memoryPointer -= 10;
		if (key == DOWN) 
			if (memoryPointer + 10 < 100) 
				memoryPointer += 10;
		if (key == F5) 
			displayBox("ACCUM", 1);
		if (key == F6) 
			displayBox("COUNTER", 2);
		if (key == EDIT) 
			displayBox("EDIT CELL", 3);
		if (key == LOAD) {
			displayBox("FILE NAME", 4);
		}
		if (key == SAVE) 
			sc_memorySave("mem.dat");
		if (key == RESET) {
			sc_memoryInit();
			sc_regInit();
		}
		

	}
	
}
