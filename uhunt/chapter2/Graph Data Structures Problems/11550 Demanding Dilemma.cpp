#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    stringstream output;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        map<pair<int, int>, int> rep;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }
        bool ans = true;

        for(int col = 0; col < m; col++){
            int count = 0;
            int num1 = -1;
            int num2 = -1;
            for(int row = 0; row < n; row++){
                if(arr[row][col] == 1){
                    count++;
                    if(num1 == -1) num1 = row;
                    else if(num2 == -1) num2 = row;
                }
                if(count > 2){
                    ans = false;
                    break;
                }
            }
            if(count == 2){
                auto parsito = make_pair(num1, num2);
                rep[parsito]++;
                if(rep[parsito] == 2){
                    ans = false;
                }
            } else if (count != 2){
                ans = false;
            }
            if(!ans) break;
        }

        if(ans){
            output << "Yes" << endl;
        } else {
            output << "No" << endl;
        }
    }
    cout << output.str();

    return 0;
}
