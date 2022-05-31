#include <stdio.h>

// Stan gry:
char board[3][3]; // 'X' / 'O' / '_'

int difficulty; // można enum, będzie profesjonalniej
int game_mode;
char name_1[50];
char name_2[50];
char token; // znacznik
//...
int num_moves = 0;
//...

int choose_game_mode();

int main()
{
	// Ekran powitalny - użytkownik wybiera opcje itd...

	/****tryb gry****/
	game_mode = choose_game_mode();

	/****trudność****/
	difficulty = choose_difficulty();

	/****wybór imion****/

	/****wybór znacznika****/

	/****start gry****/
	printf("Press any key to start the game...");
	getch();

	/****wyczyszczenie planszy****/

	// Pętla gry
	do
	{
		/****wyczyść ekran****/
		system("cls");
		/****wyświetl planszę****/
		display_board();

		// gracz 1:
		switch (game_mode)
		{
			case 1: // player vs player
		/****zapytaj o współrzędne****/

		/****sprawdź czy dobre i wyświetl feedback****/

			break;

			case 2: // player vs computer
		/****zapytaj o współrzędne****/
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

	} while ( !(/****wygrana?****/) || !(/****remis?****/) );

	/****wyświetl wynik****/

	/****statystyki****/

	/****zapytaj czy chce kontynuować****/

	return 0;
}

int choose_game_mode()
{
	int mode = 0;

	return mode;
}
