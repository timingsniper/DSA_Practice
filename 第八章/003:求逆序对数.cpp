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

int nums[20000];
int temp[20000];
int ans;

void merge(int begin, int mid, int end) {
	int i = begin, j = mid+1, k = begin;
	while (i <= mid && j <= end) {
		if (nums[i] > nums[j]) {
			temp[k] = nums[j];
			k++;
			j++;
			ans += mid - i + 1;
		}
		else {
			temp[k] = nums[i];
			k++;
			i++;
		}
	}
	while (i <= mid) {
		temp[k] = nums[i];
		k++;
		i++;
	}
	while (j <= end) {
		temp[k] = nums[j];
		k++;
		j++;
	}
	for (int p = begin; p <= end; p++) {
		nums[p] = temp[p];
	}

}

void mergeSort(int begin, int end) {
	if (begin >= end) {
		return;
	}
	int mid = (begin + end) / 2;
	mergeSort(begin, mid);
	mergeSort(mid + 1, end);
	merge(begin, mid, end);
}


int main() {
	int n;
	while(cin >> n){
		memset(nums, 0, sizeof(nums));
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		ans = 0;
		mergeSort(0, n - 1);

		cout << ans << endl;
	}
	

}
