for (int s = mask; s; s = (s - 1) & mask) {
    // non-empty submask
}
for (int s = mask;; s = (s - 1) & mask) {
    // contains empty submask
    if (s == 0) break;
}
