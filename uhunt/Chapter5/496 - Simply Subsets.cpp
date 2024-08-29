#include <bits/stdc++.h>
using namespace std;
bool equals(map<int, int> &mp1, map<int, int> &mp2, map<int, int> &all){
	if(mp1.size() != mp2.size()){
		return false;
	}
	
	for(auto pair: all){
		if(mp1[pair.first] == 0 || mp1[pair.first] == 0){
			return false;
		}
	}
	return true;
}

bool subset(map<int, int> &mp1, map<int, int> &mp2, map<int, int> &all){
	if(mp1.size() > mp2.size()){
		return false;
	}
	for(auto pair: mp1){
		if(mp2[pair.first] == 0){
			return false;
		}
	}
	return true;
}

bool disjoint(map<int, int> &mp1, map<int, int> &mp2, map<int, int> &all){
	if(mp1.size() == mp2.size()){
		return false;
	}
	for(auto pair: all){
		if(mp1[pair.first] != 0 && mp2[pair.first] != 0){
			return false;
		}
	}
	return true;
		
}
int main(){
	string waos1;
	string waos2;
	while(getline(cin, waos1)){
		if(waos1 == "") break;
		getline(cin, waos2);
		stringstream ss1(waos1);
		stringstream ss2(waos2);
		int number;
		map<int, int> all;
		map<int, int> mp1;
		map<int, int> mp2;
		
		while(ss1>>number){
			all[number]++;
			mp1[number]++;
		}
		while(ss2>>number){
			all[number]++;
			mp2[number]++;		
		}
		

		if(equals(mp1, mp2, all)){
			cout<<"A equals B"<<endl;
		}else if(subset(mp1, mp2, all)){
			cout<<"A is a proper subset of B"<<endl;

		}else if(subset(mp2, mp1, all)){
			cout<<"B is a proper subset of A"<<endl;
			
		}else if(disjoint(mp1, mp2, all)){
			cout<<"A and B are disjoint"<<endl;
			
		}else{
			cout<<"I'm confused!"<<endl;			
		}
		

	}
	return 0;
}