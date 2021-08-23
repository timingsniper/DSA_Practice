#include <iostream>
#include <math.h>
#include <cmath>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;

const int inf = 9999999;

int board[10][10], i, j;
int ans = inf;
char qis[16];

//black = 0
//white = 1

int check() { //checks if the board is filled with uniform color
	int key = board[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != key) {
				return 0;
			}
		}
	}
	return 1;
}

void flip(int x, int y) { //performs flip w/boundary checks
	board[x][y] = !board[x][y]; 
	if (x - 1 >= 0) {
		board[x - 1][y] = !board[x - 1][y];
	}
	if (x + 1 < 4) {
		board[x + 1][y] = !board[x + 1][y];
	}
	if (y - 1 >= 0) {
		board[x][y - 1] = !board[x][y - 1];
	}
	if (y + 1 < 4) {
		board[x][y + 1] = !board[x][y + 1];
	}
}

/* (0,0,0)
* nx = 1%4 = 1
* ny= 0+1/4 = 0
* 
* (1,0,0)
* 
*/

int dfs(int x, int y, int t) {
	if (check()) {
		if (ans > t) {
			ans = t;
		}
		return 0;
	}

	if (x >= 4 || y >= 4) {
		return 0;
	}
	int nx, ny;
	nx = (x + 1) % 4;
	ny = y + (x + 1) / 4;

	dfs(nx, ny, t);
	flip(x, y);

	dfs(nx, ny, t + 1);
	flip(x, y);

	return 0;
}

int main() {
	for (i = 0; i < 4; i++) {
		cin >> qis;
		for (j = 0; j < 4; j++) {
			if (qis[j] == 'b') {
				board[i][j] = 0;
			}
			else
				board[i][j] = 1;
		}
	}

	dfs(0, 0, 0);

	if (ans == inf) {
		cout << "Impossible" << endl;
	}
	else
		cout << ans << endl;

}
