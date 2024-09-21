#include <bits/stdc++.h>
#define double long double
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;

		vector<double> arr(n);
		double average = 0;
		double sum = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			average += arr[i]; 
			sum += arr[i];
		}
		if(n == 1 || n == 2){
			cout<<"-1"<<endl;
			continue;
		}
		average /= (n*2);
		
		sort(arr.begin(), arr.end());
		
		if(n%2 == 0){
			int middle = n/2;
			if(arr[middle] >= average){
				long long x = arr[middle]*n*2.0 - sum;
			    cout<<x+1<<endl;
			}else{
				cout<<0<<endl;
			}
		}else{
			int middle = n/2;
			if(arr[middle] >= average){
				long long x = arr[middle]*n*2.0 - sum;
			    cout<<x+1<<endl;

			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}