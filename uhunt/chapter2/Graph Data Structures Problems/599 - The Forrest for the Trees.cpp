#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//dfs, recibe el nodo inicial, la lista y el arreglo de visitados
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
	//marca el nodo inicial como true
    visited[node] = true;
    //recorre los vecinos de ese nodo
    for (int neighbor : adj[node]) {
    	//si no esta visitado aplicar dfs otra vez!
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}
//Metodo para contar componentes conectadas, recibe.
/*
adj -> La lista de adjacencia
numVertices -> Cantidad de vertices del grafo
*/
int countConnectedComponents(vector<vector<int>>& adj, int numVertices) {
	//crear el arreglo para marcar los vertices visitados
    vector<bool> visited(numVertices, false);
    int count = 0;
    
    for (int i = 0; i < numVertices; i++) {
        //recorrer todos los vertices y aplicar dfs sobre cada uno de ellos (si todavia no se han visitado)
		if (!visited[i]) {
			//cada vez que se vuelva a llamar al dfs, es una nueva componente!
            count++;
            DFS(i, adj, visited);
        }
    }
    
    return count;
}
int main(){
	stringstream output;
	int t; cin>>t;
	while(t--){
		vector<pair<char, char>> gr;
		while(true){
			string pr; cin>>pr;
			if(pr[0] == '*'){
				break;
			}
			char u = pr[1];
			char v = pr[3];
			gr.push_back(make_pair(u,v));
		}
		vector<char> vertices;
		string vertex;
		cin>>vertex;
		
		for(int i = 0; i < vertex.size(); i++){
			if(vertex[i] != ','){
				vertices.push_back(vertex[i]);
			}	
		}		

		map<char, int> charToIndex;
        for(int i = 0; i < vertices.size(); i++){
            charToIndex[vertices[i]] = i;
        }
        vector<vector<int>> adj(vertices.size());
        for(auto pair: gr){
            int u = charToIndex[pair.first];
            int v = charToIndex[pair.second];
            addEdge(adj, u, v);
        }
        
		int accorns = 0;
        for(int i = 0; i < vertices.size(); i++){
            if(adj[i].size() == 0){
            	accorns++;
			}
        }
		int components = countConnectedComponents(adj, vertices.size());        
        output<<"There are "<<components-accorns<<" tree(s) and "<<accorns<<" acorn(s)."<<endl;
	}
	cout<<output.str();
	
	return 0;
}