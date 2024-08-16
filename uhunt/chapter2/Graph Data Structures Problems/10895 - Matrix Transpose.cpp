#include <bits/stdc++.h>
using namespace std;

int main() {
	stringstream output;
    while (true) { 
        int m, n;
        if (!(cin >> m >> n)) break; 
        if(m == -1 || n == -1) break; //just for testing
        vector<vector<int>> waos(m, vector<int>(n, 0)); 

        for (int c = 0; c < m; c++) {
            int nonCeros;
            cin >> nonCeros;
            if (nonCeros == 0) {
                continue; 
            }

            vector<int> cols(nonCeros);
            for (int i = 0; i < nonCeros; i++) {
                cin >> cols[i];
                cols[i]--; 
            }

            for (int i = 0; i < nonCeros; i++) {
                int value;
                cin >> value;
                if (cols[i] >= 0 && cols[i] < n) { 
                    waos[c][cols[i]] = value;
                }
            }
        }

        vector<int> nonCerosT(n, 0); 
        vector<vector<pair<int, int>>> ans(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (waos[j][i] != 0) {
                    nonCerosT[i]++;
                    auto parsito = make_pair(j + 1, waos[j][i]);
                    ans[i].push_back(parsito);
                }
            }
        }

        output << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            if (nonCerosT[i] == 0) {
                output << 0 <<endl;
                output << endl;
            } else {
                output << nonCerosT[i];
                for (auto pair : ans[i]) {
                    output <<" "<<pair.first;
                }
                output << endl;
                for (auto it = ans[i].begin(); it != ans[i].end(); ++it) {
                    output << it->second;
                    if (it != ans[i].end() - 1) {
                        output << " ";
                    }
                }
                output << endl;
            }
        }
    }

    cout<<output.str();

    return 0;
}
