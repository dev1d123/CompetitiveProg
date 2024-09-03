#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	stringstream output;
	while(t--){
		int m,n,q;
		cin>>m>>n>>q;
		vector<string> arr(m);
		for(int i = 0; i < m; i++){
			cin>>arr[i];
		}
		
		vector<int> res(q);
		for(int i = 0; i < q; i++){
			int a, b;
			cin>>a>>b;
			
			char c = arr[a][b];
			int ans = 0;
			for(int i = 0; ; i++){
				int initX = a - i;
				int initY = b - i;
				//im tired
				if(initX < 0 || initY < 0){
					break;
				}
				bool quit = false;
				for(int s = initX; s < initX + i*2+1; s++){
					if(s >= m) {
						quit = true;
						break;
					}
					for(int p = initY; p < initY + i*2+1; p++){
						if(p >= n) {
							quit = true;
							break;
						}
						if(arr[s][p] != c){
							quit = true;
							break;
						}
					}
					if(quit) break;
				}
				if(quit) break;			
				ans++;
			}
			res[i] = ans*2 - 1;
		}
		output<<m<<" "<<n<<" "<<q<<endl;
		for(int n: res){
			output<<n<<endl;
		}
	}
	cout<<output.str();
	
	
	
	return 0;
}