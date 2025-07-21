struct BigInteger {
    static const int base = 1000000000, width = 9;
    vector<int> a;
    int sign = 1;
    BigInteger(long long v = 0) { *this = v; }
    BigInteger(const string& s) { read(s); }
    BigInteger& operator=(long long v) {
        sign = 1, a.clear();
        if (v < 0) sign = -1, v = -v;
        do a.push_back(v % base), v /= base; while (v);
        return *this;
    }
    void trim() {
        while (a.size() > 1 && a.back() == 0) a.pop_back();
        if (a.size() == 1 && a[0] == 0) sign = 1;
    }
    void read(string s) {
        sign = 1, a.clear();
        int pos = 0;
        if (s[0] == '-') sign = -1, pos = 1;
        for (int i = s.size(); i > pos; i -= width) {
            int x = 0;
            for (int j = max(pos, i - width); j < i; ++j) x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        if (a.empty()) a.push_back(0);
        trim();
    }
    string str() const {
        string s = sign < 0 ? "-" : "";
        s += to_string(a.back());
        for (int i = (int)a.size() - 2; i >= 0; --i) {
            string t = to_string(a[i]);
            s += string(width - t.size(), '0') + t;
        }
        return s;
    }
    static int cmpAbs(const BigInteger& x, const BigInteger& y) {
        if (x.a.size() != y.a.size()) return x.a.size() < y.a.size() ? -1 : 1;
        for (int i = (int)x.a.size() - 1; i >= 0; --i)
            if (x.a[i] != y.a[i]) return x.a[i] < y.a[i] ? -1 : 1;
        return 0;
    }
    friend bool operator<(const BigInteger& x, const BigInteger& y) {
        if (x.sign != y.sign) return x.sign < y.sign;
        int c = cmpAbs(x, y);
        return x.sign == 1 ? c < 0 : c > 0;
    }
    friend bool operator==(const BigInteger& x, const BigInteger& y) { return x.sign == y.sign && x.a == y.a; }
    static BigInteger addAbs(const BigInteger& x, const BigInteger& y) {
        BigInteger z;
        z.a.assign(max(x.a.size(), y.a.size()) + 1, 0);
        long long carry = 0;
        for (int i = 0; i < (int)z.a.size(); ++i) {
            long long cur = carry;
            if (i < (int)x.a.size()) cur += x.a[i];
            if (i < (int)y.a.size()) cur += y.a[i];
            z.a[i] = cur % base, carry = cur / base;
        }
        z.trim();
        return z;
    }
    static BigInteger subAbs(const BigInteger& x, const BigInteger& y) {
        BigInteger z;
        z.a.assign(x.a.size(), 0);
        long long carry = 0;
        for (int i = 0; i < (int)x.a.size(); ++i) {
            long long cur = x.a[i] - carry - (i < (int)y.a.size() ? y.a[i] : 0);
            if (cur < 0) cur += base, carry = 1;
            else carry = 0;
            z.a[i] = cur;
        }
        z.trim();
        return z;
    }
    friend BigInteger operator+(const BigInteger& x, const BigInteger& y) {
        if (x.sign == y.sign) {
            BigInteger z = addAbs(x, y);
            z.sign = x.sign;
            return z;
        }
        int c = cmpAbs(x, y);
        if (c == 0) return 0;
        BigInteger z = c > 0 ? subAbs(x, y) : subAbs(y, x);
        z.sign = c > 0 ? x.sign : y.sign;
        return z;
    }
    friend BigInteger operator-(BigInteger x, const BigInteger& y) {
        BigInteger z = y;
        z.sign = -z.sign;
        return x + z;
    }
    friend BigInteger operator*(const BigInteger& x, const BigInteger& y) {
        BigInteger z;
        z.sign = x.sign * y.sign;
        z.a.assign(x.a.size() + y.a.size(), 0);
        for (int i = 0; i < (int)x.a.size(); ++i) {
            long long carry = 0;
            for (int j = 0; j < (int)y.a.size() || carry; ++j) {
                long long cur = z.a[i + j] + carry + 1LL * x.a[i] * (j < (int)y.a.size() ? y.a[j] : 0);
                z.a[i + j] = cur % base, carry = cur / base;
            }
        }
        z.trim();
        return z;
    }
};
ostream& operator<<(ostream& os, const BigInteger& x) { return os << x.str(); }
