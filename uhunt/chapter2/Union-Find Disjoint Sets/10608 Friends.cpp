#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
	private:
		vi p, rank, setSize;
		int numSets;
	public:
		UnionFind(int N){
			p.assign(N, 0); 
			for(int i = 0; i < N; i++) {
				p[i] = i;
			}
			rank.assign(N, 0);
			setSize.assign(N, 1);
			numSets = N;
		}
		int findSet(int i){
			if(p[i] != i){
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
				if(isSameSet(i, j)) return;
				int x = findSet(i);
				int y = findSet(j);
				if(rank[x] > rank[y]) swap(x, y);
				p[x] = y;
				if(rank[x] == rank[y]) ++rank[y];
				setSize[y] += setSize[x];
				--numSets;
		}
};
int main(){
        //wow
        ios::sync_with_stdio(false); 
        cin.tie(nullptr); 
        ostringstream output;
	int t; cin>>t; 
		while(t--){
				int n, m;
				cin>>n>>m;
				UnionFind ds(n);
				int ans = 1;
				while(m--){
						int a, b;
						cin>>a>>b;
						ds.unionSet(--a,--b); //the most idiot error that I ever have :(
						ans = max(ans, ds.sizeOfSet(a));
				}
				output<<ans<<'\n';
		}
		cout<<output.str();
		return 0;

}
