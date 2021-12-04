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


/*
* Big Idea:
* DNA를 struct로 만든다. 그후 비교연산자 < 만들어주고, 불안하면 >까지
* reversepair는 문제대로 만들어주면 돼고, sort(dnas, dnas+m)이 포인트.
* 
*
* 
*/
using namespace std;

int strLen, m;
struct DNA {
	string pattern;
	int pairNum;
	int inputOrder;
	friend bool operator<(const DNA a, const DNA b) {
		if (a.pairNum != b.pairNum) {
			return a.pairNum < b.pairNum;
		}
		else {
			return a.inputOrder < b.inputOrder;
		}
	}

	friend bool operator>(const DNA a, const DNA b) {
		if (a.pairNum != b.pairNum) {
			return a.pairNum > b.pairNum;
		}
		else{
			return a.inputOrder > b.inputOrder;
		}
	}

	
}dnas[100];


int getReversePair(string ptr) {
	int ans = 0;
	for (int i = 0; i < strLen; i++) {
		for (int j = i + 1; j < strLen; j++) {
			if (ptr[i] > ptr[j]) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	cin >> strLen >> m;
	for (int i = 0; i < m; i++) {
		string patt;
		cin >> dnas[i].pattern;
		int revNum = getReversePair(dnas[i].pattern);
		dnas[i].pairNum = revNum;
		dnas[i].inputOrder = i;
	}

	sort(dnas, dnas + m);
	for (int i = 0; i < m; i++) {
		cout << dnas[i].pattern << endl;
	}
}
