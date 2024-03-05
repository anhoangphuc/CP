#include <vector>

using namespace std;

class Solution {
	public:
		bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
			int edge = 0;
			vector<bool> cantStart(n);
			for (int i = 0; i < n; i++) {
				edge += (leftChild[i] != -1);
				edge += (rightChild[i] != -1);
				if (leftChild[i] != -1) cantStart[leftChild[i]] = true;
				if (rightChild[i] != -1) cantStart[rightChild[i]] = true;
			}
			// Edge must equal to n - 1
			if (edge != n - 1) return false;

			int start = -1;
			for (auto i = 0; i < n; i++) {
				if (cantStart[i] == false) {
					start = i;
				}
			}
			vector<bool> isVisted(n);
			dfs(start, leftChild, rightChild, isVisted);
			return find(isVisted.begin(), isVisted.end(), false) == isVisted.end();
		}

		void dfs(int s, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& isVisted) {
			if (s == -1) return;
			if (isVisted[s] == true) return;
			isVisted[s] = true;
			dfs(leftChild[s], leftChild, rightChild, isVisted);
			dfs(rightChild[s], leftChild, rightChild, isVisted);
		}
};

int main() {
	return 0;
}
