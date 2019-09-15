#include <bits/stdc++.h>
using namespace std;

map<string, int> mapCountry;
vector<vector<int>> visitedCountry;
bool isSorted[100005];

//----------------------------------------
int main() {
    int u, year, currentCountry = -1;
    string country;
    // freopen("test.inp", "r", stdin);
    cin >> u;
    while (u--) {
        cin >> country >> year;
        if (mapCountry.find(country) == mapCountry.end()) 
            mapCountry[country] = ++currentCountry;
        int indexCountry = mapCountry[country];
        if (indexCountry == currentCountry) 
            visitedCountry.push_back(vector<int>());
        visitedCountry[indexCountry].push_back(year);
    }

    cin >> u;
    while (u--) {
        cin >> country >> year;
        int indexCountry = mapCountry[country];
        if (isSorted[indexCountry] == false) {
            sort(visitedCountry[indexCountry].begin(), visitedCountry[indexCountry].end());
            isSorted[indexCountry] = true;
        }
        cout << visitedCountry[indexCountry][year - 1] << endl;
    }
}