#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> c;
    multiset<int> s;
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capitals) {
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            c.push_back({capitals[i], profits[i]});
        }
        sort(c.begin(), c.end());
        int j = 0;
        while (k-- > 0) {
            while (j < n && c[j].first <= w) {
                s.insert(-1 * c[j].second);
                j += 1;
            }
            if (!s.empty()) {
                auto t = *s.begin();
                s.erase(s.begin());
                w = w + -1 * t;
            }
        }
        return w;
    }
};


int main() {
	return 0;
}
