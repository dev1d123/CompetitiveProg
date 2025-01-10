#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
		for (int i = n/2 - 1; i >= 0 ; i--) {
		    int j = n - i - 1;
		    if ((i + 1 < n && arr[i] == arr[i + 1]) || (j - 1 >= 0 && arr[j] == arr[j - 1])) {
		        swap(arr[i], arr[j]);
		    }
		}

		int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}

