#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

double areaOfTriangle(Point A, Point B, Point C) {
    return std::abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0;
}

int orientation(Point A, Point B, Point C) {
    int val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void quickHull(std::vector<Point> &points, Point P, Point Q, int side, std::vector<Point> &hull) {
    int maxIdx = -1;
    double maxArea = -1.0;
    for (int i = 0; i < points.size(); ++i) {
        double area = areaOfTriangle(P, Q, points[i]);
        if (orientation(P, Q, points[i]) == side && area > maxArea) {
            maxArea = area;
            maxIdx = i;
        }
    }
    if (maxIdx == -1) {
        hull.push_back(P);
        hull.push_back(Q);
        return;
    }
    quickHull(points, points[maxIdx], P, -orientation(points[maxIdx], P, Q), hull);
    quickHull(points, points[maxIdx], Q, -orientation(points[maxIdx], Q, P), hull);
}

std::vector<Point> findConvexHull(std::vector<Point> &points) {
    std::vector<Point> hull;
    if (points.size() < 3) return hull;
    int minX = 0, maxX = 0;
    for (int i = 1; i < points.size(); ++i) {
        if (points[i].x < points[minX].x) minX = i;
        if (points[i].x > points[maxX].x) maxX = i;
    }
    quickHull(points, points[minX], points[maxX], 1, hull);
    quickHull(points, points[minX], points[maxX], -1, hull);
    return hull;
}

int main() {
    std::vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    std::vector<Point> hull = findConvexHull(points);
    std::cout << "Convex Hull Points:\n";
    for (auto &point : hull) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }
    return 0;
}
