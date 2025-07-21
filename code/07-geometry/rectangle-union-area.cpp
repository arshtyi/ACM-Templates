struct RectangleUnionArea {
    struct Event {
        int x, y1, y2, type;
        bool operator<(const Event& e) const { return x < e.x; }
    };
    struct Node {
        int cover = 0;
        long long len = 0;
    };
    vector<int> ys;
    vector<Node> tree;
    void pushup(int x, int l, int r) {
        if (tree[x].cover) tree[x].len = ys[r + 1] - ys[l];
        else if (l == r) tree[x].len = 0;
        else tree[x].len = tree[x << 1].len + tree[x << 1 | 1].len;
    }
    void add(int x, int l, int r, int ql, int qr, int v) {
        if (ql <= l && r <= qr) return tree[x].cover += v, pushup(x, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) add(x << 1, l, mid, ql, qr, v);
        if (qr > mid) add(x << 1 | 1, mid + 1, r, ql, qr, v);
        pushup(x, l, r);
    }
    long long solve(const vector<array<int, 4>>& rects) {
        vector<Event> events;
        ys.clear();
        for (auto [x1, y1, x2, y2] : rects) {
            if (x1 == x2 || y1 == y2) continue;
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            events.push_back({x1, y1, y2, 1}), events.push_back({x2, y1, y2, -1});
            ys.push_back(y1), ys.push_back(y2);
        }
        if (events.empty()) return 0;
        sort(events.begin(), events.end());
        sort(ys.begin(), ys.end()), ys.erase(unique(ys.begin(), ys.end()), ys.end());
        tree.assign(ys.size() * 4, Node());
        long long ans = 0;
        int last = events[0].x;
        for (auto e : events) {
            ans += tree[1].len * (e.x - last);
            int l = lower_bound(ys.begin(), ys.end(), e.y1) - ys.begin();
            int r = lower_bound(ys.begin(), ys.end(), e.y2) - ys.begin() - 1;
            if (l <= r) add(1, 0, ys.size() - 2, l, r, e.type);
            last = e.x;
        }
        return ans;
    }
};
