vector<int> leftLess(n, -1);
stack<int> st;
for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    if (!st.empty()) leftLess[i] = st.top();
    st.push(i);
}
