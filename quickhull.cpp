#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


struct Points{
    int x;
    int y;
};

float areaOfTriangle(Point A, Point B, Point C) {
    return abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0;
}

int determinant(Point A, Point B, Point C) {
    int deter = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);
    if (deter == 0) return 0; // collinear
    return (deter > 0) ? 1 : 2; // left or right of line segment
}

void quickhull(vector<Points> &points, Point P,Point Q, int side,vector<Points> &hull){
    int maxidx=-1;
    float maxarea=-1.0;
    for(int i=0;i<points.size();++i){
        float area= areaOfTriangle(P,Q,points[i]);
    }
    if(determinant==side && area>maxarea){
        maxarea= area;
        maxidx=i;
    }
    if(maxidx==-1){
        hull.push_back(P);
        hull.push_back(Q);
        return;
    }

    quickhull(points,points[maxidx],P,determinant(points[maxidx],P,Q),hull);
    quickhull(points,points[maxidx],P,determinant(points[maxidx],Q,P),hull);
}

kn