struct AhoCorasick {
    struct Node {
        int next[26], fail = 0, cnt = 0;
        Node() { fill(next, next + 26, 0); }
    };
    vector<Node> tr = vector<Node>(1);
    void insert(const string& s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!tr[u].next[c]) tr[u].next[c] = tr.size(), tr.emplace_back();
            u = tr[u].next[c];
        }
        tr[u].cnt++;
    }
    void build() {
        queue<int> q;
        for (int c = 0; c < 26; ++c)
            if (tr[0].next[c]) q.push(tr[0].next[c]);
        while (!q.empty()) {
            int u = q.front();
            q.pop(), tr[u].cnt += tr[tr[u].fail].cnt;
            for (int c = 0; c < 26; ++c) {
                int v = tr[u].next[c];
                if (v) tr[v].fail = tr[tr[u].fail].next[c], q.push(v);
                else tr[u].next[c] = tr[tr[u].fail].next[c];
            }
        }
    }
    int query(const string& s) const {
        int u = 0, res = 0;
        for (char ch : s) u = tr[u].next[ch - 'a'], res += tr[u].cnt;
        return res;
    }
};
