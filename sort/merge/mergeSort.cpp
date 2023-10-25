//
// Created by neepoo on 23-10-20.
//

#include <iostream>
#include <algorithm>

const int N = 1000010;
int n;
int a[N], tmp[N];

void mergeSort(int *q, int l, int r);

void mergeSort(int *q, int l, int r) {
    if (l >= r) { return; }
    int mid = l + r >> 1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);
    int k = 0;
    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = q[i++];
    }
    while (j <= r) {
        tmp[k++] = q[j++];
    }
    std::copy(tmp, tmp + k, q + l);
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}


