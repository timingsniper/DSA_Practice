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
int n;
int f[300];

struct edge {
	int from, to, weight;
	friend bool operator<(edge e1, edge e2) {
		return e1.weight < e2.weight;
	}
};
vector<edge>edges;

int find(int x) {
	return f[x] < 0 ? x : (f[x] = find(f[x]));
}

bool mer(int x, int y) {
	int rx = find(x); int ry = find(y);
	if (rx != ry) {

		f[rx] += f[ry];
		f[ry] = rx;
		return true;
	}
	return false;
}

int kruscal() {
	memset(f, -1, sizeof(f));
	sort(edges.begin(), edges.end());
	int ans = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		edge e = edges[i];
		if (mer(e.from, e.to))
		{
			ans += e.weight;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		char fromV; int nums;
		cin >> fromV >> nums;
		while (nums--) {
			char toV; int weightVal;
			cin >> toV >> weightVal;
			edges.push_back(edge{ fromV, toV, weightVal });
		}
	}
	cout << kruscal() << endl;
}
