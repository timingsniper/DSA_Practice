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

struct point {
    int xP, yP, zP;
}points[10];

struct distance {
    point firstPoint, secondPoint;
    double val;

}distances[100];

double getDistance(point a, point b) {
    double xDiff = pow(a.xP - b.xP, 2.0);
    double yDiff = pow(a.yP - b.yP, 2.0);
    double zDiff = pow(a.zP - b.zP, 2.0);
    return sqrt(xDiff + yDiff + zDiff);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].xP >> points[i].yP >> points[i].zP;
    }

    int distanceIndex = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            distances[distanceIndex].firstPoint = points[i];
            distances[distanceIndex].secondPoint = points[j];
            distances[distanceIndex].val = getDistance(points[i], points[j]);
            distanceIndex++;
        }
    }
    struct distance temp;
    for (int i = 0; i < distanceIndex; i++) {
        int flag = 1;
        for (int j = 0; j < distanceIndex - i; j++) {
            if (distances[j].val < distances[j + 1].val) {
                flag = 0;
                temp = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = temp;

            }
        }
        if (flag) {
            break;
        }
    }

    for (int i = 0; i < distanceIndex; i++) {
        cout << "(" << distances[i].firstPoint.xP << "," <<
            distances[i].firstPoint.yP << "," << distances[i].firstPoint.zP
            << ")-(" << distances[i].secondPoint.xP << "," <<
            distances[i].secondPoint.yP << "," << distances[i].secondPoint.zP
            << ")=" << fixed << setprecision(2) << distances[i].val
            << endl;
    }


}
