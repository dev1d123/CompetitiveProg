#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin>>t;
	int c = 1;
	stringstream output;
	while(t--){
		int n; cin>>n;
		int res = ((n-1)*n);
		output<<"Case "<<c<<": ";
		if(res%4 == 0){
			output<<res/4<<endl;
		}else if(res%2 == 0){
			output<<res/2<<"/"<<2<<endl;
		}else{
			output<<res<<"/"<<2<<endl;
		}
		c++;
		
	}
	cout<<output.str();
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int findSwaps(int n, int a[]) {
    int count = 0, temp;
    int b[100000]; 
    
    for (int i = 0; i < n; i++) {
        b[i] = a[i];  
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5,6,7,8,9}; 
    int n = sizeof(arr); 
    
    sort(arr, arr + n);
    map<int, int> waos;
    do {
		for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << " - Swaps: " << findSwaps(n, arr) << endl;

		waos[findSwaps(n, arr)]++;
    } while (next_permutation(arr, arr + n));  
    
    for(auto pair: waos){
    	cout<<pair.first<<", "<<pair.second<<endl;	
	}
    return 0;
}

*/