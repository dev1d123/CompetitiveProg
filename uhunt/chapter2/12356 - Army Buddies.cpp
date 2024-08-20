#include <bits/stdc++.h>
using namespace std;
int main(){
	int S, B;
	stringstream output;
	while(cin>>S>>B){
		if(B == 0 && S == 0){
			break;
		}
		
		//s -> number
		//b -> battles
		vector<int> left(S, 0);
		vector<int> right(S, 0);
		//the soldier i has the left[i] and the right[i] buddies
		left[0] = -1;
		for(int i = 0; i < S - 1; i++){
			left[i+1] = i; 
		}
		right[S-1] = -1;
		for(int i = 0; i < S-1; i++){
			right[i] = i+1;
		}
		while(B--){
			int L, R; 
			cin>>L>>R;
			L--;
			R--;
			//simulate the reference :) -> instead of right[L-1] use the 'reference'
			if(left[L] >= 0){
				right[left[L]] = right[R];
			}
			//simulate the reference :) -> instead of the right neighbor....use the 'reference' of the right
			//								instead of the left neighbor....use the 'reference' of the left

			if(right[R] >= 0){
				left[right[R]] = left[L];
			}
			
			string ans1 = (left[L] + 1 != 0) ? to_string(left[L] + 1) : "*";
			string ans2 = (right[R] + 1 != 0) ? to_string(right[R] + 1) : "*";

			output<<ans1<<" "<<ans2<<endl;
		}
		output<<"-"<<endl;
	}
	cout<<output.str();
	
	
	return 0;
}