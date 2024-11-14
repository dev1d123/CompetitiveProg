	#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n == 2){
			cout<<-1<<endl;
		}else{
			int arr[n][n];
			int num1 = 1;
			int num2 = n*n;
			int aux = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(aux%2 == 0){
						arr[i][j] = num1;
						num1++;
					}else{
						arr[i][j] = num2;
						num2--;
					}
					aux++;
				}
			}
			int temp = arr[0][0];
			arr[0][0] = arr[n-1][n-1];
			arr[n-1][n-1] = temp;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					cout<<arr[i][j]<<" "; 
				}
				cout<<endl;
			}
		}

	}
	return 0;
}