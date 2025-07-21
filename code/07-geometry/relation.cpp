bool onSegment(const Point& p, const Line& l) {
    return sgn(cross(l.b - l.a, p - l.a)) == 0 && sgn(dot(p - l.a, p - l.b)) <= 0;
}
bool onLine(const Point& p, const Line& l) { return sgn(cross(l.b - l.a, p - l.a)) == 0; }
Point foot(const Point& p, const Line& l) {
    return l.a + (l.b - l.a) * dot(p - l.a, l.b - l.a) / dot(l.b - l.a, l.b - l.a);
}
Point reflect(const Point& p, const Line& l) { return foot(p, l) * 2 - p; }
bool parallel(const Line& l1, const Line& l2) { return sgn(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }
Point intersection(const Line& l1, const Line& l2) {
    return l1.a + (l1.b - l1.a) * cross(l2.b - l2.a, l2.a - l1.a) / cross(l2.b - l2.a, l1.b - l1.a);
}
bool segmentIntersect(const Line& l1, const Line& l2) {
    int d1 = sgn(cross(l2.b - l2.a, l1.a - l2.a)), d2 = sgn(cross(l2.b - l2.a, l1.b - l2.a));
    int d3 = sgn(cross(l1.b - l1.a, l2.a - l1.a)), d4 = sgn(cross(l1.b - l1.a, l2.b - l1.a));
    return (d1 * d2 < 0 && d3 * d4 < 0) || (d1 == 0 && onSegment(l1.a, l2)) || (d2 == 0 && onSegment(l1.b, l2)) ||
           (d3 == 0 && onSegment(l2.a, l1)) || (d4 == 0 && onSegment(l2.b, l1));
}
