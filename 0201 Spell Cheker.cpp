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
using namespace std;

bool isSame(string a, string b)
{
	char drop;
	//a短
	int mi = min(a.length(), b.length());
	string a1 = a; string b1 = b;
	sort(a1.begin(), a1.end());
	sort(b1.begin(), b1.end());
	bool exis = false;
	for (int i = 0; i < mi; i++)
	{
		//사용할 예시: a = mre, b = more
		if (a1[i] != b1[i]) //a1과 b1 글자 동일여부 확인 (ex m == m)
		{
			drop = b1[i]; //ex) drop = o
			exis = true;
			break;
		}
	}

	if (!exis) //다른 글자가 없음
	{
		drop = b1[b1.length() - 1]; //그럼 마지막글자 하나만 다른거죠?
		//ex) drop = y
	}
	string ti; bool ex = false;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i]) //다시 확인
		{
			ex = true; //ex) i = 1
			ti = a.substr(0, i);  //ti = m
			ti = ti + drop; //ti = mo
			ti = ti + a.substr(i, 1000); //ti = more
			break;
		}
		//예시의경우 그냥 루프 통과
	}
	if (!ex) //ex case
	{
		ti = a + drop; //ti = m+y
	}
	if (ti != b)
	{
		return false;
	}
	else {
		return true;
	}
}

int main() {
	string dictionary[10000];
	string target[50];
	string a, b;
	int dicCount = 0; int tarCount = 0;

	while (1) {
		cin >> a;
		if (a == "#") {
			break;
		}
		else {
			dictionary[dicCount++] = a;
		}
	}
	while (1) {
		cin >> b;
		if (b == "#") {
			break;
		}
		else {
			target[tarCount++] = b;
		}
	}


	//체크시작.
	/*
	체크해야할 경우들:
	1. 그냥 dic에 완전히 똑같은 단어가 있을경우. 찾으면 종료
	2-1. 단어 길이수에 차이가 없음. 글자 하나를 바꿨는데 같을 경우. 찾으면 종료.
	2-2. 단어 길이수가 1 차이남. 이경우 isSame 활용.

	*/
	for (int i = 0; i < tarCount; i++) { //big loop, 타켓들 처음부터 돌려보기
		bool sameFound = false;
		//1번 케이스
		for (int j = 0; j < dicCount; j++) {
			if (dictionary[j] == target[i])
			{
				cout << target[i] << " is correct" << endl;
				sameFound = true;
				break;
			}
		} //checking for identical words

		if (!sameFound) { //못찾음, 2-1과 2-2 검증시작
			cout << target[i] << ": ";
			for (int j = 0; j < dicCount; j++) { //dic의 단어들 루프시작
				int lenDiff = target[i].length() - dictionary[j].length();

				if (lenDiff == 0) { //2-1케이스 검증시작
					for (int k = 0; k < target[i].length(); k++) {
						if (target[i][k] != dictionary[j][k]) {
							string tishen = target[i];
							tishen[k] = dictionary[j][k];
							if (tishen == dictionary[j]) {
								cout << dictionary[j] << " ";
							}
						}
					}
				}

				if (abs(lenDiff) == 1)
				{
					if (target[i].length() > dictionary[j].length())
					{
						if (isSame(dictionary[j], target[i]))
						{
							cout << dictionary[j] << " ";
						}
					}
					else
					{
						if (isSame(target[i], dictionary[j]))
						{
							cout << dictionary[j] << " ";
						}
					}
				}
			}
			cout << endl;

		}
	}
	system("pause");
}
