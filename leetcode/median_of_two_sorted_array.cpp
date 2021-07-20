#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;


class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            
            int t1 = trunc(ceil((m + n) / 2.0)) - 1;
            int t2 = trunc(ceil((m + n + 1) / 2.0)) - 1;
            int u1 = findSpecificPosition(nums1, nums2, t1);
            int v1 = findSpecificPosition(nums1, nums2, t2);
            cout << t1 << " " << u1 << endl;
            cout << t2 << " " << v1 << endl;
            return (u1 + v1) / 2.0;
        }

    private:
        int findSpecificPosition(vector<int>& nums1, vector<int>& nums2, int t) {
            // Force nums1.size() must smaller than nums2.size()
            if (nums1.size() > nums2.size()) 
                swap(nums1, nums2);

            int i1 = 0, j1 = nums1.size() - 1;

            while (i1 <= j1) {
                int mid = (i1 + j1 / 2);
                if (mid > t) {
                    j1 = mid;
                    continue;
                }
                int ind = (t - mid) - 1;
                if (nums1[mid] <= nums2[ind + 1]) {
                    if (ind < 0 || nums1[mid] >= nums2[ind])
                        return nums1[mid];
                    else {
                        i1 = mid + 1;
                        continue;
                    }
                }

                if (nums1[mid] >= nums2[ind + 1]) {
                    if (mid <= 0 || nums2[ind + 1] >= nums1[mid - 1])
                        return nums2[ind + 1];
                    else{
                        j1 = mid - 1;
                        continue;
                    }
                }
            }
            return nums2[t];
        }

};

int main() {
    freopen("test.inp", "r", stdin);
    vector<int> nums1;
    vector<int> nums2;
    int m, n, u;

    cin >> m >> n;
    rep(i, 0, m, 1) {
        cin >> u;
        nums1.push_back(u);
    }
    rep(i, 0, n, 1) {
        cin >> u;
        nums2.push_back(u);
    }
    
    for (auto x : nums1)
        cout << x << " ";
    cout << endl;
    for (auto x: nums2) 
        cout << x << " ";
    cout << endl;
    Solution a = Solution();
    cout << a.findMedianSortedArrays(nums1, nums2);
}
