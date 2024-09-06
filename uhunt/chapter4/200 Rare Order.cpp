#include <bits/stdc++.h>
using namespace std;

// felix halim toposort
vector<vector<int>> AL;  //adjacency list
vector<int> dfs_num;     //visit
vector<int> ts;          //the sort
const int UNVISITED = -1;
const int VISITED = 1;


void toposort(int u){
	dfs_num[u] = VISITED;
	for(auto vt: AL[u]){
		if(dfs_num[vt] == UNVISITED){
			toposort(vt);
		}
	}
	ts.push_back(u);
}

int main(){
	string line;
	vector<string> lines;
	while(cin>>line){
		if(line == "#"){
			//cout<<"Calcular"<<endl;
			//primer paso, inicializar el grafo con los caracteres
			set<char> nodes;
			map<char, int> mp; // -> del char para trabajar con int!
			
			int count = 0;
			for(string s: lines){	
				for(char c: s){
					int tam = nodes.size();
					nodes.insert(c);
					if(tam != nodes.size()){
						mp[c] = count;
						count++; 
					}
				}
			}
			vector<vector<int>> adj(nodes.size());
			//empezar a llenar el grafo!. relacion de vertices de dos en dos...evitar relaciones repetidos...siempre del minimo al mañxim
			map<pair<int, int>, bool> rep;
			for(int i = 0; i < lines.size() -1 ; i++){
				string line1 = lines[i];
				string line2 = lines[i+1];
				int length = min(line1.length(), line2.length());
				for(int j = 0; j < length; j++){
					
					if(line1[j] != line2[j]){
						//agregar al grafo
						int a = mp[line1[j]];
						int b = mp[line2[j]];
						
						//cout<<"Relacion de "<<line1[j]<<" -> "<< line2[j]<<endl;
						if(!rep[{a, b}]){
							adj[a].push_back(b);
							rep[{a, b}] = true;
						}
						break;
					}
				}
				
			}
			AL = adj;

			dfs_num.assign(nodes.size(), UNVISITED);
			ts.clear();
			for(int u = 0; u < nodes.size(); u++){
				if(dfs_num[u] == UNVISITED){
					toposort(u);
				}
			}
			reverse(ts.begin(), ts.end());
			
			map<int, char> reverse_mp;
			for(auto p: mp){
				reverse_mp[p.second] = p.first;
			}
			//cout<<"Imprimiendoo wn"<<endl;
			for(auto elem: ts){
    			cout << reverse_mp[elem];
			}
			cout<<endl;
			
			lines.clear();
		}else{
			lines.push_back(line);
		}
	}
	
	
	return 0;
}