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
* Topological Sorting은 먼저 indegree가 0인놈을 없애고, 없앨때 걔로부터 연결되있는 선들을 지워주고, 그친구들의 indegree도 1 줄여주는것이 필요.
* 입력을 받을때, graph[from-1][to-1]위치에 1 값을 넣어 변을 표시한다. 동시에 to 값의 vertex의 indegree를 1 늘려준다. 세팅완료.
* 
* 모든 꼭짓점이 프린트되는게 목표니, printcount를 0부터 시작해 프린트되면 1씩 늘리고, printCount값이 v값과 동일해지면 루프를 종료한다.
* 내부에서 일단 i기준 v값까지 루프, 꼭짓점 i의 indegree가 0이면 프린트및 gotPrinted 변경, printCount도 1 늘린다.
* 만약 조건이 만족되어 i가 프린트 되었다면, j기준 v까지 루프하여 연결되었던 변들 타노스시키기 시작. indegree[j] && i != j && !gotPrinted[j]면 조건충족이다. 
* 이때도 printcount와 gotprinted 값 업데이트를 하도록 한다.
*
* 
*/
using namespace std;
int inDegree[100];
int graph[100][100];
int gotPrinted[100];


int main() {
	memset(inDegree, 0, sizeof(inDegree));
	memset(graph, 0, sizeof(graph));
	memset(gotPrinted, 0, sizeof(gotPrinted));
	int v, a, printCount = 0;
	cin >> v >> a;
	for (int i = 0; i < a; i++) {
		int from, to;
		cin >> from >> to;
		inDegree[to - 1]++;
		graph[from - 1][to - 1] = 1;

	}
	//int i = 0;
	while (printCount != v) {
		for (int i = 0; i < v; i++) {
			if (inDegree[i] == 0 && !gotPrinted[i]) {
				cout << "v" << i + 1 << " ";
				printCount++;
				gotPrinted[i] = 1;
			}
			if (gotPrinted[i]) {
				for (int j = 0; j < v; j++) {
					if (graph[i][j] == 1) {
						inDegree[j]--;
						if (inDegree[j] == 0 && j != i && !gotPrinted[j]) {
							cout << "v" << j + 1 << " ";
							printCount++;
							gotPrinted[j] = 1;
						}
					}

				}
			}
		}

	}

}
