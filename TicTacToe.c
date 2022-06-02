#include "TicTacToe.h"
#include <stdio.h>
#include <math.h>
#include <time.h>


int difficulty = 1;
int num_moves = 0;



// Wojtek:
void make_null_tab(char a[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = '_';
		}
	}
}

void Print_Bord_on_Screen(char poziom[3][3])
{
	printf("  " "\n");
	printf("     y=1 y=2 y=3" "\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j == 0) printf("x=1  _%c", poziom[i][j]);
			else if (i == 0 && j == 1) printf("_|_%c", poziom[i][j]);
			else if (i == 0 && j == 2) printf("_|_%c_\n", poziom[i][j]);

			else if (i == 1 && j == 0) printf("x=2  _%c", poziom[i][j]);
			else if (i == 1 && j == 1) printf("_|_%c", poziom[i][j]);
			else if (i == 1 && j == 2) printf("_|_%c_\n", poziom[i][j]);

			else if (i == 2 && j == 0)
				if (poziom[i][j] == '_') printf("x=3    ");
				else printf("x=3   %c", poziom[i][j]);
			else if (i == 2 && j == 1)
				if (poziom[i][j] == '_') printf(" |  ");
				else printf(" | %c", poziom[i][j]);
			else if (i == 2 && j == 2)
				if (poziom[i][j] == '_') printf(" |  ");
				else printf(" | %c ", poziom[i][j]);
		}
	}
}

void put_coordinates(int a, int b, char cos[3][3], char token)
{
	cos[a][b] = token;
}


void give_coordinates()
{

	int temp_x, temp_y;
	printf("\ngive coordinates x ");
	scanf_s("%d", &temp_x);
	x = temp_x - 1;

	coordinatesCheck(&x);

	printf("\ngive coordinates y ");
	scanf_s("%d", &temp_y);
	y = temp_y - 1;

	coordinatesCheck(&y);

}

void coordinatesCheck(int* coordinate)
{
	int temp_coordinate = 0;

	while ((*coordinate != 0) && (*coordinate != 1) && (*coordinate != 2))
	{
		printf("Your coordinates are outside of the game board. Try again: \n");
		printf("coordinate: ");
		scanf_s("%d", &temp_coordinate);
		*coordinate = temp_coordinate - 1;
	}
}

void is_occupied(char board[3][3])
{
	int temp_x, temp_y;
	while (board[x][y] == 'X' || board[x][y] == 'O')
	{
		printf("Your coordinates are pointing to an already occupied spot. Try again: \n");
		printf("x: ");
		scanf_s("%d", &temp_x);
		x = temp_x - 1;
		coordinatesCheck(&x);

		printf("y: ");
		scanf_s("%d", &temp_y);
		y = temp_y - 1;
		coordinatesCheck(&y);
	}

}

void choose_name(int game_mode)
{
	system("cls");
	if (game_mode == 1)
	{
		printf("Give names of players: \n");
		printf("Player 1: \n");
		scanf_s("\n%[^\n]s", &name_1, sizeof(name_1));
		printf("Player 2: \n");
		scanf_s("\n%[^\n]s", &name_2, sizeof(name_2));
	}


	if (game_mode == 2)
	{
		printf("Give your name: \n");
		printf("Player 1: \n");
		scanf_s("\n%[^\n]s", &name_1, sizeof(name_1));

		printf("Player 2: \n");
		printf("Computer");
	}

	if ((game_mode == 3))
	{
		printf("Player 1: \n");
		printf("Computer1 \n");
		printf("Player 2: \n");
		printf("Computer2 \n");
	}
}

// Mateusz:

void choose_token()
{
	//komunikat dla usera
	do {
		system("cls");
		printf("Now you need to choose your game token.");
		printf("\nYou can choose between 'X' or 'O'.");
		printf("\nEnter your choice: ");

		scanf_s(" %c", &token_1);

	} while (token_1 != 'X' && token_1 != 'O');



	if (token_1 == 'X')                //przypisanie tokenow do zmiennych
	{
		token_2 = 'O';
	}
	else
	{
		token_2 = 'X';
	}
	system("cls");
	printf("Your choice is '%c' token.", token_1);
	printf("\nPlayer 2 has '%c' token.\n", token_2);
}

void stats()
{
	game_duration = (float)(stop - start) / CLOCKS_PER_SEC;
	int game_duration_min = game_duration / 60;
	float game_duration_sec = (int)game_duration % 60;

	printf("\nIn this game %d moves was performed\n", num_moves);
	printf("Game duration: %d minutes and %.f seconds. ", game_duration_min, game_duration_sec);
}

void play_again()
{

	char newGame;

	do
	{
		printf("Do You want to play again? (Y / N)\n");
		scanf_s(" %c", &newGame);

	} while (newGame != 'Y' && newGame != 'N');

	if (newGame == 'N')
	{
		printf("\nGood Bye!");
		exit(0);
	}

}

// Michal:

void choose_difficulty(int* difficulty)
{
	char temp_difficulty;

	system("cls");
	printf("Choose difficulty level:\n\n");
	printf("1 - dummy\n\n2 - mastermind\n\n");
	scanf_s("\n%c", &temp_difficulty);

	while (temp_difficulty != '1' && temp_difficulty != '2')
	{
		system("cls");
		printf("Make sure, that you enter correct value...\n\n");

		printf("Choose difficulty level:\n\n");
		printf("1 - dummy\n\n2 - mastermind\n\n");
		scanf_s("\n%c", &temp_difficulty);
	}

	*difficulty = (int)temp_difficulty - 48;
}

// TODO: Replace computer_x with x...
void computers_move(char board[3][3], char my_token, char rivals_token, int* computer_x, int* computer_y)
{
	switch (difficulty)
	{
	case 1: // dummy
		dummy_move(board, my_token, computer_x, computer_y);
		break;

	case 2: // mastermind
		mastermind_move(board, token_1, token_2, computer_x, computer_y);
		break;
	}

}

void dummy_move(char board[3][3], char my_token, int* computer_x, int* computer_y)
{
	int temp_x = 0;
	int temp_y = 0;

	do
	{
		temp_x = rand() % 3;
		temp_y = rand() % 3;
	} while (board[temp_x][temp_y] != '_');

	*computer_x = temp_x;
	*computer_y = temp_y;
}

void mastermind_move(char board[3][3], char my_token, char rivals_token, int* computer_x, int* computer_y)
{
	int found_move = 0; // if algorithm finds the right move, it skips the remaining calculations

	// can I win in this move? if so, do it
	found_move = can_player_win(board, my_token, computer_x, computer_y);


	// can the rival win in the next move? how? if so, prevent that
	if (!found_move)
	{
		found_move = can_player_win(board, rivals_token, computer_x, computer_y);
	}

	// if none of the above is true, assess each of the possibile moves: 
	if (!found_move)
	{
		int temp_computer_x, temp_computer_y;
		float best_rate = -1.0; // results of assessment of particular moves
		float current_rate;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '_') // check if the tile is empty
				{
					//how many winning opportunities for me it creates? how many winning opportunities for the rival does it block?
					current_rate = assess_move(board, i, j, my_token, rivals_token);
					if (current_rate > best_rate)
					{
						// if the currently considered move is the best so far, remember it
						best_rate = current_rate;
						temp_computer_x = i;
						temp_computer_y = j;
					}
				}
			}
		}
		// return final coordinates
		*computer_x = temp_computer_x;
		*computer_y = temp_computer_y;
	}

}

float assess_move(char board[3][3], int x, int y, char my_token, char rivals_token)
{
	// Check if that move creates some possibilities for creating a winning line or prevents 
	// the rival from creating his winning lines. If there is such possibility take it into account
	// while assessing the quality of the move. Line where there'd be only one token left should be 
	// weighted more.

	float move_quality = 0;

	int no_empty_tiles_in_line = 0; // number of empty tiles and my tokens in the currently considered line
	int no_my_tokens_in_line = 0;
	int no_rivals_tokens_in_line = 0;
	// count how many winning lines could be made with my token placed in here

	// row
	no_empty_tiles_in_line = 0;
	no_my_tokens_in_line = 0;
	no_rivals_tokens_in_line = 0;
	for (int i = 0; i < 3; i++)
	{
		if (board[x][i] == '_')
		{
			no_empty_tiles_in_line++;
		}
		if (board[x][i] == my_token)
		{
			no_my_tokens_in_line++;
		}
		if (board[x][i] == rivals_token)
		{
			no_rivals_tokens_in_line++;
		}
	}

	move_quality += quality_for_that_line(no_empty_tiles_in_line, no_my_tokens_in_line, no_rivals_tokens_in_line);

	// column
	no_empty_tiles_in_line = 0;
	no_my_tokens_in_line = 0;
	no_rivals_tokens_in_line = 0;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][y] == '_')
		{
			no_empty_tiles_in_line++;
		}
		if (board[i][y] == my_token)
		{
			no_my_tokens_in_line++;
		}
		if (board[i][y] == rivals_token)
		{
			no_rivals_tokens_in_line++;
		}
	}

	move_quality += quality_for_that_line(no_empty_tiles_in_line, no_my_tokens_in_line, no_rivals_tokens_in_line);

	// first diagonal
	if (x == y)
	{
		no_empty_tiles_in_line = 0;
		no_my_tokens_in_line = 0;
		no_rivals_tokens_in_line = 0;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] == '_')
			{
				no_empty_tiles_in_line++;
			}
			if (board[i][i] == my_token)
			{
				no_my_tokens_in_line++;
			}
			if (board[i][i] == rivals_token)
			{
				no_rivals_tokens_in_line++;
			}
		}

		move_quality += quality_for_that_line(no_empty_tiles_in_line, no_my_tokens_in_line, no_rivals_tokens_in_line);
	}



	// second diagonal
	if (x + y == 3 - 1)
	{
		no_empty_tiles_in_line = 0;
		no_my_tokens_in_line = 0;
		no_rivals_tokens_in_line = 0;
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2 - i] == '_')
			{
				no_empty_tiles_in_line++;
			}
			if (board[i][2 - i] == my_token)
			{
				no_my_tokens_in_line++;
			}
			if (board[i][2 - i] == rivals_token)
			{
				no_rivals_tokens_in_line++;
			}
		}

		move_quality += quality_for_that_line(no_empty_tiles_in_line, no_my_tokens_in_line, no_rivals_tokens_in_line);
	}

	return move_quality;
}

float quality_for_that_line(int no_empty_tiles_in_line, int no_my_tokens_in_line, int no_rivals_tokens_in_line)
{
	float empty_line_weight = 0.5; // weight for the case when there is no token 
	float my_token_present_weight = 1; // weight for the case when there has been a token already
	float rivals_token_present_weight = 0.9; // weight for the case when there has been a rivals token already

	float quality = 0;

	if (no_empty_tiles_in_line == 3)
	{
		quality += empty_line_weight;
	}
	else if (no_empty_tiles_in_line == 2 && no_my_tokens_in_line == 1)
	{
		quality += my_token_present_weight;
	}
	else if (no_empty_tiles_in_line == 2 && no_rivals_tokens_in_line == 1)
	{
		quality += rivals_token_present_weight;
	}

	return quality;
}

int can_player_win(char board[3][3], char players_token, int* winning_choice_x, int* winning_choice_y)
{
	int can_he_win = 0;
	char empty_tile = '_';
	int temp_no_rivals_tokens = 0; // to determine how many tokens rival already has in particular row / column / diagonal
	int temp_no_empty_tiles = 0; // how many empty tiles are in particular row / column / diagonal
	int temp_winning_choice_x = -1; // coordinates of potential winning move (-1 means there's no such a move)
	int temp_winning_choice_y = -1;
	// if in any row, column or diagnoal there are exactly 2 rival tokens along with one empty tile, then we have trouble

	// check each row:
	for (int i = 0; i < 3; i++) // y-coordinate
	{
		temp_no_rivals_tokens = 0;
		temp_no_empty_tiles = 0;
		for (int j = 0; j < 3; j++) // x-coordinate
		{
			if (board[i][j] == players_token)
			{
				temp_no_rivals_tokens++;
			}
			else if (board[i][j] == empty_tile)
			{
				temp_no_empty_tiles++;
				temp_winning_choice_x = i; // if it later on turns out that there's only one epmty tile and exactly 2 rival's tokens - that's the right move for him
				temp_winning_choice_y = j;
			}
		}
		if (temp_no_rivals_tokens == 2 && temp_no_empty_tiles == 1) // otherwise there's my token which prevents him from winning in that row
		{
			can_he_win = 1;
			*winning_choice_x = temp_winning_choice_x;
			*winning_choice_y = temp_winning_choice_y;
		}
	}

	// check each column:
	for (int j = 0; j < 3; j++) // x-coordinate
	{
		temp_no_rivals_tokens = 0;
		temp_no_empty_tiles = 0;
		for (int i = 0; i < 3; i++) // y-coordinate
		{
			if (board[i][j] == players_token)
			{
				temp_no_rivals_tokens++;
			}
			else if (board[i][j] == empty_tile)
			{
				temp_no_empty_tiles++;
				temp_winning_choice_x = i; // if it later on turns out that there's only one epmty tile and exactly 2 rival's tokens - that's the right move for him
				temp_winning_choice_y = j;
			}
		}
		if (temp_no_rivals_tokens == 2 && temp_no_empty_tiles == 1) // otherwise there's my token which prevents him from winning in that row
		{
			can_he_win = 1;
			*winning_choice_x = temp_winning_choice_x;
			*winning_choice_y = temp_winning_choice_y;
		}
	}

	// check first diagonal:
	temp_no_rivals_tokens = 0;
	temp_no_empty_tiles = 0;
	for (int i = 0; i < 3; i++) // y-coordinate
	{
		for (int j = 0; j < 3; j++) // x-coordinate
		{
			if (i == j) // check of tile belongs to the diagonal
			{
				if (board[i][j] == players_token)
				{
					temp_no_rivals_tokens++;
				}
				else if (board[i][j] == empty_tile)
				{
					temp_no_empty_tiles++;
					temp_winning_choice_x = i; // if it later on turns out that there's only one epmty tile and exactly 2 rival's tokens - that's the right move for him
					temp_winning_choice_y = j;
				}
			}
		}
	}
	if (temp_no_rivals_tokens == 2 && temp_no_empty_tiles == 1) // otherwise there's my token which prevents him from winning in that row
	{
		can_he_win = 1;
		*winning_choice_x = temp_winning_choice_x;
		*winning_choice_y = temp_winning_choice_y;
	}

	// check second diagonal:
	temp_no_rivals_tokens = 0;
	temp_no_empty_tiles = 0;
	for (int i = 0; i < 3; i++) // y-coordinate
	{
		for (int j = 0; j < 3; j++) // x-coordinate
		{
			if (i + j == 2) // check of tile belongs to the diagonal
			{
				if (board[i][j] == players_token)
				{
					temp_no_rivals_tokens++;
				}
				else if (board[i][j] == empty_tile)
				{
					temp_no_empty_tiles++;
					temp_winning_choice_x = i; // if it later on turns out that there's only one epmty tile and exactly 2 rival's tokens - that's the right move for him
					temp_winning_choice_y = j;
				}
			}
		}
	}
	if (temp_no_rivals_tokens == 2 && temp_no_empty_tiles == 1) // otherwise there's my token which prevents him from winning in that row
	{
		can_he_win = 1;
		*winning_choice_x = temp_winning_choice_x;
		*winning_choice_y = temp_winning_choice_y;
	}


	// TODO: Extract "check each row" and "check each column" sections into separate functions
	return can_he_win;
}

// Gaba:


void choose_game_mode(int* game_mode)
{
	char temp_game_mode = ' ';

	do {
		system("cls");
		printf("Choose game mode:\n\nPlayer vs player - Press 1\nPlayer vs computer - Press 2\nComputer vs Computer - Press 3\n");
		scanf_s("%c", &temp_game_mode);
	} while (temp_game_mode != '1' && temp_game_mode != '2' && temp_game_mode != '3');

	*game_mode = (int)temp_game_mode - 48;
}


int checkforwin(int board[3][3])
{
	int which_player_won = 0; // 0 - nobody; 1 - player_1; 2 - player_2; 3 - tie

	if (has_token_won(token_1, board))
	{
		which_player_won = 1;
		printf("%s won", name_1);
	}
	// has player_2 won?
	else if (has_token_won(token_2, board))
	{
		which_player_won = 2;
		printf("%s won", name_2);
	}
	// was there a tie?
	else if (is_board_full(board) && which_player_won == 0) {
		printf("Draw! Nobody wins\n");
		which_player_won = 3;
	}

	return which_player_won;
}

int is_board_full(char board[3][3])
{
	int is_board_full = 1; // 0 - there's no draw; 1 - there's draw

	for (int i = 0; i < 3; i++) // row loop
	{
		for (int j = 0; j < 3; j++) // column loop
		{
			if (board[i][j] == '_')
			{
				is_board_full = 0;
			}
		}
	}

	return is_board_full;
}

int has_token_won(char token, char board[3][3])
{
	int has_token_won = 0;

	int no_tokens_in_line = 0;

	//check each row
	for (int i = 0; i < 3; i++) // row loop
	{
		no_tokens_in_line = 0;
		for (int j = 0; j < 3; j++) // column loop
		{
			if (board[i][j] == token)
			{
				no_tokens_in_line++;
			}
		}
		if (no_tokens_in_line == 3)
		{
			has_token_won = 1;
		}
	}

	// check each column
	for (int j = 0; j < 3; j++) // row loop
	{
		no_tokens_in_line = 0;
		for (int i = 0; i < 3; i++) // column loop
		{
			if (board[i][j] == token)
			{
				no_tokens_in_line++;
			}
		}
		if (no_tokens_in_line == 3)
		{
			has_token_won = 1;
		}
	}

	// check first diagonal
	if (board[0][0] == token && board[1][1] == token && board[2][2] == token) {
		has_token_won = 1;
	}

	// check second diagonal
	else if (board[0][2] == token && board[1][1] == token && board[2][0] == token) {
		has_token_won = 1;
	}

	return has_token_won;
}


