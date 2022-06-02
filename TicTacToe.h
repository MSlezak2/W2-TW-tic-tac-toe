#pragma once
#include <time.h>


// Stan gry:
char board[3][3]; // 'X' / 'O' / '_'

int x, y; // coordinates chosen by user
int computer_x, computer_y; // coordinates chosen by computer
int difficulty; 
int game_mode;
char name_1[50]; 
char name_2[50];
char token_1; // znacznik pierwszego gracza
char token_2;  
int num_moves;
clock_t start, stop; // stats
float game_duration; // stats



void make_null_tab(char a[3][3]);
void Print_Bord_on_Screen(char poziom[3][3]);
void put_coordinates(int a, int b, char cos[3][3], char token);
void give_coordinates();
void coordinatesCheck(int* coordinate);
void is_occupied(char board[3][3]);
void choose_name(int game_mode);
void choose_token();
void stats();
void play_again();
void choose_difficulty(int* difficulty);
void computers_move(char board[3][3], char my_token, char rivals_token, int* computer_x, int* computer_y);
void dummy_move(char board[3][3], char my_token, int* computer_x, int* computer_y);
void mastermind_move(char board[3][3], char my_token, char rivals_token, int* computer_x, int* computer_y);
float assess_move(char board[3][3], int x, int y, char my_token, char rivals_token);
float quality_for_that_line(int no_empty_tiles_in_line, int no_my_tokens_in_line, int no_rivals_tokens_in_line);
int can_player_win(char board[3][3], char rivals_token, int* winning_choice_x, int* winning_choice_y);
void choose_game_mode(int* game_mode);
int checkforwin(int board[3][3]);
int is_board_full(char board[3][3]);
int has_token_won(char token, char board[3][3]);
