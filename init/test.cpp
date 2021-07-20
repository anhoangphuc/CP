#include <bits/stdc++.h>
using namespace std;

void debug_quicksort(vector<int>& a, int l, int r) {
    int i = l, j = r - 1;
    if (i >= j) return;
    // cout << "arr: ";
    // for (auto x: a)
    //     cout << x << " ";
    // cout << endl;
    // cout << l << " " << r << endl;
    int pivot = a[(l + r) / 2];
    while (i < j) {
        while (i < r && a[i] < pivot) i++;
        while (j >= l && a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    // cout << j << " " << i << endl;
    // cout << "After swap:" << endl;
    // for (auto x: a)
    //     cout << x << " ";
    // cout << endl;
    debug_quicksort(a, l, j + 1);
    debug_quicksort(a, i, r);
}

int main() {
    cout << (-6 % 5);
}
