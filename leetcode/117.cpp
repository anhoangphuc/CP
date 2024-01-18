#include <iostream>
using namespace std;

class Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(): val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val): val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next): val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    public:
        vector<Node*> flattenNode {};
        vector<int> nodeHeight {};
        Node* connect(Node* root) {
                if (root == NULL) return NULL;
                flattenNode.push_back(root);
                nodeHeight.push_back(0);
                flatten();
                for (int i = 0; i < flattenNode.size() - 1; i++) {
                    if (nodeHeight[i] == nodeHeight[i + 1]) 
                        flattenNode[i]->next = flattenNode[i + 1];
                }
                return root;
        }
        void flatten() {
            int i = 0;
            while (i < flattenNode.size()) {
                Node* curNode = flattenNode[i];
                if (curNode->left != NULL) {
                    flattenNode.push_back(curNode->left);
                    nodeHeight.push_back(nodeHeight[i] + 1);
                }
                if (curNode->right != NULL) {
                    flattenNode.push_back(curNode->right);
                    nodeHeight.push_back(nodeHeight[i] + 1);
                }
                i++;
            }
        }
}
