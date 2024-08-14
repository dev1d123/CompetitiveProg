#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minD = INT_MAX;
    int price = 0;

    for(int i = 0; i < n; i++) {
        int currentDiff = abs(arr[i] - k);
        if(currentDiff < minD) {
            minD = currentDiff;
            price = arr[i];
        }
    }
    cout << price << endl;

    return 0;
}
