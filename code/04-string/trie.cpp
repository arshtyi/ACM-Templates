struct Trie {
    struct Node {
        array<int, 26> next;
        int cnt = 0, end = 0;
        Node() { next.fill(-1); }
    };
    vector<Node> tr;
    Trie() : tr(1) {}
    void insert(const string& s) {
        int u = 0;
        tr[u].cnt++;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].next[c] == -1) tr[u].next[c] = tr.size(), tr.emplace_back();
            u = tr[u].next[c], tr[u].cnt++;
        }
        tr[u].end++;
    }
    int countWord(const string& s) const {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].next[c] == -1) return 0;
            u = tr[u].next[c];
        }
        return tr[u].end;
    }
    int countPrefix(const string& s) const {
        int u = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (tr[u].next[c] == -1) return 0;
            u = tr[u].next[c];
        }
        return tr[u].cnt;
    }
};
