#include <bits/stdc++.h>
using namespace std;


vector<int> pr(10001, 1);

int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == target) {
            return mid; 
        }else if (arr[mid] < target) {
            low = mid + 1; 
        }else {
            high = mid - 1; 
        }
    }
    
    return -1; 
}
vector<int> sieve(int m){
	pr[0] = 0;
	pr[1] = 0;
	for(int i = 2; i * i <= m; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= m; j+=i){
				pr[j] = 0;
			}
		}
	}
	vector<int> primes;
	for(int i = 0; i <= m; i++){
		if(pr[i] == 1) primes.push_back(i);
	}
	return primes;
}
int main(){
	vector<int> primes = sieve(10000);
	
	int n;
	vector<int> dp(10001);
	dp[0] = -1;
	dp[1] = 1;
	for(int i = 2; i < 10000; i++){
		if(pr[i] == 1) dp[i] = i;
		else dp[i] = dp[i-1];
	}
	while(cin>>n){
		if(n == 0) break;
		int index = binarySearch(primes, dp[n]);
		int suma = 0;
		int ans = 0;
		queue<int>q;
		for(int i = index; i >= 0; i--){
			suma += primes[i];
			q.push(primes[i]);
			if(suma == n){
				ans++;
				suma -= q.front();
				q.pop();
			}else if(suma > n){

				suma -= q.front();
				q.pop();

			}	
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
