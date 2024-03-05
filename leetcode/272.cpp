#include <iostream>
#include <set>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
class Solution {
public:
    struct Cmp {
        Cmp(double k): k(k) {}
        double k;
        bool operator() (int x, int y) const {
            if (abs(x - k) != abs(y - k))
                return abs(x - k) > abs(y - k);
            else return x > y;
        }
    };

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        auto cmp = Cmp(target);
        multiset<int, Cmp> s(cmp);
        dfs(root, k, s);
        vector<int> v;
        copy(s.begin(), s.end(), back_inserter(v));
        return v;
    }

    void dfs(TreeNode* root, int k, multiset<int, Cmp>& s) {
        if (root == NULL)
            return;
        s.insert(root->val);
        if (s.size() > k)
            s.erase(s.begin());
        dfs(root->left, k, s);
        dfs(root->right, k, s);
    }
};
