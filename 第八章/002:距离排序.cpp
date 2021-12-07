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
#include <stack>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;
int n;

struct point{
	int xP, yP, zP;
	int inputOrder;
	//point(int x, int y, int z): xP(x), yP(y), zP(z){};
}points[10];

struct distance{
	double distVal; point firstP; point secondP;
	friend bool operator<(const distance a, const distance b){
		if(a.distVal != b.distVal){
			return a.distVal > b.distVal;
		}
		else if(a.distVal == b.distVal){
			if(a.firstP.inputOrder!= b.firstP.inputOrder){
				return a.firstP.inputOrder < b.firstP.inputOrder;
			}
			else{
				return a.secondP.inputOrder < b.secondP.inputOrder;
			}
		}
		
			//return a.firstP.inputOrder < b.firstP.inputOrder && a.secondP.inputOrder < b.secondP.inputOrder;
	}
}distances[50];

double getDistance(point a, point b){
	int xV = pow(a.xP-b.xP, 2.0);
	int yV = pow(a.yP-b.yP, 2.0);
	int zV = pow(a.zP-b.zP, 2.0);
	return sqrt(xV+yV+zV);
}

int main(){
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> points[i].xP >> points[i].yP >> points[i].zP; 
		points[i].inputOrder = i;
	}
	int distCount = 0;
	for(int i = 0; i<n-1; i++){
		for(int j = i+1; j<n; j++){
			distances[distCount].firstP = points[i];
			distances[distCount].secondP = points[j];
			distances[distCount].distVal = getDistance(points[i], points[j]);
			distCount++;
		}
	}	
	
	sort(distances, distances+distCount);
	for (int i = 0; i < distCount; i++) {
        cout << "(" << distances[i].firstP.xP << "," <<
            distances[i].firstP.yP << "," << distances[i].firstP.zP
            << ")-(" << distances[i].secondP.xP << "," <<
            distances[i].secondP.yP << "," << distances[i].secondP.zP
            << ")=" << fixed << setprecision(2) << distances[i].distVal
            << endl;
    }
}










