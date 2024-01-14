#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());

        int maxValueFromLeft = 0;
        for (int i = 0; i < height.size(); i++) {
            maxValueFromLeft = max(maxValueFromLeft, height[i]);
            left[i] = maxValueFromLeft;
        }

        int maxValueFromRight = 0;
        //Use int instead auto type, because i become size_type, and for-loop is incorrect
        for (int i = height.size() - 1; i >= 0; i--) {
            maxValueFromRight = max(maxValueFromRight, height[i]);
            right[i] = maxValueFromRight;
        }

        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};
