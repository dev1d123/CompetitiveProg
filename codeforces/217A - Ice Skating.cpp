#include <bits/stdc++.h>
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
		
		int findSet(int i){
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
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
			if(rank[x] > rank[y]) swap(x, y);
			p[x] = y;
			if(rank[x] == rank[y]) ++rank[y];
			setSize[y] += setSize[x];
			--numSets;
		}
};

int main(){
	int n; cin>>n;
	vector<vector<int>> arr(1001, vector<int>(1001, -1));
	int c = 0;
	for(int i = 0; i < n; i++){
		int x, y; cin>>x>>y;
		arr[x][y] = c;
		c++;
	}
	UnionFind UF(n);
	for(int i = 1; i <= 1000; i++){
		for(int j = 1; j <= 1000; j++){
			if(arr[i][j] != -1){
				for(int top = i + 1; top <= 1000; top++){
					if(arr[top][j] != -1){
						UF.unionSet(arr[i][j], arr[top][j]);
					}
				}
				for(int right = j + 1; right <= 1000; right++){
					if(arr[i][right] != -1){
						UF.unionSet(arr[i][j], arr[i][right]);
					}
				}
			}
		}
	}
	cout<<UF.numDisjointSets() - 1<<endl;
	return 0;
}