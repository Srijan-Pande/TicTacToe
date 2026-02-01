#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>

#include"TICTACTOE.h"

int main(int argc, char *argv[])
{
    two_player_game();
    return EXIT_SUCCESS;
}