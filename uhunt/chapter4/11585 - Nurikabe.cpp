#include <bits/stdc++.h>
using namespace std;
//utilizar variables globales, el arreglo y un arreglo bidimensional para marcar los visitados
vector<string> grid;
vector<vector<int>> valid;
int white = 0;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int floodfill(int r, int c, char target,int R, int C){
	if(r < 0 || r >= R) return 0;
	if(c < 0 || c >= C) return 0;
	
	if(grid[r][c] != target) return 0; 
	if(valid[r][c]) return 0;
	int ans = 1;
	
	valid[r][c] = 1;
	for(int i = 0 ; i < 4; i++){
		ans += floodfill(r+dr[i], c+dc[i], target, R, C);
	} 
	return ans;
}



/*Any two shaded spaces are connected by some
sequence of adjacent shaded spaces. Two spaces
are called adjacent if they share a side.
*/
bool cond1(int r, int c){
    valid.assign(r, vector<int>(c, 0)); 
	int black = 0, posX = -1, posY = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '#') {
                if (posX == -1) posX = i, posY = j; 
                black++;
            }else{
            	white++;
			}
        }
    }
    if (black == 0) return true; 
    int count = floodfill(posX, posY, '#', r, c);
	return count == black;
}
 
/*
For each of the unshaded spaces b, let Wb be the collection of all unshaded spaces that can be reached
from b by a sequence of adjacent unshaded spaces.
Then, Wb contains exactly one numbered space and
that number is exactly the number of spaces in Wb.
*/
bool cond2(int r, int c, vector<tuple<int, int, int>> &info){
    valid.assign(r, vector<int>(c, 0)); 
    if(info.size() == 0){
    	//verificar que cada casilla sea igual a #
    	for(int i = 0; i < r; i++) {
	        for(int j = 0; j < c; j++) {
	            if(grid[i][j] == '.') return false;
	        }
	    }
	    return true;
	}
    int countedWhite = 0;
	for(auto tp: info){
		int x = get<0>(tp);
		int y = get<1>(tp);
		int number = get<2>(tp);
		int counted = floodfill(x, y, '.', r, c);
		countedWhite += counted;
		if(number != counted){
			return false;
		}
	}
	if(countedWhite != white){
		return false;
	}
	return true;
}

/*
For any unshaded space b, there is a sequence of unshaded spaces starting at b and ending at a space on
the edge of the grid where consecutive spaces in this
sequence share a side or a corner.
*/
//for every blank space or for the info space?
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

void floodfillEdge(int r, int c, char target, int R, int C, bool &edge) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (grid[r][c] != target || valid[r][c]) return;

    if (r == 0 || r == R - 1 || c == 0 || c == C - 1) {
        edge = true;
    }
	
    valid[r][c] = 1;
    for (int i = 0; i < 8; i++) {
        floodfillEdge(r + dx[i], c + dy[i], target, R, C, edge);
    }
}

bool cond3(int r, int c, vector<tuple<int, int, int>> &info) {
    
    for (auto tp : info) {
    	    valid.assign(r, vector<int>(c, 0)); 

        int x = get<0>(tp);
        int y = get<1>(tp);
        bool isEdge = false;
        floodfillEdge(x, y, '.', r, c, isEdge);
        if (!isEdge){
        	return false;
		}
    }
    
    return true;
}


bool cond4(int r, int c){
	for(int i = 0; i < r-1; i++) {
        for(int j = 0; j < c-1; j++) {
            bool flag = (grid[i][j] == '.' || grid[i][j+1] == '.' ||
                         grid[i+1][j] == '.' || grid[i+1][j+1] == '.');
            if(flag == false){
            	return false;
			}
        }
    }
    return true;
}


int main(){
	int t; cin>>t;
	stringstream output;
	while(t--){
		white = 0;
		int r, c, d;
		cin>>r>>c>>d;
		vector<tuple<int, int, int>> arr(d);
		for(int i = 0; i < d; i++){
			int x, y, n;
			cin>>x>>y>>n;
			arr[i] = {x, y, n};
		}
		grid.resize(r);
		
		for(int i = 0; i < r; i++){
			cin>>grid[i];
		}
		
		//ubicar la primera posicion de una casilla negra...
		/*
        cout << "¿Se cumple la primera cond? --> " << (cond1(r, c) ? "Si" : "No") << endl;
        cout << "¿Se cumple la segunda cond? --> " << (cond2(r, c, arr) ? "Si" : "No") << endl;
        cout << "¿Se cumple la tercera cond? --> " << (cond3(r, c, arr) ? "Si" : "No") << endl;
        cout << "¿Se cumple la cuarta cond? --> " << (cond4(r, c) ? "Si" : "No") << endl;
		*/
        bool waos = cond1(r, c) && cond2(r, c, arr) && cond3(r, c, arr) && cond4(r, c);
        
        if(waos){
        	puts("solved");
		}else{
        	puts("not solved");
		}
		
	}
	
	//cout<<output.str();
	return 0;
}