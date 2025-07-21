vector<int> xs = a;
sort(xs.begin(), xs.end());
xs.erase(unique(xs.begin(), xs.end()), xs.end());
for (int& x : a) x = lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
