#include <string>
#include <iostream>
#include <ranges>
#include <algorithm>

using namespace std;


class Solution {
    public:
        int compareVersion(string version1, string version2) {
            auto rangeV1 = version1 | views::split('.');
            auto rangeV2 = version2 | views::split('.');

            vector<string> splitV1;
            vector<string> splitV2;

            for (auto subRange: rangeV1) {
                splitV1.push_back(string(subRange.begin(), subRange.end()));
            }

            for (auto subRange: rangeV2) {
                splitV2.push_back(string(subRange.begin(), subRange.end()));
            }

            auto sizeV1 = ssize(splitV1);
            auto sizeV2 = ssize(splitV2);
            for (auto i = 0; i < max(sizeV1, sizeV2); i++) {
                auto v1 = 0, v2 = 0;
                if (i < sizeV1) {
                    v1 = stoi(splitV1[i]);
                }
                if (i < sizeV2) {
                    v2 = stoi(splitV2[i]);
                }

                if (v1 < v2) return -1;
                else if (v1 > v2) return 1;
            }
            return 0;
        }
};

int main() {
    Solution s = Solution();
    string version1 = "1.0";
    string version2 = "1.0.0.0";
    int  res = s.compareVersion(version1, version2);
    cout << res;
}
