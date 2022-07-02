#include <vector>
#include <set>
#include <iostream>
using namespace std;


class Solution {
public:
    bool solved = false;
    void solveSudoku(vector<vector<char>>& board) {
        trySolveACell(board, 0, 0);
    }

private:
    vector<pair<int, int>> get_list_relative_cell(pair<int, int> cell) {
        vector<pair<int, int>> res = {};
        for (int i = 0; i < 9; i++) {
            res.push_back(make_pair(i, cell.second));
            res.push_back(make_pair(cell.first, i));
            res.push_back(make_pair(cell.first / 3 * 3 + i / 3, cell.second / 3 * 3 + i % 3));
        }
        return res;
    }

    pair<int, int> getNextCell(int i, int j) {
        if (i == 8 && j == 8) return make_pair(-1 , -1);
        if (j != 8) return make_pair(i, j + 1);
        else return make_pair(i + 1, 0);
    }

    void trySolveACell(vector<vector<char>>& board, int i, int j) {
        if (solved) return;
        if (i == -1) {
            solved = true;
            return;
        }
        bool isSet = board[i][j] != '.';
        set<char> available_value = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        if (!isSet) {
            for (auto p: get_list_relative_cell(make_pair(i, j))) {
                available_value.erase(board[p.first][p.second]);
            }
        } else {
            available_value = { board[i][j] };
        }
        if (available_value.size() > 0) {
            for (auto value: available_value) {
                if (solved) return;
                board[i][j] = value;
                auto nextCell = getNextCell(i, j);
                trySolveACell(board, nextCell.first, nextCell.second);
                if (!isSet && !solved) board[i][j] = '.';
            }
        }
    }
};
