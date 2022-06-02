#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h> 
#include "TicTacToe.h"



int main()
{

	board[0][0] = '_'; board[0][1] = '_'; board[0][2] = '_';
	board[1][0] = '_'; board[1][1] = '_'; board[1][2] = '_';
	board[2][0] = '_'; board[2][1] = '_'; board[2][2] = '_';
	//
	//mastermind_move(board, token_2, token_1, &computer_x, &computer_y);

	int which_player_won = 0;

	do
	{
		// Ekran powitalny - u?ytkownik wybiera opcje itd...
		srand(time(NULL)); // set seed for pseud-random number generator, do it before each game

		///****tryb gry****/
		choose_game_mode(&game_mode);

		///****trudno??****/
		choose_difficulty(&difficulty);

		/****wybór imion****/
		choose_name(game_mode);

		/****wybór znacznika****/
		choose_token();

		/****start gry****/
		system("cls");
		printf("\n\nPress any key to start the game...");
		getch();
		start = clock();
		num_moves = 0;

		/****wyczyszczenie planszy****/
		make_null_tab(board);

		// P?tla gry
		do
		{
			/****wyczy?? ekran****/
			system("cls");
			/****wy?wietl plansz?****/
			Print_Bord_on_Screen(board);

			which_player_won = checkforwin(board);

			// gracz 1:
			if (which_player_won == 0)
			{
				switch (game_mode)
				{
				case 1: // player vs player
					/****zapytaj o wspó?rz?dne****/
					give_coordinates();
					is_occupied(board);
					put_coordinates(x, y, board, token_1);
					/****sprawd? czy dobre i wy?wietl feedback****/

					break;

				case 2: // player vs computer
					/****zapytaj o wspó?rz?dne****/
					give_coordinates();
					is_occupied(board);
					put_coordinates(x, y, board, token_1);
					/****sprawd? czy dobre i wy?wietl feedback****/
					break;

				case 3: // computer vs computer
					/****ruch komputera (w zale?no?ci od poziomy trudno?ci)****/
					computers_move(board, token_1, token_2, &computer_x, &computer_y);
					put_coordinates(computer_x, computer_y, board, token_1);
					Sleep(1500); // wait for 1.5s, for user to be able to see each move
					break;
				}

				num_moves++;
				system("cls");
				Print_Bord_on_Screen(board);
			}

			which_player_won = checkforwin(board);

			// gracz 2:
			if (which_player_won == 0)
			{
				switch (game_mode)
				{
				case 1: // player vs player
					/****zapytaj o wspó?rz?dne****/
					give_coordinates();
					is_occupied(board);
					put_coordinates(x, y, board, token_2);
					/****sprawd? czy dobre i wy?wietl feedback****/
					break;

				case 2: // player vs computer
					/****ruch komputera (w zale?no?ci od poziomy trudno?ci)****/
					computers_move(board, token_2, token_1, &computer_x, &computer_y);
					put_coordinates(computer_x, computer_y, board, token_2);
					break;

				case 3: // computer vs computer
					/****ruch komputera (w zale?no?ci od poziomy trudno?ci)****/
					computers_move(board, token_2, token_1, &computer_x, &computer_y);
					put_coordinates(computer_x, computer_y, board, token_2);
					Sleep(1500); // wait for 1.5s, for user to be able to see each move
					break;
				}

				/****inkrementacja zmiennej num_moves****/
				num_moves++;
				system("cls");
				Print_Bord_on_Screen(board);
			}

		} while (which_player_won == 0);
		//} while (1);

		stop = clock();
		/****wy?wietl wynik****/

		/****statystyki****/
		stats();
		/****zapytaj czy chce kontynuowa?****/
		play_again();

	} while (1);


	return 0;
}
