#include <vector>
using namespace std;
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        return verifyHelper(preorder, 0, preorder.size() - 1);
    }
    bool verifyHelper(const vector<int>& preorder, int left, int right) {
        if (left >= right)
            return true;
        auto pivot = right + 1;
        for (auto i = left + 1; i <= right; i++) {
            if (preorder[i] > preorder[left]) {
                if (pivot == right + 1) {
                    pivot = i;
                }
            } else {
                if (pivot != right + 1)
                    return false;
            }
        }
        return verifyHelper(preorder, left + 1, pivot - 1) &&
               verifyHelper(preorder, pivot, right);
    }
};
