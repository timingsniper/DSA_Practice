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

using namespace std;

int main() {
	int n, m;
	char command; int key;
	int arr[100000];
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int answer = 0;
		cin >> command >> key;
		
		if (command == 'C') {
			for (int j = 0; j < n; j++) {
				arr[j] += key;
				if (arr[j] > 65535) {
					arr[j] %= 65536;
				}
			}
		}
		else if (command == 'Q') {
			int check = 1 << key;
			
			for (int j = 0; j < n; j++) {
				if (check & arr[j]) {
					answer++;
				}
			}
			cout << answer << endl;
		}
		
	}
}
