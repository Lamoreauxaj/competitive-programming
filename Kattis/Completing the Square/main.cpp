#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator - (const Point& other) const {
        return Point(x - other.x, y - other.y);
    }
    Point operator + (const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
    int operator * (const Point& other) const {
        return x * y + other.x * other.y;
    }
    int magSq() {
        return x * x + y * y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    Point cen, x, y;
    if ((c - a) * (b - a) == 0) {
        cen = a;
        x = b;
        y = c;
    }
    else if ((c - b) * (a - b) == 0) {
        cen = b;
        x = a;
        y = c;
    }
    else if ((a - c) * (b - c) == 0) {
        cen = c;
        x = a;
        y = b;
    }

    Point m = (x + y - cen);
    cout << m.x << " " << m.y << "\n";

    return 0;
}
