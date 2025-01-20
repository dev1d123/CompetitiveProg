#include <bits/stdc++.h>
#define DBG(x) cerr << #x << ": " << x << endl;
#define DBG_VEC(v) cerr << #v << ": ["; for (auto &x : v) cerr << x << " "; cerr << "]" << endl;
#define DBG_MAP(m) cerr << #m << ": {"; for (auto &[key, value] : m) cerr << key << ": " << value << ", "; cerr << "}" << endl;
#define RAYA cerr << "==============================================================================" << endl;

using namespace std;

typedef vector<int> vi;
class UnionFind{
	private:
		vi p, rank, setSize;
		int numSets;

	public:
		UnionFind(int N){
			p.assign(N, 0); for(int i = 0; i < N; i++) p[i] = i;
			rank.assign(N, 0);
			setSize.assign(N, 1);
			numSets = N;
		}
		int findSet(int i) {
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		bool isSameSet(int i, int j) {
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
			if(rank[x] > rank[y]) swap(x, y);
			p[x] = y;
			if(rank[x] == rank[y]) ++rank[y];
			setSize[y] += setSize[x];
			--numSets;
		}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
		UnionFind F(n);
        UnionFind G(n);
        vector<pair<int, int>> f, g;
		for(int i = 0; i < m1; i++){
        	int a, b;
        	cin>>a>>b;
        	a--;
        	b--;
        	f.push_back({a,b});
		}
		for(int i = 0; i < m2; i++){
        	int a, b;
        	cin>>a>>b;
        	a--;
        	b--;
			G.unionSet(a,b);
        	g.push_back({a,b});
		}
		int ans = 0;
		for(auto p: f){
			if(G.isSameSet(p.first, p.second)){
				F.unionSet(p.first, p.second);
			}else{
				ans++;
				
			}
		}
		for(auto p: g){
			if(F.isSameSet(p.first, p.second)){
			}else{
				ans++;
				F.unionSet(p.first, p.second);
			}
		}
		
		cout<<ans<<endl;
		
    }

    return 0;
}

