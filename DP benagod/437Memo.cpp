#include <bits/stdc++.h>
using namespace std;


bool comp(const tuple<int, int, int> &t1, const tuple<int, int, int> &t2) {
    return (get<1>(t1) > get<1>(t2)) || (get<1>(t1) == get<1>(t2) && get<2>(t1) > get<2>(t2));
}

int main(){
	int n;
	int c = 1;
	stringstream output;
	while(cin>>n){
		if(n == 0) break;
		vector<tuple<int, int, int>> arr;
		//h, w, l
		for(int i = 0; i < n; i++){
			int a,b,c;
			cin>>a>>b>>c;
			arr.push_back({a,max(b,c),min(b,c)});
			arr.push_back({b,max(a,c),min(a,c)});
			arr.push_back({c,max(b,a),min(b,a)});
		}
		sort(arr.begin(), arr.end(), comp);
		
		int len = 3*n;
		vector<int> lis(len);
		for(int i = 0; i < len; i++){
			lis[i] = get<0>(arr[i]);
		}
		for(int i = 1; i < len; i++){
			for(int j = 0; j < i; j++){
				if((get<1>(arr[i]) < get<1>(arr[j])) && ((get<2>(arr[i]) < get<2>(arr[j])) && (lis[i] < lis[j] + get<0>(arr[i]) ))){
					lis[i] = lis[j] + get<0>(arr[i]);
				}
			}
		}
		int maxH = 0;
		for(int height: lis){
			maxH = max(maxH, height);
		}
		output<<"Case "<<c++<<": maximum height = "<<maxH<<endl;;
	}
	cout<<output.str();
	return 0;
}