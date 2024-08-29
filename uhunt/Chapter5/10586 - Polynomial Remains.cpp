#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    stringstream output;
    while (cin >> n >> k) {
        if (n == -1 && k == -1) {
            break;
        }
        vector<int> arr(n + 1);
        for (int i = 0; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = n; i >= k; i--) {
            if (arr[i] != 0) {
                arr[i - k] -= arr[i];  //reducir con el coef*1
                arr[i] = 0;  // Se elimina el término de grado mayor....
            }
        }

        int maxIndex = 0;
        for (int i = n; i >= 0; i--) {
            if (arr[i] != 0) {
                maxIndex = i;
                break;
            }
        }

        for (int i = 0; i <= maxIndex; i++) {
            output << arr[i];
            if (i<maxIndex) {
                output << " ";
            }
        }
        output << endl;	
    }

    cout << output.str();
    return 0;
}
