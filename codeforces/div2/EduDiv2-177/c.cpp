#include <bits/stdc++.h>
using namespace std;

class UnionFind{
private:
	vector<int> parent, rank, size;
	int numSets;
public:
    UnionFind(int n) {
        parent.resize(n+1);
        rank.assign(n+1, 0);
        size.assign(n+1, 1);
        numSets = n;
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    bool isSameSet(int i, int j) {
        return find(i) == find(j);
    }

    bool unionSet(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;

        if (rank[x] < rank[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
            if (rank[x] == rank[y]) rank[x]++;
        }

        numSets--;
        return true;
    }

    int count() const {
        return numSets;
    }

    int getSize(int i) {
        return size[find(i)];
    }
};





int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		vector<int> q(n);
		UnionFind uf(n+1);

		for(int i = 0; i < n; i++){
			cin>>a[i];
			uf.unionSet(a[i], i+1);
		}
		
		int b = 0;
		int rep = 0;
		for(int i = 0; i < n; i++){
			cin>>q[i];
			if(i == 0) rep = q[i];
			uf.unionSet(q[i], rep);
			cout<<uf.getSize(q[i])<<" "; 
		}
		cout<<endl;
		
	}

	return 0;
}
