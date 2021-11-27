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

int inDegree[100];
int sorted[100];
int graph[100][100]; //v*v array
bool gotPrinted[100];


int main() {
	int v, a, first, second, printCount = 0;
	cin >> v >> a;
	memset(inDegree, 0, sizeof inDegree);
	memset(graph, 0, sizeof graph);
	memset(gotPrinted, 0, sizeof gotPrinted);
	for (int i = 0; i < a; i++) {
		cin >> first >> second;
		inDegree[second - 1]++;
		graph[first-1][second-1] = 1;
	}
	int i = 0;
	while (printCount != v) {
		for (int i = 0; i < v; i++) {
		
			if (inDegree[i] == 0 && !gotPrinted[i]) { //If indegree of the vertice = 0
				cout << "v" << i + 1 << " ";
				printCount++;
				gotPrinted[i] = 1;
			}
			for (int j = 0; j < v; j++) {
				if (graph[i][j] == 1) {
					inDegree[j]--;
					if (inDegree[j] == 0 && j != i && !gotPrinted[j]) {
						cout << "v" << j + 1 << " ";
						printCount++;
						gotPrinted[j] = 1;
					}
				}
				graph[i][j] = -1;

			}
		}
	}
}
