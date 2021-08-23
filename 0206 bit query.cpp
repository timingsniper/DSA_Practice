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

int n, m, key;
char action;
int numbers[100000];

//1 = 01
//2 = 10

void qAction(int q) { //execute action for q
	int i, t, sum = 0;
	t = 1 << q;

	for (i = 0; i < n; i++) {
		if (t & numbers[i]) {
			sum++;
		}
	}
	cout << sum << endl;
}

void cAction(int c) {
	for (int i = 0; i < n; i++) {
		numbers[i] = (numbers[i] + c) % 65536;
	}
}

int main() {
	cin >> n >> m;


	for (int j = 0; j < n; j++) {
		cin >> numbers[j];
	}

	for (int i = 0; i < m; i++) {
		cin >> action >> key;

		if (action == 'Q') {
			qAction(key);
		}
		else if (action == 'C') {
			cAction(key);
		}
	}
}
