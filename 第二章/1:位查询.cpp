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

//3 = 101
//1<<2 = 100
int nums[100000];
int n, m, op;
char act;

void cAction() {
	for (int i = 0; i < n; i++) {
		nums[i] += op;
	}
}

void qAction() {
	int count = 0;
	int mask = 1 << op;
	for (int i = 0; i < n; i++) {
		if (mask & nums[i]) {
			count++;
		}
	}
	cout << count << endl;
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> act >> op;
		if (act == 'Q') {
			qAction();
		}
		if (act == 'C') {
			cAction();
		}
	}

}
