#include <bits/stdc++.h>
using namespace std;

// point class
struct point {
    double x, y;
    point() {}
    point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    point operator + (const point& other) const {
        return point(x + other.x, y + other.y);
    }
    point operator - (const point& other) const {
        return point(x - other.x, y - other.y);
    }
    point operator * (double s) const {
        return point(x * s, y * s);
    }
};

// dot product of vector
double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

// squared norm of vector p
double norm(point p) {
    return p.x * p.x + p.y * p.y;
}

// dist between two points
double dist(point a, point b) {
    return sqrt(norm(b - a));
}

// return shortest dist from p to ab
double distToLine(point p, point a, point b, point& c) {
    point ap = p - a;
    point ab = b - a;
    double u = dot(ap, ab) / norm(ab);
    c = a + ab * u;
    return dist(p, c);
}

// relfect a over p1p2
point reflect(point a, point p1, point p2) {
    point i;
    distToLine(a, p1, p2, i);
    // cout << i.x << " " << i.y << "\n";
    return a + (i - a) + (i - a);
}

int N;
vector<point> poly;
point startp, endp;

int main() {
    
    // input
    cin >> N;
    poly.assign(N, point());
    for (int i = 0; i < N; i++)
        cin >> poly[i].x >> poly[i].y;
    cin >> endp.x >> endp.y >> startp.x >> startp.y;
    
    // reflect over each side
    for (int i = 0; i < N; i++) {
        point l = poly[i], r = poly[(i + 1) % N];
        for (int j = 0; j < N; j++)
            poly[j] = reflect(poly[j], l, r);
        endp = reflect(endp, l, r);
    }
    
    // calculate final angle of straight line
    point res = endp - startp;
    double ang = atan2(res.y, res.x);
    if (ang < 0) ang += 2*acos(-1);
    
    // output angle in degrees
    cout << fixed << setprecision(8) << ang * 180 / acos(-1) << "\n";
    
    return 0;
}
