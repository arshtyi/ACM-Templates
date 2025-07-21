struct SuffixAutomaton {
    struct Node {
        int next[26], link = -1, len = 0;
        Node() { fill(next, next + 26, -1); }
    };
    vector<Node> st;
    int last;
    SuffixAutomaton() { init(); }
    void init() {
        st.assign(1, Node());
        last = 0;
    }
    void extend(char ch) {
        int c = ch - 'a', cur = st.size();
        st.push_back(Node()), st[cur].len = st[last].len + 1;
        int p = last;
        while (p != -1 && st[p].next[c] == -1) st[p].next[c] = cur, p = st[p].link;
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int clone = st.size();
                st.push_back(st[q]), st[clone].len = st[p].len + 1;
                while (p != -1 && st[p].next[c] == q) st[p].next[c] = clone, p = st[p].link;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void build(const string& s) {
        init();
        for (char ch : s) extend(ch);
    }
    long long countDifferentSubstrings() const {
        long long res = 0;
        for (int i = 1; i < (int)st.size(); ++i) res += st[i].len - st[st[i].link].len;
        return res;
    }
};
