#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>

/*
    L C R
T   0 1 2
M   3 4 5
B   6 7 8 

Columns
L - Left
C - Center
R - Right

Rows
T - Top
M - Middle
B - Bottom

New - N
Exit - E
*/

char *create_board_internal(void)
{
    char *board = malloc(9*sizeof(char));
    if(board==nullptr)return nullptr;
    memset(board,' ',9);
    return board;
}
#define create_board(void) create_board_internal(void)

void destroy_board_internal(char **board)
{
    if(!board||!*board)return;
    free(*board);
    *board=nullptr;
    return;
}
#define destroy_board(board) destroy_board_internal((char **)(&board))

char win_check(char *board)
{
    if(!board)return '\0';

    if
    (
        board[0]=='X'&&board[1]=='X'&&board[2]=='X'
        ||
        board[3]=='X'&&board[4]=='X'&&board[5]=='X'
        ||
        board[6]=='X'&&board[7]=='X'&&board[8]=='X'
        ||
        board[0]=='X'&&board[3]=='X'&&board[6]=='X'
        ||
        board[1]=='X'&&board[4]=='X'&&board[7]=='X'
        ||
        board[2]=='X'&&board[5]=='X'&&board[8]=='X'
        ||
        board[0]=='X'&&board[4]=='X'&&board[8]=='X'
        ||
        board[2]=='X'&&board[4]=='X'&&board[6]=='X'
    )
    {
        return 'X';
    }

    if
    (
        board[0]=='O'&&board[1]=='O'&&board[2]=='O'
        ||
        board[3]=='O'&&board[4]=='O'&&board[5]=='O'
        ||
        board[6]=='O'&&board[7]=='O'&&board[8]=='O'
        ||
        board[0]=='O'&&board[3]=='O'&&board[6]=='O'
        ||
        board[1]=='O'&&board[4]=='O'&&board[7]=='O'
        ||
        board[2]=='O'&&board[5]=='O'&&board[8]=='O'
        ||
        board[0]=='O'&&board[4]=='O'&&board[8]=='O'
        ||
        board[2]=='O'&&board[4]=='O'&&board[6]=='O'
    )
    {
        return 'O';
    }

    return ' ';
}

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}