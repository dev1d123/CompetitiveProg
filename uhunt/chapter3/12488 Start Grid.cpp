#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	while(cin>>n){
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		for(int i = 0; i < n; i++){
			cin>>b[i];
		}
		int ans = 0;
		
		for(int i = n-1; i >= 0; i--){
			if(b[i] == a[i]){
				//no hacer nada
			}else{
				int indexB = i;
				int indexA;
				for(int j = 0; j < n; j++){
					if(a[j] == b[i]){
						indexA = j;
						break;
					}
				}	
				if(indexB > indexA){
					//este elemento ha superado a los demas....hacer swaps para igualarlo
					int pos = abs(indexB - indexA);
					int c = 0;
					while(pos--){
						swap(a[indexA + c], a[indexA + c + 1]);
						c++;
						ans++;
					}
				}else{
					//ha sido superado
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}