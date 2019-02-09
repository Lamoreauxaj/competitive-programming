#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct point {
	double x, y;
	point() { x = y = 0; }
	point(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

struct line {
	double a, b, c;
	line() { a = b = c = 0; }
	line(point p1, point p2) {
		if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
			a = 1.0; b = 0.0; c = -p1.x; // default values
		} else {
			a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
			b = 1.0; // IMPORTANT: we fix the value of b to 1.0
			c = -(double)(a * p1.x) - p1.y;
		}
	}
};

struct line_segment {
	line l;
	point a, b;
	line_segment(point p1, point p2) {
		l = line(p1, p2);
		a = p1;
		b = p2;
	}
};

bool parallel(line l1, line l2) {
	return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool intersect(line l1, line l2, point& p) {
	if (parallel(l1, l2)) return false;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}

bool intersect(line_segment l1, line_segment l2) {
	point p;
	if (!intersect(l1, l2, p))
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("1.in", "r", stdin);



	return 0;
}
