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
			for(int i = 0; i < N; i++){
				p[i] = i;
			}
			rank.assign(N, 0);
			setSize.assign(N, 1);
			numSets = N;
		}
		int findSet(int i){
			return (p[i] == i ? i : (p[i] = findSet(p[i])));
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
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) swap(x, y);
			p[x] = y;
			if(rank[x] == rank[y]) rank[y]++;
			setSize[y] += setSize[x];
			--numSets;
		}
};
int main(){
        ios::sync_with_stdio(false); 
        cin.tie(nullptr); 
	int c, r;
	stringstream output;
	while(cin>>c>>r){
		if(c == 0 && r == 0){
			break;
		}
		unordered_map<string, int> mp;
		UnionFind ds(c);
		for(int i = 0; i < c; i++){
			string name; cin>>name;
			mp[name] = i;
		}
		int ans = 1;
		for(int i = 0; i < r; i++){
			string r1, r2;
			cin>>r1>>r2;
			ds.unionSet(mp[r1], mp[r2]);
			ans = max(ans, ds.sizeOfSet(mp[r1]));
		}
		output<<ans<<endl;
	}
	cout<<output.str();
	return 0;
}
