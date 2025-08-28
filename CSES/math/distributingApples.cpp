#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2000001; 

long long fact[MAXN+1], invfact[MAXN+1];

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}
long long inv(long long x) {
    return modpow(x, MOD-2);
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = (fact[i-1] * i) % MOD;
    invfact[MAXN] = inv(fact[MAXN]);
    for (int i = MAXN-1; i >= 0; i--) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
}

// C(n, k) mod MOD
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
    init();
    int n, m;
    cin>>n>>m;
    long long ans = 0;
    ans += C(n+m-1, n-1);

    cout << ans << "\n";
}

