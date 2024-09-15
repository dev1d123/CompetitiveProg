#include <bits/stdc++.h>
#define int long long
using namespace std;

int calculate(int n, int b1, int b2, int d) {
    if (b1 == -1) {
        if (d < b2) {
            int dist = abs(d - 1);
            return dist + abs(d - b2);
        } else {
            int dist = abs(n - d);
            return dist + abs(d - b2);
        }
    } else if (b2 == -1) {
        if (d < b1) {
            int dist = abs(d - 1);
            return dist + abs(d - b1);
        } else {
            int dist = abs(n - d);
            return dist + abs(d - b1);
        }
    } else {
        int a = max(b1, b2);
        int b = min(b1, b2);

        if (b < d && d < a) {
            if (d - b == a - d) {
                return a - d;
            } else {
                int dist1 = d - b;
                int dist2 = a - d;
                int minim = min(dist1, dist2);
                int maxim = max(dist1, dist2);
                return minim + (maxim - minim) / 2;
            }
        } else {
            if (b1 < d && b2 < d) {
                int dist = abs(d - n);
                return dist + min(abs(d - b1), abs(d - b2));
            } else {
                int dist = abs(d - 1);
                return dist + min(abs(d - b1), abs(d - b2));
            }
        }
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> b(m);

        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        while (q--) {
            int d;
            cin >> d;

            auto it_left = lower_bound(b.begin(), b.end(), d);
            int profLeft = (it_left == b.begin()) ? -1 : *(--it_left);

            auto it_right = upper_bound(b.begin(), b.end(), d);
            int profRight = (it_right == b.end()) ? -1 : *it_right;

            cout << calculate(n, profLeft, profRight, d) << endl;
        }
    }

    return 0;
}
