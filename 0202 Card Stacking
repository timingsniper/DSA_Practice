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
	//n = 플레이어 수 (베시포함)
	//k = 총 카드 수
	//p = 딜할때마다 밑장으로 뺄 카드 숫자
	int n, k, p = 0;
	cin >> n >> k >> p;
	//int goodCard = k / n;

	queue <int> deck;
	int goodCardList[maxn];
	int goodCardCount = 0;

	//int cardNum = 1;
	for (int i = 1; i <= k; i++) {
		deck.push(i); //1 2 3 4 5 6 7 8 9....
	}

	int dealCount = 1;
	while(!deck.empty()) { //start dealing
		//int cardDealtThisTurn;
		//cardDealtThisTurn = deck.front();
		if ((dealCount) % n == 0) {
			goodCardList[goodCardCount++] = deck.front();
			if (goodCardCount == k/n)
				break;
		}
		dealCount++;
		//cout << cardDealtThisTurn << endl;
		deck.pop();
		for (int j = 0; j < p; j++) {
			int toPutBack = deck.front();
			deck.push(toPutBack);
			deck.pop();
		}
	
		
	}

	sort(goodCardList, goodCardList+goodCardCount);
	for (int i = 0; i < goodCardCount; i++) {
		cout << goodCardList[i] << endl;
	}


}
