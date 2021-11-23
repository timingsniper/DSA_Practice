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
	int n;
	
	cin >> n;
	

	while (n--) {
		int i = 2, coeff, power;
		map<int, int, greater<int>> poly; //Polynomial declared with map STL
		while (i--) {
			while (1) {
				cin >> coeff >> power;
				if (power < 0) {
					break;
				}
				if (poly.find(power) != poly.end()) {
					poly[power] += coeff;
				}
				else {
					poly.insert(make_pair(power, coeff));
				}

			}
		}
		for (auto& item : poly) {
			if (item.second != 0) {
				cout << "[ " << item.second << " " << item.first << " ] ";
			}
		}
		cout << endl;
	}
}
