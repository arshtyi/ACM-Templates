double angleX(const Point& a) { return atan2(a.y, a.x); }
Point rotate(Point a, double theta) {
    return Point(a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta));
}
Point rotateC(Point a, Point b, double theta) { return rotate(a - b, theta) + b; }
double angleX(const Line& l) { return angleX(l.b - l.a); }
