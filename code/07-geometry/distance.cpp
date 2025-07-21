double dist(const Point& a, const Point& b) { return sqrt(dot(a - b, a - b)); }
double dist(const Line& l, const Point& p) { return abs(cross(l.b - l.a, p - l.a)) / dist(l.a, l.b); }
