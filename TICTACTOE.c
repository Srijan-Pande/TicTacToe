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

typedef struct 
{
    char name[27];
    char symbol;
} 
Player;

char *create_board_internal(void);
void destroy_board_internal(char **board);
void print_board_internal(char *board);
char win_check_internal(char *board,char symbol);
bool make_move_internal(char *board, unsigned int tile, char symbol);
unsigned int ask_tile_internal(void);
void move_maker_internal(char *board, char symbol);
Player *player_initializer_internal(void);
void two_player_game_internal();

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
#define destroy_board(board) destroy_board_internal(&(board))

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

bool make_move_internal(char *board, unsigned int tile, char symbol)
{
    if(board==nullptr)return false;
    if( (tile>8) || board[tile]=='X' || board[tile]=='O' )
    {
        puts("Illegal Move. Try Again");
        return false;
    }
    board[tile]=symbol;
    return true;
}
#define make_move(board,tile,symbol) make_move_internal(board,tile,symbol)

unsigned int ask_tile_internal(void)
{
    puts("Enter Your Move:");
    char holder = fgetc(stdin);
    unsigned int tile;

    if(holder!='\n' && holder!=EOF)
    {
        char waste;
        while((waste=getchar())!='\n' && waste!=EOF);
    }

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

void move_maker_internal(char *board, char symbol)
{
    while(make_move(board,ask_tile(),symbol)==false);
    return;
}
#define move_maker(board,symbol) move_maker_internal(board,symbol)

Player *player_initializer_internal(void)
{
    Player *new_player = malloc(sizeof(Player));
    if(new_player==nullptr)return nullptr;
    fgets(new_player->name,sizeof(new_player->name),stdin);
    new_player->name[strcspn(new_player->name,"\n")] = '\0';
    return new_player;
}
#define player_initializer() player_initializer_internal()

void two_player_game_internal()
{
    puts("Enter Player 1 Name:");
    Player* player1 = player_initializer();
    player1->symbol = 'X';

    puts("Enter Player 2 Name:");
    Player* player2 = player_initializer();
    player2->symbol = 'O';

    char *myboard =  create_board();
    print_board(myboard);

    for(unsigned int i = 0; i<9; i++)
    {
        Player *turn = i%2==0 ? player1 : player2;
        printf("%s to play\n" , turn->name);
        move_maker(myboard,turn->symbol);
        print_board(myboard);
        if(win_check(myboard,turn->symbol)==turn->symbol)
        {
            printf("%s Wins",turn->name);
            destroy_board(myboard);
            return;
        }
    }
    puts("Drawn Game");
    destroy_board(myboard);
    return;
}
#define two_player_game() two_player_game_internal()