#include <stdio.h>
#include <math.h>
#include <time.h>


// Stan gry:
char board[3][3]; // 'X' / 'O' / '_'

int x, y; // coordinates chosen by user
int computer_x, computer_y; // coordinates chosen by computer


int difficulty; // można enum, będzie profesjonalniej
int game_mode = 2;
char name_1[50] = "";
char name_2[50] = "";
char token_1; // znacznik
char token_2; // znacznik
//...
int num_moves = 0;
//...
clock_t start, stop; // stats
float game_duration; // stats


void make_null_tab(char a[3][3]);
void Print_Bord_on_Screen(char poziom[3][3]);
void give_coordinates();
void coordinatesCheck(int x, int y);
void is_occupied(char board[3][3]);
void choose_name(int game_mode);
void choose_token();
void stats();
void computers_move(char board[3][3], char my_token, char rivals_token, int* computer_x, int* computer_y);
int can_rival_win(char board[3][3], char rivals_token, int* winning_choice_x, int* winning_choice_y);

int main()
{

	board[0][0] = 'X'; board[0][1] = 'O'; board[0][2] = '_';
	board[1][0] = 'O'; board[1][1] = 'X'; board[1][2] = '_';
	board[2][0] = 'X'; board[2][1] = 'O'; board[2][2] = 'O';

	do
	{
		// Ekran powitalny - użytkownik wybiera opcje itd...

///****tryb gry****/
//game_mode = choose_game_mode();

///****trudność****/
//difficulty = choose_difficulty();

/****wybór imion****/
		choose_name(game_mode);

		/****wybór znacznika****/
		choose_token();

		/****start gry****/
		printf("Press any key to start the game...");
		getch();
		start = clock();
		num_moves = 0;

		/****wyczyszczenie planszy****/
		//make_null_tab(board);

		// Pętla gry
		do
		{
			/****wyczyść ekran****/
			system("cls");
			/****wyświetl planszę****/
			Print_Bord_on_Screen(board);

			// gracz 1:
			switch (game_mode)
			{
			case 1: // player vs player
		/****zapytaj o współrzędne****/
				give_coordinates();
				coordinatesCheck(x, y);
				is_occupied(board);
				/****sprawdź czy dobre i wyświetl feedback****/

				break;

			case 2: // player vs computer
		/****zapytaj o współrzędne****/
				give_coordinates();
				coordinatesCheck(x, y);
				is_occupied(board);
				/****sprawdź czy dobre i wyświetl feedback****/
				break;

			case 3: // computer vs computer
		/****ruch komputera (w zależności od poziomy trudności)****/
				break;
			}

			// gracz 2:
			switch (game_mode)
			{
			case 1: // player vs player
		/****zapytaj o współrzędne****/
				give_coordinates();
				coordinatesCheck(x, y);
				is_occupied(board);
				/****sprawdź czy dobre i wyświetl feedback****/
				break;

			case 2: // player vs computer
		/****ruch komputera (w zależności od poziomy trudności)****/
				break;

			case 3: // computer vs computer
		/****ruch komputera (w zależności od poziomy trudności)****/
				break;
			}

			/****inkrementacja zmiennej num_moves****/
			num_moves++;

			//} while (!(/****wygrana?****/) || !(/****remis?****/));
		} while (0);
		stop = clock();
		/****wyświetl wynik****/

		/****statystyki****/
		stats();
		/****zapytaj czy chce kontynuować****/

	} while (1);

	return 0;
}

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

void give_coordinates()
{
	int temp_x, temp_y;
	printf("\ngive coordinates x ");
	scanf_s("%d", &temp_x);
	x = temp_x - 1;
	printf("\ngive coordinates y ");
	scanf_s("%d", &temp_y);
	y = temp_y - 1;
}

// Iza:

void coordinatesCheck(int x, int y)
{
	int temp_x, temp_y;
	while ((x != 0) && (x != 1) && (x != 2) || (y != 0) && (y != 1) && (y != 2))
	{
		printf("Your coordinates are outside of the game board. Try again: \n");
		printf("x: ");
		scanf_s("%d", &temp_x);
		x = temp_x - 1;
		printf("y: ");
		scanf_s("%d", &temp_y);
		y = temp_y - 1;
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
		printf("y: ");
		scanf_s("%d", &temp_y);
		y = temp_y - 1;
	}

}

void choose_name(int game_mode)
{
	if (game_mode == 1) //player vs player
	{
		printf("Give names of players: \n");
		printf("Player 1: \n");
		scanf_s("%s", name_1, 20);
		printf("Player 2: \n");
		scanf_s("%s", name_2, 20);
	}
	
	if (game_mode == 2) // player vs computer
	{
		printf("Give your name: \n");
		printf("Player 1: \n");
		scanf_s("%s", name_1, 20);
		printf("Player 2: \n");
		printf("Computer");
	}
}

// Mateusz:

void choose_token()
{
	//komunikat dla usera
	do {
		printf("\nNow you need to choose your game token.");
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
	printf("\n*", token_1);
	printf("\nYour choice is '%c' token.", token_1);
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


//char newGame;
//printf("Do You want to play again? (Y / N)\n");
//do
//{
//	scanf_s(" %c", &newGame);
//
//} while (newGame != 'Y' && newGame != 'N');
//
//
//
//if (newGame == 'Y')
//{
//
//	// startprogram();  ??
//}
//else if (newGame == 'N')
//{
//	printf("\nGood Bye!");
//	exit(0);
//}

// Michal:

void computers_move(char board[3][3], char my_token, char rivals_token, int* computer_x, int* computer_y) 
{
	// can the rival win in the next move?
	can_rival_win(board, rivals_token, computer_x, computer_y);
	// how?
	// if so, prevent that (go with first available option)

	// if no, process each move: 
	// how many winning opportunities it creates?
	// how many winning opportunities for the rival it blocks

	// choose the best one (but how the algorithm is going to "remember" that?)
}

int can_rival_win(char board[3][3], char rivals_token, int* winning_choice_x, int* winning_choice_y)
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
			if (board[i][j] == rivals_token)
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
			if (board[i][j] == rivals_token)
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
				if (board[i][j] == rivals_token)
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
				if (board[i][j] == rivals_token)
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
