#include <vector>
#include <iostream>

using namespace std;

using pii = pair<int, int>;

class Solution {
    public:
        double e = 0.00001;
        double largestTriangleArea(vector<vector<int>>& points) {
            auto L = ssize(points);
            double res = 0;
            for (auto i = 0; i < L; i++) {
                for (auto j = i + 1; j < L; j++) {
                    for (auto k = j + 1; k < L; k++) {
                        pii pi = make_pair(points[i][0], points[i][1]);
                        pii pj = make_pair(points[j][0], points[j][1]);
                        pii pk = make_pair(points[k][0], points[k][1]);

                        auto totalS = getSquare(pi, pj, pk);
                        cout << i << " " << j << " " << k << " " << totalS << endl;
                        if (totalS < res) continue;

                        bool isValid = true;
                        for (auto l = 0; l < L; l++) {
                            if ((l == i) || (l == j) || (l == k)) continue;
                            pii pl = make_pair(points[l][0], points[l][1]);
                            cout << "index " << i << " " << j << " " << k << " " << l << endl;
                            auto ijl_S = getSquare(pi, pj, pl);
                            auto ikl_S = getSquare(pi, pk, pl);
                            auto jkl_S = getSquare(pj, pk, pl);
                            cout << ijl_S << " " << ikl_S << " " << jkl_S << endl;
                            if ((checkEqual(ijl_S, -1)) || checkEqual(ikl_S, -1) || checkEqual(jkl_S, -1)) {
                            } else if (checkEqual(ijl_S + ikl_S + jkl_S, totalS)) {
                                res = totalS; 
                            } else {
                                isValid = false;
                                break;
                            }
                        }
                        if (isValid) res = totalS;
                    }
                }
            }
            return res;
        }

        double getSquare(pii pi, pii pj, pii pk) {
            auto ij = sqrt((pj.first - pi.first) * (pj.first - pi.first) + (pj.second - pi.second) * (pj.second - pi.second));
            auto ik = sqrt((pk.first - pi.first) * (pk.first - pi.first) + (pk.second - pi.second) * (pk.second - pi.second));
            auto jk = sqrt((pj.first - pk.first) * (pj.first - pk.first) + (pj.second - pk.second) * (pj.second - pk.second));
            auto d = (ij + ik + jk) / 2;

            // if three points in the same line, return -1
            if (checkEqual(d, ij) || checkEqual(d, ik) || checkEqual(d, jk)) {
                return -1;
            }
            return sqrt(d * (d - ij) * (d - ik) * (d - jk));
        }

        bool checkEqual(double x, double y) {
            return (abs(x - y) <= e);
        }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> v = {{8,10},{2,7},{9,2},{4,10}};
    auto res = s.largestTriangleArea(v);
    cout << res;
}
