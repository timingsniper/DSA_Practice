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


int n, coeff, power;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		map<int, int, greater<int>>poly;
		for (int j = 0; j < 2; j++) {
			while (true) {
				cin >> coeff >> power;
				if (power < 0) {
					break;
				} 
				if (poly.find(power) != poly.end()) { //poly에서 값을 못찾으면 .end()를 반환하는점 이용, 즉 찾았다면
					poly[power] += coeff;
				}
				else {
					poly.insert(make_pair(power, coeff));
				}
			}
		}

		map<int, int, greater<int>>::iterator iter;
		for (iter = poly.begin(); iter != poly.end(); iter++) {
			if (iter->second == 0) { continue; }
			cout << "[ " << iter->second << " " << iter->first << " ] ";
		}
		cout << endl;

	}
}
