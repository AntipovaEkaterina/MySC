#include <stdio.h>
#include <stdlib.h>
#include "mysc.h"
#include "myTerm.h"
#include "myBC.h"

#define CLR_SCR "\E[H\E[J" //очистка всей консоли

int main()
{
	//printf("hello\n");
	mt_clrscr();
	//bc_Box(1, 1, 12, 62);
	//	printf("\n");

	int sx;
	int sy;
	mt_getscreensize(&sx, &sy);
	printf("Screen size: %d %d\n", sx, sy);

	//mt_setbgcolor(BLACK);
	//mt_setfgcolor(GREEN);
	
	mt_setbgcolor(BLACK);
	mt_setfgcolor(RED);
	int a, ch, address = 0, value = 0, comIn = 0, opIn = 0, resEn = 0, resDec = 0;
	int memF = 0, comF = 0;

	sc_memoryInit();
	sc_regInit();
	while(1){
		
		printf(CLR_SCR);
		bc_Box(1, 1, 3, 10);
			
		mt_gotoXY(2, 2);
		printf("create: Katya Antipova\n");

		print();

		sc_regGet(F_VINX, &memF);
		sc_regGet(F_BADCOM, &comF);
		mt_setbgcolor(BLACK);
		mt_setfgcolor(WHITE);

		printf("FLAGS: out of memory: %d, bad command: %d\n", memF, comF );
		printf("\n1)Encode\n2)Decode\n3)Save\n4)Download\n5)Exit\n");
		scanf("%d", &ch);

		switch(ch) {

			case 1:
			{
				printf(CLR_SCR);
				mt_setbgcolor(BLACK);
				mt_setfgcolor(RED);
				print();


				mt_setbgcolor(BLACK);
				mt_setfgcolor(WHITE);

				printf("FLAGS: out of memory: %d, bad command: %d\n", memF, comF );
				printf("Input command and operand: \n");
				scanf("%d %d", &comIn, &opIn);

				if(sc_commandEncode(comIn, opIn, &resEn) == 0){
					printf("\nCODED: %X", resEn);
					printf("\nINPUT ADDRESS: ");
					scanf("%d", &address);
					sc_memorySet(address, resEn);
				}
			}
			break;

			case 2:
			{
				printf(CLR_SCR);
				
				print();

				printf("FLAGS: out of memory: %d, bad command: %d\n", memF, comF );
				printf("Input address: \n");
				scanf("%d", &address);

				if(sc_memoryGet(address, &resDec) == 0){
					printf("\nDECODED: %X", resDec);
					sc_commandDecode( resDec, &comIn, &opIn);
					printf("\nDECODED COMMAND: %d, DECODED OPERAND: %d", comIn, opIn);
				}
					scanf("%d", &a);		
			}
			break;

			case 3:
			{
				sc_memorySave("mem.dat");
			}
			break;

			case 4:
			{
				sc_memoryLoad("mem.dat");
			}
			break;

			case 5:
			{
				return 0;
			}

		}
	}
	return 0;
}
