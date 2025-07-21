void quickSort(vector<int>& a, int l, int r) {
    int i = l, j = r, pivot = a[l + ((r - l) >> 1)];
    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) swap(a[i++], a[j--]);
    } while (i <= j);
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}
