#include <stdio.h>

// Stan gry:
char board[3][3];

int difficulty; // można enum, będzie profesjonalniej
int game_mode;
char name_1[50];
char token; // znacznik
//...
int no_moves = 0;
//...


int main()
{
	// Ekran powitalny - użytkownik wybiera opcje itd...

	/****tryb gry****/

	/****trudność****/

	/****wybór imion****/

	/****wybór znacznika****/

	/****start gry****/

	// Pętla gry
	do
	{
		/****wyczyść ekran****/
		/****wyświetl planszę****/

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

		/****inkrementacja zmiennej no_moves****/

	} while ( !(/****wygrana?****/) || !(/****remis?****/) );

	/****wyświetl wynik i statystyki****/

	return 0;
}
