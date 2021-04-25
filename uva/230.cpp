#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;
typedef pair<string, string> pss;

set<pss> set_book_shelved;
set<pss> set_book_borrwed;
set<pss> set_book_returned;
map<string, string> m;

void openf() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    string s;
    while (getline(cin, s)) {
        if (s == "END")
            break;
        int ind = s.find('"', 1);
        m[s.substr(0, ind + 1)] = s.substr(ind + 4);
        set_book_shelved.insert(make_pair(s.substr(ind + 4), s.substr(0, ind + 1)));
    }
}

void process() {
    string s;
    while (getline(cin, s)) {
        if (s == "END") {
            return;
        }

        string book_name;
        pss book;
        if (s[0] != 'S') {
            book_name = s.substr(7);
            book = make_pair(m[book_name], book_name);
        }
        //Borrow
        if (s[0] == 'B') {
            set_book_shelved.erase(book);
            set_book_borrwed.insert(book);
        }
        //Return
        else if (s[0] == 'R') {
            set_book_borrwed.erase(book);
            set_book_returned.insert(book);
        } else {                //Shelve
            while (!set_book_returned.empty()) {
                book = *set_book_returned.begin();
                set_book_returned.erase(book);
                if (set_book_shelved.empty()) {
                    cout << "Put " << book.second << " first" << endl;
                } else {
                    auto before_book = set_book_shelved.lower_bound(book);
                    if (before_book == set_book_shelved.begin()) 
                        cout << "Put " << book.second << " first" << endl;
                    else 
                        cout << "Put " << book.second << " after " << (*(--before_book)).second << endl;
                }
                set_book_shelved.insert(book);
            }
            cout << "END" << endl;
        }
    }
}
int main() {
    openf();
    process();
}