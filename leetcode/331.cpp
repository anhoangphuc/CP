#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder = preorder + ",";
        auto pre = isValidHelper(preorder);
        // Return true and preoder must be empty
        return (pre == true && preorder == "");
    }
    bool isValidHelper(string& preorder) {
        if (preorder == "")
            return true;
        auto ind = preorder.find(",");
        auto sub = preorder.substr(0, ind);
        if (sub != "#") {
            // Non null
            // Eliminate root
            preorder.erase(preorder.begin(), preorder.begin() + ind + 1);
            // No left child, return false
            if (preorder == "") {
                return false;
            }
            // Check left tree build success
            auto res1 = isValidHelper(preorder);
            if (res1 == false)
                return false;
            // No right child, return false
            if (preorder == "") {
                return false;
            }
            // REturn result of right child
            return isValidHelper(preorder);
        } else {
            // Null
            // Skip vallue, return true
            preorder.erase(preorder.begin(), preorder.begin() + 2);
            return true;
        }
    }
};
