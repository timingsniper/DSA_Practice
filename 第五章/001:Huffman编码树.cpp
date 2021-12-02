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

int n, ans, x;
int main(){
    int t;
    cin >> t;
    while(t--) {
        priority_queue<int, vector<int>, greater<int>>tree;
        int element;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> element;
            tree.push(element);
        }
        int ans = 0;
        for (int i = 1; i <= n-1; i++) {
            int sum = 0;
            sum += tree.top();
            tree.pop();
            sum += tree.top();
            tree.pop();
            ans += sum;
            tree.push(sum);
        }
        cout << ans << endl;


    }

}
