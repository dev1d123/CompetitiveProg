#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> unique_chars(s.begin(), s.end());
        vector<char> arr(unique_chars.begin(), unique_chars.end());
        map<char, char> tr;
        int len = arr.size();
        for (int i = 0; i < len / 2; ++i) {
            tr[arr[i]] = arr[len - i - 1];
            tr[arr[len - i - 1]] = arr[i];
        }
        if (len % 2 == 1) {
            tr[arr[len / 2]] = arr[len / 2];
        }
        for (char c : s) {
            cout << tr[c];
        }
        cout << endl;
    }

    return 0;
}
