#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <random>

using namespace std;

class Dino {

private:

	enum {
		ARROW_UP = 72,
		ARROW_DOWN = 80
	};

	int n = 30;
	int m = 120;
	int delay = 50;
	int X = 10;
	int Y;
	int Time;
	int cordinate_line_X;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coordinate = {0, 0};

	char **gameBoard, **oldGameBoard;

	bool run_game = true;

	const char WALL_SYMBOL = '#', SPACE_SYMBOL = ' ';

	char **CreateBoard(bool fill) {
		char **board = new char *[n];
		for (int i = 0; i < n; i++) {
			board[i] = new char[m];
			for (int j = 0; j < m; j++) {
				board[i][j] = fill ? (i == 0 || i == n - 1 || j == 0 || j == m - 1 ? WALL_SYMBOL : SPACE_SYMBOL)
								   : SPACE_SYMBOL;
			}
		}

		return board;
	}

	static int Random(int min, int max) {
		random_device rd;
		mt19937 rng(rd());
		uniform_int_distribution<int> uni(min, max);

		return uni(rng);
	}

	void MoveCursorTo(int coordinateX, int coordinateY) {
		coordinate.X = coordinateX;
		coordinate.Y = coordinateY;
		SetConsoleCursorPosition(handle, coordinate);
	}

	void Input() {
		if (_kbhit()) {
			int ch = 0;
			while (_kbhit()) {
				ch = _getch();
			}
			switch (ch) {
				case ARROW_UP:
					Time = 10;
					break;
				case ARROW_DOWN:
					Time = 0;
					break;
				default:
					break;
			}
		}
	}

	void Dinosaur(int x, int y, bool fill) {
		gameBoard[y][x] = fill ? '*' : ' ';
		gameBoard[y - 1][x] = fill ? '*' : ' ';
		gameBoard[y - 2][x - 1] = fill ? '*' : ' ';
		gameBoard[y - 2][x - 2] = fill ? '*' : ' ';
		gameBoard[y - 1][x + 1] = fill ? '*' : ' ';
		gameBoard[y - 1][x] = fill ? '*' : ' ';
		gameBoard[y - 2][x] = fill ? '*' : ' ';
		gameBoard[y - 1][x + 2] = fill ? '*' : ' ';
		gameBoard[y - 2][x + 1] = fill ? '*' : ' ';
		gameBoard[y - 2][x + 2] = fill ? '*' : ' ';
		gameBoard[y - 2][x + 3] = fill ? '*' : ' ';
		gameBoard[y - 1][x + 3] = fill ? '*' : ' ';
		gameBoard[y - 1][x + 3] = fill ? '*' : ' ';
		gameBoard[y - 1][x + 3] = fill ? '*' : ' ';
		gameBoard[y - 3][x + 4] = fill ? '*' : ' ';
		gameBoard[y - 3][x + 3] = fill ? '*' : ' ';
		gameBoard[y - 3][x + 5] = fill ? '*' : ' ';
		gameBoard[y][x + 3] = fill ? '*' : ' ';
	}

	void Logic() {
		int old_line_X = cordinate_line_X;
		cordinate_line_X--;

		if (cordinate_line_X == 0) {
			cordinate_line_X = m - 1;
		}


		Dinosaur(X, Y, false);
		//gameBoard[Y][X] = ' ';

		for (int i = n - 2; i > 15; i--) {

			if (old_line_X != 0 && old_line_X != (m - 1)) {
				gameBoard[i][old_line_X] = SPACE_SYMBOL;
			}

			gameBoard[i][cordinate_line_X] = WALL_SYMBOL;
		}

		Y = Time == 0 ? (n-2) : (n-16);


		Dinosaur(X, Y, true);
		//gameBoard[Y][X] = '*';
		if(Time > 0)
		{
			Time--;
		}
//		gameBoard[i][cordinate_line_X]
	}

	void Draw() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (gameBoard[i][j] != oldGameBoard[i][j]) {
					oldGameBoard[i][j] = gameBoard[i][j];
					MoveCursorTo(j, i);
					cout << gameBoard[i][j];
				}
			}
		}
	}


public:

	Dino() {

		cordinate_line_X = m - 1;


		gameBoard = CreateBoard(true);
		oldGameBoard = CreateBoard(false);
		Y = n-2;
		Time = 0;
//		gameBoard[n-16][10] = '*';
	}

	void Run() {
		while (run_game) {
			Draw();
			Sleep(delay);
			Input();
			Logic();
		}
	}

};