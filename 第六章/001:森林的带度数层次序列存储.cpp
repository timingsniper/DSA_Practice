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
* 매 노드마다 outdegree가 0보다 크면 그 수만큼 자식수 입력을 받는다. 
* if(outDegree)-> 이색기가 맞으면 당연히 자식이 잇는것이니 index에 애를 달고 큐에 넣는다.
* 
*
* 
*/
using namespace std;

struct leaf {
	char vert;
	int outDegree;
	leaf* child, *brother;
	leaf(){}
	leaf(char v, int o):vert(v), outDegree(o), child(NULL), brother(NULL){}

	leaf* addBrother(char v, int o) {
		if (!brother) {
			brother = new leaf(v, o);
			return brother;
		}
		else 
			return brother->addBrother(v, o);
	}
	leaf* addChild(char v, int o) {
		if (!child) {
			child = new leaf(v, o);
			return child;
		}
		else {
			return child->addBrother(v, o);
		}
	}

	void read() {
		if (child) {
			child->read();
		}
		cout << vert << " ";
		if (brother) {
			brother->read();
		}
	}
};

queue<leaf*> trees;

int main() {
	int n, outDegree;
	cin >> n;
	while (n--) {
		while (!trees.empty()) { //trees 초기화
			trees.pop();
		}
		char vertex;
		cin >> vertex >> outDegree; //루트 노드 입력 받아서 tree로 만들기
		leaf* tree = new leaf(vertex, outDegree);
		int printCount = outDegree;
		leaf* index = tree;
		while (!trees.empty() || printCount != 0) { //큐가 비어있지 않거나 카운트가 0이 아닐동안
			if (printCount == 0) { //마지막 단계라면
				index = trees.front(); //인덱스는 큐 맨 앞
				printCount = index->outDegree; //카운트는 이친구 자식 수로 리셋
				trees.pop(); //아웃
			}
			cin >> vertex >> outDegree;
			printCount--;
			if (outDegree != 0) {
				trees.push(index->addChild(vertex, outDegree));
			}
			else
				index->addChild(vertex, outDegree);
		}
		tree->read();
	}
	cout << endl;
}
