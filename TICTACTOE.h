#ifndef TICTACTOE_H
#define TICTACTOE_H

#define __USE_MINGW_ANSI_STDIO 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<errno.h>
#include<limits.h>
#include<stdint.h>

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

#define create_board() create_board_internal()
#define destroy_board(board) destroy_board_internal(&(board))
#define print_board(board) print_board_internal(board)
#define win_check(board,symbol) win_check_internal(board,symbol)
#define make_move(board,tile,symbol) make_move_internal(board,tile,symbol)
#define ask_tile() ask_tile_internal()
#define move_maker(board,symbol) move_maker_internal(board,symbol)
#define player_initializer() player_initializer_internal()
#define two_player_game() two_player_game_internal()

#endif