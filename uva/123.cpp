#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;

struct kwic_title {
    int row_num, pos_num;
    kwic_title(int row_num, int pos_num) {
        this -> row_num = row_num;
        this -> pos_num = pos_num;
    }
};
vector<string> titles[203];
vector<string> ignore_words;
int num_of_titles = -1;
vector<kwic_title> list_title;

void openf() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    bool isTitle = false;
    string s;
    while (getline(cin, s)) {
        if (s == "::") {
            isTitle = true;
            continue;
        }
        if (!isTitle) 
            ignore_words.push_back(s);
        else {
            num_of_titles++; 
            istringstream iss(s);
            string word;
            int pos_of_word = -1;
            while (iss >> word) {
                transform(word.begin(), word.end(), word.begin(), 
                    [](char c) { return tolower(c);});
                titles[num_of_titles].push_back(word);
                pos_of_word += 1;
                if (find(ignore_words.begin(), ignore_words.end(), word) == ignore_words.end()) {
                    list_title.push_back(kwic_title(num_of_titles, pos_of_word));
                }
            }
        }
    }
}

void process() {
    sort(list_title.begin(), list_title.end(), 
    [](kwic_title a, kwic_title b) {
        if (titles[a.row_num][a.pos_num] != titles[b.row_num][b.pos_num])
            return titles[a.row_num][a.pos_num] < titles[b.row_num][b.pos_num];
        return ((a.row_num < b.row_num) || (a.row_num == b.row_num && a.pos_num < b.pos_num));
    });

    for (auto title: list_title) {
        int row_num = title.row_num, pos_num = title.pos_num;
        vector<string> vs = titles[row_num];
        for (int i = 0; i < vs.size(); i++) {
            if (i != pos_num)
                cout << vs[i];
            else {
                transform(vs[i].begin(), vs[i].end(), vs[i].begin(),
                [](char ch) { return toupper(ch); });
                cout << vs[i];
            }
            if (i < vs.size() - 1) cout << " ";
        }
        cout << endl;
    }
}

int main() {
    openf();
    process();
}