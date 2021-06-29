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
    freopen("test.out", "w", stdout);
    vector<int> a;
    vector<int> b;
    int cnt = 0;
    const int NUMBER_OF_TEST = 1000;
    const int LENGTH_OF_ARRAY = 1000;
    srand(time(NULL));
    cout << rand() % 1000000 << endl;
    for (int i = 1; i <= NUMBER_OF_TEST; i++) {
        a.clear();
        for (int j = 0; j < LENGTH_OF_ARRAY; j++)
            a.push_back(rand() % 10000);
        b.clear();
        b.insert(b.begin(), a.begin(), a.end());
        sort(b.begin(), b.end());
        debug_quicksort(a, 0, a.size());

        if (a != b) {
            for (auto x: a) 
                cout << x << " ";
            return 0;
        } else {
            cnt++;
        }
    }
    cout << cnt;
}
