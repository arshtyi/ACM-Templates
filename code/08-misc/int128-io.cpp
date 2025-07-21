ostream& operator<<(ostream& os, __int128 x) {
    if (x == 0) return os << '0';
    if (x < 0) os << '-', x = -x;
    string s;
    while (x) s.push_back('0' + x % 10), x /= 10;
    reverse(s.begin(), s.end());
    return os << s;
}
istream& operator>>(istream& is, __int128& x) {
    string s;
    is >> s;
    x = 0;
    int sign = 1, i = 0;
    if (s[0] == '-') sign = -1, i = 1;
    for (; i < (int)s.size(); ++i) x = x * 10 + s[i] - '0';
    x *= sign;
    return is;
}
