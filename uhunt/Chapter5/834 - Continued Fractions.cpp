#include <bits/stdc++.h>
using namespace std;
int main(){
	int n1;
	int n2;
	stringstream output;
	while(cin>>n1>>n2){
		vector<int> arr;
		int i= 0;
		while(true){
			
			int mod;
			if(n1 >= n2){
				if(n2== 0) break;
				arr.push_back(n1/n2);
				mod = n1%n2;
				n1 = mod;
			}else{
				//voltear...solo agregar 0 si es la primera iteracion
				if(i == 0){
					arr.push_back(0);
					swap(n1,n2);
					i++;
					continue;
				}
				swap(n1,n2);
				
				if(n2== 0) break;
				
				if(n1/n2 == n1){
					arr.push_back(n1);
					break;
				}else{
					if(n2== 0) break;

					arr.push_back(n1/n2);
					mod = n1%n2;
					n1 = mod;
				}

			}
			i++;
		}
		
		
		int c = 0;
		output<<"[";
		for(int num: arr){
			output<<num;
			if(c == 0 && arr.size() != 1){
				output<<";";
			}else{
				if(c < arr.size()-1){
					output<<",";
				}
			}
			c++;
		}
		output<<"]"<<endl;
	}
	cout<<output.str();
	return 0;
}