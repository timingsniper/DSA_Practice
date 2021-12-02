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
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>

using namespace std;
int n, k; // n : dimension, k : number of chess pieces
int a[10];
char board[10][10];
int ans, counter;

void dfs(int current) {
	if (counter == k) { //if counter reaches total num of chess pieces
		ans++;
		return;
	}
	if (current >= n) { //if current exceeds dimension
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!a[i] && board[current][i] == '#') { //if a[i] == 0 and current row's pos i is empty
			a[i] = 1;
			counter++;
			dfs(current + 1);
			a[i] = 0;
			counter--;
		}
	}
	dfs(current + 1);
}


int main() {
	while (cin >> n >> k) {
		if (n == -1 && k == -1) {
			break;
		}
		getchar();
		ans = 0; counter = 0;
		memset(a, 0, sizeof(a));

		for (int i = 0; i < n; i++) {
			cin >> board[i];
		}
		dfs(0);
		cout << ans << endl;
	}

}
