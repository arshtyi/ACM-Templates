deque<int> q;
vector<int> ans;
for (int i = 0; i < n; ++i) {
    while (!q.empty() && q.front() <= i - k) q.pop_front();
    while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
    q.push_back(i);
    if (i >= k - 1) ans.push_back(a[q.front()]);
}
