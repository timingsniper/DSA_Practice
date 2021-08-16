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
const int maxn = 1e5 + 100;
const int inf = 0x7ffffff;
using namespace std;

int main() {
	string str, substr;
	while (cin >> str >> substr) { //while(1)때려넣으면 output limit exceeded 뜸
		

		//int largestChar = str[0];
		int largestPos = 0;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] > str[largestPos]) {
				largestPos = i;
				//cout << largestPos << endl;
			}
		}

		string ans = str.substr(0, largestPos+1) + substr + str.substr(largestPos+1, str.length());
		cout << ans << endl;



	}
}
