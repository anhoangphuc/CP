#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)

char sudoku[12][12];
typedef pair<int, int> position;
//----------------------------------------
void openf() {
    //freopen("test.inp", "r", stdin);
    rep(i, 0, 8)
        rep(j, 0, 8) {
            cin >> sudoku[i][j];
		}
}
//----------------------------------------
int getSquare(int i, int j) {
    return i / 3 * 3 + j / 3;
}
//----------------------------------------
position getPosition(int value) {
    // initialize rows, cols, squares
    set<int> rows, cols, squares;
    vector<position> res;
    res.clear();
	rows.clear();
	cols.clear();
	squares.clear();

    rep(i, 0, 8) {
        rows.insert(i);
        cols.insert(i);
        squares.insert(i);
    }

    rep(i, 0, 8)
        rep(j, 0, 8)
            if (sudoku[i][j] == '0' + value) {
                if (rows.find(i) != rows.end()) 
                    rows.erase(i);
                else 
                    return position(-1, -1);

                if (cols.find(j) != cols.end())
                    cols.erase(j);
                else
                    return position(-1, -1);
                if (squares.find(getSquare(i, j)) != squares.end())
                    squares.erase(getSquare(i, j));
                else 
                    return position(-1, -1);
            }
	
	if (squares.empty()) 
		return position(-3, -3);
    
    for (auto square:squares) {
		res.clear();
        auto srow = square / 3;
        auto scol = square % 3;
        rep(i, srow * 3, srow * 3 + 2)
            rep(j, scol * 3, scol * 3 + 2) {
                if (rows.find(i) != rows.end() && cols.find(j) != cols.end() && sudoku[i][j] == '.')
                    res.push_back(position(i, j));
            }
        if (res.size() == 0)
            return position(-1, -1);
        else if (res.size() == 1)
            return res[0];
    } 
	return position(-2, -2);
}
//----------------------------------------
void write() {
	rep(i, 0, 8) {
		rep(j, 0, 8)
			cout << sudoku[i][j];
		cout << endl;
	}
}
//----------------------------------------
void process() {
	set<int> g;
	rep(i, 1, 9)
		g.insert(i);

    while (true) {
        bool stop = true;
		if (g.empty()) break;
        rep(i, 1, 9) {
			if (g.find(i) == g.end()) 
				continue;
            auto p = getPosition(i);
            if (p.first == -1) {
                cout << "ERROR";
                return;
            } else if (p.first == -3) {
				stop = false;
				g.erase(i);
			}
			else if (p.first != -2) {
                sudoku[p.first][p.second] = '0' + i;
                stop = false;
            }
        }
        if (stop) break;
    }

	write();
}
//----------------------------------------
int main() {
    openf();
    process();
}
