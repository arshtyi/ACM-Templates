long long mergeSort(int l, int r) {
    if (l >= r) return 0;
    int mid = l + ((r - l) >> 1);
    long long inv = mergeSort(l, mid) + mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++], inv += mid - i + 1;
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int p = l; p <= r; ++p) a[p] = tmp[p];
    return inv;
}
