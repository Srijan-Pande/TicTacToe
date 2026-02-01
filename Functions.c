#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>

char *create_board_internal(void)
{
    char *board = malloc(9*sizeof(char));
    if(board==nullptr)return nullptr;
    memset(board,' ',9);
    return board;
}

void destroy_board_internal(char **board)
{
    if(!board||!*board)return;
    free(*board);
    *board=nullptr;
    return;
}

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}