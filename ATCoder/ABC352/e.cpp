#include <bits/stdc++.h>
#define int long long
using namespace std;
class UnionFind {
private:
    vector<int> parent, rank, sz;
    int components;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        sz.resize(n, 1);
        components = n;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            sz[rootX] += sz[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            sz[rootY] += sz[rootX];
        } else {
            parent[rootY] = rootX;
            sz[rootX] += sz[rootY];
            rank[rootX]++;
        }

        components--;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sz[find(x)];
    }

    int count_components() {
        return components;
    }

    vector<vector<int>> groups() {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < parent.size(); i++)
            mp[find(i)].push_back(i);
        
        vector<vector<int>> res;
        for (auto &p : mp)
            res.push_back(p.second);
        return res;
    }
};

signed main(){
	int n,m; cin>>n>>m;
	vector<int> k(m), c(m);
	vector<vector<int>> a(m);
	for(int i = 0; i < m; i++){
		cin>>k[i]>>c[i];
		a[i].resize(k[i]);
		for(int &x: a[i]){
			cin>>x; x--;
		}
	}
	vector<int> ord(m);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j){return c[i] < c[j];});

	UnionFind uf(n);
	int ans = 0;
	for(int i: ord){
		for(int j = 1; j < k[i]; j++){
			if(uf.same(a[i][0], a[i][j])) continue;
			uf.merge(a[i][0], a[i][j]);
			ans += c[i];
		}
	}
	cout<<(uf.groups().size() == 1 ? ans : -1)<<endl;
}
