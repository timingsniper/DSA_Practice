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
* dfs써야한다. 외워라 걍.
* 
* 
*
* 
*/
using namespace std;

char board[8][8];
int a[10];
int answer, counter;
int n, k;

void dfs(int current) {
	if (counter == k) { //체스 말 개수만큼 돌았다면
		answer++; //답의 값 1 늘리고 리턴
		return;
	}
	if (current >= n) { //current 값이 크기와 같거나 더 크다면
		return; //끗
	}
	for (int i = 0; i < n; i++) {
		if (!a[i] && board[current][i] == '#') { //a[i]값 0에 이 자리가 비어있다면
			a[i] = 1;
			counter++; //a[i]값 업데이트 후 이 자리에 체스 말을 놔보자.
			dfs(current + 1); //이상태로 담줄도 보자
			a[i] = 0; //비우기
			counter--; //이번줄 마무리
		}
	}
	dfs(current + 1); //이번 줄 검색 끝, 다음줄로
}

int main() {
	
	while (cin >> n >> k) {
		if (n == -1 && k == -1) {
			break;
		}
		getchar();
		counter = 0; answer = 0;
		for (int i = 0; i < n; i++) {
			cin >> board[i];
		}
		dfs(0);
		cout << answer << endl;
	}

}
