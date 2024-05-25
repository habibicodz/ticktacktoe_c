#include <stdio.h>
#include <stdbool.h>

#define N 3

void printCurrentState(char(*)[N]);
void reset(char(*)[N]);
void convertTo2D(int index, int *row, int *column);
void getCharAtIndex(int index, char(*)[N]);

int main () {
	char tickTackToe[N][N];
	reset(tickTackToe);

	bool isEnded = false;
	bool turnX = true;

	bool isFirst = true;
	char firstChar = 'x';
	char secondChar = 'y';

	while (!isEnded) {
		printCurrentState(tickTackToe);

		char currentPlayer = ((isFirst) ? firstChar : secondChar);
		printf("%c: ", currentPlayer);

		int positionChoosed = 0;
		scanf("%d", &positionChoosed);

		getCharAtIndex(positionChoosed, tickTackToe);


		printf("position choosed: %d\n", positionChoosed);
	}
} 

void reset(char game[N][N]) {
	int row;
	int column;

	int rows = N;
	int columns = N;

	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			game[row][column] = ' ';
		}
	}
}

void getCharAtIndex (int index, char game[N][N]) {
	int row, column;
	convertTo2D(index, &row, &column);

	printf("current: (%c)", game[row][column]);
}


void printCurrentState(char game[N][N]) {
	int row;
	int column;

	int rows = N;
	int columns = N;

	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			char choice = game[row][column];
			bool isEmpty = choice == ' ';

			if (isEmpty) {
				int _1DPosition = row * columns + column;
				printf("%d ", _1DPosition+1);
			}
		}
		printf("\n", "]");
	}
}

void convertTo2D (int index, int *row, int *column) {
	*row = index / N;
	*column = index % N;
}