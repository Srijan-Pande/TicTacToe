#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>
#include<limits.h>

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
    for(unsigned int i = 0; i<9; i++)
    {
        board[i]='0'+i;
    }
    return board;
}
#define create_board() create_board_internal()

void destroy_board_internal(char **board)
{
    if(!board||!*board)return;
    free(*board);
    *board=nullptr;
    return;
}
#define destroy_board(board) destroy_board_internal((char **)(&board))

void print_board_internal(char *board)
{
    if(board==nullptr)return;
    for(unsigned int i = 0; i<9; i++)
    {
        printf("%c ",board[i]);
        if(i%3==2)
        {
            puts("");
        }
    }
    return;
}
#define print_board(board) print_board_internal(board)

char win_check_internal(char *board,char symbol)
{
    if(!board)return '\0';

    if
    (
        board[0]==symbol&&board[1]==symbol&&board[2]==symbol
        ||
        board[3]==symbol&&board[4]==symbol&&board[5]==symbol
        ||
        board[6]==symbol&&board[7]==symbol&&board[8]==symbol
        ||
        board[0]==symbol&&board[3]==symbol&&board[6]==symbol
        ||
        board[1]==symbol&&board[4]==symbol&&board[7]==symbol
        ||
        board[2]==symbol&&board[5]==symbol&&board[8]==symbol
        ||
        board[0]==symbol&&board[4]==symbol&&board[8]==symbol
        ||
        board[2]==symbol&&board[4]==symbol&&board[6]==symbol
    )
    {
        return symbol;
    }

    return ' ';
}
#define win_check(board,symbol) win_check_internal(board,symbol)

void make_move_internal(char *board, unsigned int tile, char symbol)
{
    if(board==nullptr)return;
    board[0+tile]=symbol;
    return;
}
#define make_move(board,tile,symbol) make_move_internal(board,tile,symbol)

unsigned int ask_move_internal(void)
{
    puts("Enter Your Move:");
    char holder = getchar();
    unsigned int tile;

    while(getchar()!='\n');

    if(holder>='0'&&holder<='8')
    {
        tile = holder - '0';
        return tile;
    }
    else 
    {
        return UINT_MAX;
    }
}
#define ask_move() ask_move_internal()

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}