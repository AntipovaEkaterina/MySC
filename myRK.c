#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include "myTerm.h"
#include "myRK.h"

struct termios const __term_state;
struct termios termState;

void termInit()//сохраняем по адресу константы
{
    rk_myTermSave(&__term_state);
}

void defaultTermSettings(struct termios *termState)//загрузка стандартных настроек
{
    *termState = __term_state;
}

int rk_readKey(enum Keys *key) {
	int term = open(TERM, O_RDWR);
	char buf;

	struct termios termState = __term_state;
    rk_myTermRegime(&termState, 0, 0, 1, 0, 1);
    read (term, &buf, 1);

    switch (buf) {
    case 'q':
        *key = QUIT;
        break;
    case 'l':
        *key = LOAD;
        break;
    case 's':
        *key = SAVE;
        break;
    case 'r':
        *key = RUN;
        break;
    case 't':
        *key = STEP;
        break;
    case 'i':
        *key = RESET;
        break;
    case 'e':
		*key = EDIT;
		break;
    case '\E':        
        read (term, &buf, 1);
        read (term, &buf, 1);
        switch (buf) {
        case 65:
            *key = UP;
            break;
        case 66:
            *key = DOWN;
            break;
        case 67:
            *key = RIGHT;
            break;
        case 68:
            *key = LEFT;
            break;
        case '1':
            read (term, &buf, 1);
            if (buf == '5') {
                read (term, &buf, 1);
                if (buf == '~') 
                	*key = F5;
            }
            if (buf == '7') {
                read (term, &buf, 1);
                if (buf == '~') 
                	*key = F6;
            }
            break;
        default:
            *key = NONE;
        }
        break;
    default:
        *key = NONE;
        break;
    }
    rk_myTermRegime(&termState, 1, 1, 1, 1, 1);
    close (term);

	return 0;
}

int rk_myTermRegime(struct termios const *currState, int regime, int vtime, int vmin, int echo, int sigint) {
	if (regime < 0 || regime > 1 || echo < 0 || echo > 1 || sigint < 0 || sigint > 1) return -1;

	struct termios newTermState = *currState;

    if (regime == 1)
        newTermState.c_lflag |= ICANON;
    else
        newTermState.c_lflag &= ~ICANON;

    if (echo == 1)
        newTermState.c_lflag |= ECHO;
    else
        newTermState.c_lflag &= ~ECHO;

    if (sigint == 1)
        newTermState.c_lflag |= ISIG;
    else
        newTermState.c_lflag &= ~ISIG;

    newTermState.c_cc [VMIN]  = vmin;
    newTermState.c_cc [VTIME] = vtime;
	tcsetattr(0, TCSANOW, &newTermState);

	return 0;
}

int rk_myTermSave(struct termios *termState)
{
    return tcgetattr(1, termState);
}

int rk_myTermRestore(struct termios *currState)
{
    return tcsetattr(1, TCSADRAIN, &termState);
}