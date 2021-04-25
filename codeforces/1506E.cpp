    #include <bits/stdc++.h>
    using namespace std;
     
    const int NMAX = 2e5 + 3;
    int a[NMAX], n, f[NMAX];
    set<int> se, new_se;
     
     
    void openf() {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }
     
    void process() {
        for (int i = 1; i <= n; i++)
            f[i] = 0;
        se.clear();
        new_se.clear();
        for (int i = 1; i <= n; i++)
            se.insert(i);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > cur) {
                f[i] = a[i];
                cur = a[i];
                se.erase(a[i]);
            }
        }
        for (auto x: se)
            new_se.insert(x);
     
        //find_min
        for (int i = 1; i <= n; i++) {
            if (f[i] == 0) {
                cout << *se.begin();
                se.erase(se.begin());
            }
            else cout << f[i];
            cout << " ";
        }
        cout << endl;
     
        //find_max
        for (int i = 1; i <= n; i++) {
            if (f[i] == 0) {
                auto it = new_se.lower_bound(a[i]);
                it--;
                cout << *it;
                new_se.erase(it);
            }
            else cout << f[i];
            cout << " ";
        }
        cout << endl;
    }
     
    int main() {
        //freopen("test.inp", "r", stdin);
        int test;
        cin >> test;
        while (test--) {
            openf();
            process();
        }
    }