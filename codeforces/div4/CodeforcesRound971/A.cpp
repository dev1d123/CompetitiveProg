#include <bits/stdc++.h>
using namespace std;
int main(){
	int a = 6;
	unordered_map<int, int> cubes;
    for(int i = 1; i <= 200; ++i) {
        cubes[i] = i * i * i;
    }
	while(a <= 200){
		cout<<"a: "<<a<<endl;
		int a3 = cubes[a];
		
		for(int i = 1; i < a; i++){
			if(cubes[i] > a3) break;
			for(int j = 1 ; j <= i; j++){
				if(cubes[i] + cubes[j] > a3) break; 
				for(int k = 1; k <= j; k++){
					if(cubes[i] + cubes[j] + cubes[k] == a3){
						cout<<"Cube = "<<a<<", Triple = ("<<i<<","<<j<<","<<k<<")"<<endl;
						break;
					}else if(cubes[i] + cubes[j] + cubes[k] > a3){
						break;
					}
				}
			}
		}
		a++;
	}

	
	return 0;
}