#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define DIRECTION 224
#define NOTHING 0
#define HEAD 1
#define EGG 2
#define BODY 3
#define BODYMAX 50
#define Y 0
#define X 1
using namespace std;

void output();
void newEgg();
void up();
void down();
void left();
void right();
int map[25][100];
int bodyLong = 2;
int head[2] = {0, 2};
int body[BODYMAX][2];
int score = 0;
int firstBody = 1, tail = 0;


int main() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = NOTHING;
		}
	}
	map[0][2] = HEAD;
	body[1][Y] = 0; body[1][X] = 1;
	body[0][Y] = 0; body[0][X] = 0;
	srand((unsigned) time(NULL));
	newEgg();
	output();
	
	int input;
	while(input = getch()) {
        if (input == DIRECTION) {
            input = getch();
            switch (input) {
                case UP:
                    up();
                    break;
                case DOWN:
                    down();
                    break;
                case LEFT:
                    left();
                    break;
                case RIGHT:
                    right();
                    break;
            }
        }
        output();
    }
	
}

void newEgg() {
	int x, y;
	do {
		x = rand() % 100;
		y = rand() % 25;
	} while(map[y][x] != NOTHING);
	map[y][x] = EGG;
}

void output() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == NOTHING) {
				cout << "*";
			} else if (map[i][j] == EGG) {
				cout << "$";
			} else if (map[i][j] == HEAD) {
				cout << "@";
			} else if (map[i][j] == BODY) {
				cout << "0";
			}
		}
		cout << endl;
	}
}

void up() {
	if (map[head[Y] - 1][head[X]] == NOTHING) {
		firstBody++;
		body[firstBody][Y] = head[Y];
		tail++;
		head[Y]--;
		
	}
}
