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
	auto iter = find(v.begin(), v.end(), 12);
	if (iter != v.end()) {
		cout << iter - v.begin();
	}
*/
using namespace std;
//Map 사용법 익히기. sstream도.
//getline(cin, s) && s != " " 하면 공백 나올떄까지 입력 가능
//map.find()하면 못찾으면 .end iterator 반환
map<string, string>dictionary;

int main() {
	string a, b, s;
	while (getline(cin, s) && s != ""){
		stringstream stream(s);
		stream >> a >> b;
		dictionary[b] = a;
	}
	string key;
	while (cin >> key) {
		//cin >> key;

		if (dictionary.find(key) == dictionary.end()) {
			cout << "eh" << endl;
		}	
		else
			cout << dictionary[key] << endl;
	}
}

