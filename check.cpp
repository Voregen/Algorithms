#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream A("output.txt");
    ifstream B("out.txt");

    vector < string > v1, v2;
    string s;
    while (A >> s) v1.push_back(s);
    while (B >> s) v2.push_back(s);

    if ((int)v1.size() != (int)v2.size()) return 1;

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            cerr << i + 1 << " token = " << v1[i] << " | " << v2[i] << endl;
            return 1;
        }
    }
    return 0;
}
