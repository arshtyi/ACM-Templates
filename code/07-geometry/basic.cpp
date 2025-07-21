const double EPS = 1e-9;
int sgn(double x) { return (x > EPS) - (x < -EPS); }
int cmp(double a, double b) { return sgn(a - b); }
struct Point {
    double x, y;
    Point(double x = 0, double y = 0)
        : x(x)
        , y(y) {}
    Point operator+(const Point& p) const { return {x + p.x, y + p.y}; }
    Point operator-(const Point& p) const { return {x - p.x, y - p.y}; }
    Point operator*(double k) const { return {x * k, y * k}; }
    Point operator/(double k) const { return {x / k, y / k}; }
    bool operator<(const Point& p) const { return cmp(x, p.x) ? x < p.x : y < p.y; }
    bool operator==(const Point& p) const { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
};
struct Line {
    Point a, b;
};
