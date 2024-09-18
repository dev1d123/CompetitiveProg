#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int limit) {
    vector<int> pr(limit + 1, 1);
    pr[0] = pr[1] = 0;
    for (int i = 2; i * i <= limit; i++) {
        if (pr[i]) {
            for (int j = i * i; j <= limit; j += i) {
                pr[j] = 0;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (pr[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    int limit = sqrt(INT_MAX);
    vector<int> primes = sieve(limit);
    int n;
    stringstream output;

    while (cin>>n) {
        if (n == 0) break;

        int total = n;
        vector<int> ans;

        if (n<0) {
            n *= -1;
        }

        for (int i : primes) {
            while (n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }
        //Si hay un primo que no se evaluo....
        if (n>1) {
            ans.push_back(n);
        }
        output << total << " = ";
        if (total < 0) {
            output << "-1 x ";
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i != ans.size() - 1) {
                output << ans[i] << " x ";
            } else {
                output << ans[i];
            }
        }
        output << endl;
    }
    cout << output.str();
    return 0;
}