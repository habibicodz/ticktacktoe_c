#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3

void printCurrentState(char(*)[N]);
void reset(char(*)[N]);
void convertTo2D(int index, int *row, int *column);
void convertTo1D(int row, int column, int *index);
int get1DIndex(int row, int column);
char getCharAtIndex(int index, char(*)[N]);
bool fillSpace (char player, int index, char(*)[N]);
bool checkRows(char game[N][N]);
bool checkColumns(char game[N][N]);
bool checkDiagonals(char game[N][N]);
bool checkAntiDiagonals(char game[N][N]);
bool checkWin (char game[N][N]);
void clearScreen();

int main () {
	char tickTackToe[N][N];
	reset(tickTackToe);

	bool isEnded = false;
	bool turnX = true;

	bool isFirst = true;
	char firstChar = 'x';
	char secondChar = 'y';

	clearScreen();
	printCurrentState(tickTackToe);

	while (!isEnded) {

		//Get the current player
		char currentPlayer = ((isFirst) ? firstChar : secondChar);
		printf("%c: ", currentPlayer);

		int positionChoosed = 0;
		scanf("%d", &positionChoosed);

		char characterAtChoosed = getCharAtIndex(positionChoosed, tickTackToe);
		//Clear the screen first
		clearScreen();

		if (fillSpace(currentPlayer, positionChoosed - 1, tickTackToe)) {
			if (checkWin(tickTackToe)) {
				isEnded = true;
				continue;
			} else {
				isFirst = !isFirst;
			}
		} else {
			printf("%d Wrong position choosed\n", positionChoosed);
		}

		//Everytime something is changed Print the game
		printCurrentState(tickTackToe);
	}
} 

void reset(char game[N][N]) {
	int row;
	int column;

	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			game[row][column] = ' ';
		}
	}
}

char getCharAtIndex (int index, char game[N][N]) {
	int row, column;
	convertTo2D(index, &row, &column);
	return game[row][column];
}


void printCurrentState(char game[N][N]) {
	int row;
	int column;

	char _1 = ((game[0][0] == ' ') ? '1' : game[0][0]);
	char _2 = ((game[0][1] == ' ') ? '2' : game[0][1]);
	char _3 = ((game[0][2] == ' ') ? '3' : game[0][2]);
	char _4 = ((game[1][0] == ' ') ? '4' : game[1][0]);
	char _5 = ((game[1][1] == ' ') ? '5' : game[1][1]);
	char _6 = ((game[1][2] == ' ') ? '6' : game[1][2]);
	char _7 = ((game[2][0] == ' ') ? '7' : game[2][0]);
	char _8 = ((game[2][1] == ' ') ? '8' : game[2][1]);
	char _9 = ((game[2][2] == ' ') ? '9' : game[2][2]);

	 system("cls");
	 printf("\n\t|\t|\n");
	 printf("\t|\t|\n");
	 printf("%c\t|%c\t|%c\n", _1, _2, _3);
	 printf("--------|-------|--------\n");
	 printf("\t|\t|\n");
	 printf("%c\t|%c\t|%c\n", _4, _5, _6);
	 printf("--------|-------|--------\n");
	 printf("\t|\t|\n");
	 printf("%c\t|%c\t|%c\n", _7, _8, _9);
	 printf("\t|\t|\n");
}

void convertTo2D (int index, int *row, int *column) {
	*row = index / N;
	*column = index % N;
}

bool fillSpace(char player, int index, char game[N][N]) {
	int row, column;
	convertTo2D(index, &row, &column);
	if (game[row][column] != ' ') return false;
	game[row][column] = player;
	return true;
}

bool checkWin (char game[N][N]) {
	//Check Rows
	if (checkRows(game)) {
		return true;
	} else if (checkColumns(game)) {
		return true;
	} else if (checkDiagonals(game)) {
		return true;
	} else if (checkAntiDiagonals(game)) {
		return true;
	}

	return false;
}

void clearScreen() {
	system("cls");
}

bool checkRows(char game[N][N]) {
	bool checkWin = false;

	OUTER:for (int row = 0; row < N; row++) {
		if (checkWin) break;

		int filledTime = 0;
		char playerToCheck = game[row][0];

		for (int column = 0; column < N; column++) {
			char currentChar = game[row][column];

			if (currentChar != ' ' && game[row][column] == playerToCheck) {
				filledTime++;
			}

			if (filledTime == N) {
				printf("Player %c win the game\n", playerToCheck);
				checkWin = true;
				goto OUTER;
			}
		}
	}

	return checkWin;
}

bool checkDiagonals (char game[N][N]) {
	int filledTime = false;
	char playerToCheck = game[0][0];

	for (int i = 0; i < N; i++) {
		char c = game[i][i];

		if (c != ' ' && c == playerToCheck) {
			filledTime++;
		}

		if (filledTime == N) {
			printf("Player %c win the game\n", playerToCheck);
			return true;
		}
	}

	return false;
}

bool checkAntiDiagonals (char game[N][N]) {
	int filledTime = false;
	char playerToCheck = game[N - 1][N - 3];

	for (int i = 0; i < N; i++) {
		char c = game[i][N - 1 - i];

		if (c != ' ' && c == playerToCheck) {
			filledTime++;
		}

		if (filledTime == N) {
			printf("Player %c win the game\n", playerToCheck);
			return true;
		}
	}

	return false;
}

bool checkColumns(char game[N][N]) {
	bool checkWin = false;

	OUTER:for (int column = 0; column < N; column++) {
		if (checkWin) break;

		int filledTime = 0;
		char playerToCheck = game[0][column];

		for (int row = 0; row < N; row++) {
			char currentChar = game[row][column];

			if (currentChar != ' ' && game[row][column] == playerToCheck) {
				filledTime++;
			}

			if (filledTime == N) {
				printf("Player %c win the game\n", playerToCheck);
				checkWin = true;
				goto OUTER;
			}
		}
	}

	return checkWin;
}

void convertTo1D(int column, int row, int *index) {
	*index = row * N + column;
}

int get1DIndex(int column, int row) {
	return row * N + column;
}