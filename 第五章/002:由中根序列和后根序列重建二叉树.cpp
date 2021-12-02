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

vector<int> sequence;

//中根序列是	9 5 32 67
//后根序列		9 32 67 5
//前根序列		5 9 67 32

void rebuild(int *zhong, int *hou, int len) {
	if (len >= 1) {
		cout << hou[len - 1] << " "; //Last element of hougen: first elements
	}
	if (len > 1) {
		for (int i = 0; i < len; i++) {
			if (zhong[i] == hou[len - 1]) {
				rebuild(zhong, hou, i);
				rebuild(zhong + i + 1, hou + i, len - i - 1);
				return;
			}
		}
	}
}

int main() {
	int t;
	int zhongGen[100], houGen[100];
	int i = 0;
	while (cin >> zhongGen[i++]) {
		if (cin.get() != ' ') {
			break;
		}
	}
	int len = i;
	i = 0;
	while (cin >> houGen[i++]) {
		if (cin.get() != ' ') {
			break;
		}
	}
	rebuild(zhongGen, houGen, len);

}
