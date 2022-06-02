#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h> 
#include "TicTacToe.h"

int main()
{

	int which_player_won = 0;

	do
	{
		srand(time(NULL)); // set seed for pseudo-random number generator, do it before each game
		
		welcome_screen();

		clear_screen();

		choose_game_mode(&game_mode);

		if (game_mode != 1) // when there's player vs player situation, there's no need to choose difficulty
		{
			choose_difficulty(&difficulty);
		}

		choose_name(game_mode);
		choose_token();

		clear_screen();
		printf("\n\nPress any key to start the game...");
		getch();
		start = clock();
		num_moves = 0;

		clear_the_board(board);

		// main game loop
		do
		{
			clear_screen();
			display_board(board);

			which_player_won = checkforwin(board); // check if the game is still on

			// player 1:
			if (which_player_won == 0)
			{
				switch (game_mode)
				{
				case 1: // player vs player
					give_coordinates();
					is_occupied(board);
					put_coordinates(x, y, board, token_1);

					break;

				case 2: // player vs computer
					give_coordinates();
					is_occupied(board);
					put_coordinates(x, y, board, token_1);

					break;

				case 3: // computer vs computer
					computers_move(board, token_1, token_2, &computer_x, &computer_y);
					put_coordinates(computer_x, computer_y, board, token_1);
					Sleep(1500); // wait for 1.5s, for user to be able to see each move
					
					break;
				}

				num_moves++;
				clear_screen();
				display_board(board);
			}

			which_player_won = checkforwin(board);

			// gracz 2:
			if (which_player_won == 0)
			{
				switch (game_mode)
				{
				case 1: // player vs player
					give_coordinates();
					is_occupied(board);
					put_coordinates(x, y, board, token_2);

					break;

				case 2: // player vs computer
					computers_move(board, token_2, token_1, &computer_x, &computer_y);
					put_coordinates(computer_x, computer_y, board, token_2);

					break;

				case 3: // computer vs computer
					computers_move(board, token_2, token_1, &computer_x, &computer_y);
					put_coordinates(computer_x, computer_y, board, token_2);
					Sleep(1500); // wait for 1.5s, for user to be able to see each move
					
					break;
				}

				num_moves++;
				clear_screen();
				display_board(board);
			}

		} while (which_player_won == 0);

		stop = clock();

		stats();

		play_again();

	} while (1);

	return 0;
}
