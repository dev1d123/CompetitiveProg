#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind{
	private:
		vi p, rank, setSize;
		int numSets;
	public:
		UnionFind(int N){
			p.assign(N, 0);
			for(int i = 0; i < N; ++i){
				p[i] = i;
			}
			rank.assign(N,0);
			setSize.assign(N,1);
			numSets = N;
		}
		int findSet(int i){
			if (p[i] != i) {
	            p[i] = findSet(p[i]);
	        }
	        return p[i];
		}
		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}
		int numDisjointSets(){
			return numSets;
		}
		int sizeOfSet(int i){
			return setSize[findSet(i)];
		}
		void unionSet(int i, int j){
			if(isSameSet(i, j)){
				return; //i y j son del mismo conjunto
			}
			//Encontrar ambos elementos represetativos
			int x = findSet(i);
			int y = findSet(j);
			
			//Mantener el arbol lo mas pequeño, para optimizar
			//siempre x debe ser menor que y
			if(rank[x] > rank[y]){
				swap(x,y);
			}
			p[x] = y; //x debajo de y
			
			//Actualizar la 'importancia' de y (profundidad)
			if(rank[x] == rank[y]){
				rank[y]++;
			}
			setSize[y] += setSize[x];
			--numSets;
		}
};

int main(){
	
	int n,m;
	stringstream output;
	while(cin>>n>>m){
		if(n == 0 && m == 0){
			break;		
		}
		UnionFind dsu(n);

		while(m--){
			int c; cin>>c;
			vector<int> arr(c);
			for(int i = 0; i < c; i++){
				cin>>arr[i];
			}
			for(int i = 0; i < c-1; i++){
				dsu.unionSet(arr[i], arr[i+1]);
			}		
		}
		output<<dsu.sizeOfSet(0)<<endl;
	}
	cout<<output.str();
	
	
	return 0;
}