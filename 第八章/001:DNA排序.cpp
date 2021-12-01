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

//map<int, string, less<int>>dna;
int n, m;

struct dnaStruct {
	string seq;
	int pairNum;
	int inputOrder;
	friend bool operator<(const dnaStruct a, const dnaStruct b) {
		if (a.pairNum != b.pairNum) {
			return a.pairNum < b.pairNum;
		}
		else {
			return a.inputOrder < b.inputOrder;
		}
	}

}dnas[100];

int getReversePair(string pattern) {
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (pattern[i] > pattern[j]) {
				ans++;
			}
		}
	}

	return ans;

}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string sequence;
		cin >> dnas[i].seq;
		int revVal = getReversePair(dnas[i].seq);
		dnas[i].inputOrder = i;
		dnas[i].pairNum = revVal;
	}

	sort(dnas, dnas + m);

	for (int i = 0; i < m; i++) {
		cout << dnas[i].seq << endl;
	}

}
