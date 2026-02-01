#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>
#include<limits.h>
#include<stdint.h>

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
    if(board==nullptr || *board==nullptr)return;
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

typedef enum
{
    NULLBOARD = 0,
    VALIDBOARD = 1
} 
MoveStatus;

MoveStatus make_move_internal(char *board, unsigned int tile, char symbol)
{
    if(board==nullptr)return NULLBOARD;
    if((tile<0||tile>8)||(board[tile]=='X'||board[tile]=='O'))
    {
        puts("Illegal Move");

    }
    board[tile]=symbol;
    return VALIDBOARD;
}
#define make_move(board,tile,symbol) make_move_internal(board,tile,symbol)

unsigned int ask_tile_internal(void)
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
#define ask_tile() ask_tile_internal()

typedef struct
{
    char symbol;
    char name[27];
} 
Player;

void two_player_game_internal()
{
    Player player1;
    puts("Enter the name of player 1");
    scanf("%26s",player1.name);
    player1.symbol = 'X';

    Player player2;
    puts("Enter the name of player 2");
    scanf("%26s",player2.name);
    player2.symbol = 'O';

    char *myboard =  create_board();
    print_board(myboard);

    for(unsigned int i = 0; i<9; i++)
    {
        Player *turn = i%2==0 ? &player1 : &player2;
        printf("%s to play\n" , turn->name);
        MoveStatus status_of_play = (myboard,ask_tile(),turn->symbol);
        if(status_of_play!=VALIDBOARD)
        {
            puts("Invalid Move");
            break;
        }
        else 
        {

        }
    }
    destroy_board(myboard);
}

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}