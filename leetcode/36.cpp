#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
   bool isASetValid(vector<char>& s) {
        vector<int> filtered_s;
        copy_if(s.begin(), s.end(), back_inserter(filtered_s), [](char x) { return x != '.'; });
        sort(filtered_s.begin(), filtered_s.end());
        auto newSize = unique(filtered_s.begin(), filtered_s.end());
        return newSize == filtered_s.end();
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto i = 0; i < 9; i++) {
            vector<char> row;
            for (auto j = 0; j < 9; j++)
                row.push_back(board[i][j]);
            if (!isASetValid(row)) return false;

            vector<char> col;
            for (auto j = 0; j < 9; j++)
                col.push_back(board[j][i]);
            if (!isASetValid(col))  return false;

            vector<char> square;
            for (auto j = 0; j < 9; j++) {
                square.push_back(board[(i / 3 * 3) + (j / 3)][(i % 3 * 3) + (j % 3)]);
            }
            if (!isASetValid(square)) return false;
        }
        return true;
    }
};

int main() {
    vector<vector<char>> x {{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};

    Solution a = Solution();
    cout << a.isValidSudoku(x);
}
