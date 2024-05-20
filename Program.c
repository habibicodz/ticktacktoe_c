#include <stdio.h>
#include <stdbool.h>

void printCurrentState(char(*)[3]);
void reset(char(*)[3]);

int main () {
	char tickTackToe[3][3];
	reset(tickTackToe);

	bool isEnded = false;
	bool turnX = true;

	while (!isEnded) {
		// Print the state first
		printCurrentState(tickTackToe);
		int input = '';
		scanf("%d", &input);

	}
} 

void reset(char game[3][3]) {
	int row;
	int column;

	int rows = 3;
	int columns = 3;

	for (row = 0; row < 3; row++) {
		for (column = 0; column < 3; column++) {
			game[row][column] = ' ';
		}
	}
}


void printCurrentState(char game[3][3]) {
	int row;
	int column;

	int rows = 3;
	int columns = 3;

	for (row = 0; row < 3; row++) {
		for (column = 0; column < 3; column++) {
			char choice = game[row][column];
			bool isEmpty = choice == ' ';

			if (choice == ' ') {
				int order = column + (row * columns);
				printf("%d ", order+1);
			}
		}
		printf("\n", "]");
	}
}