#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        int n; 
        cin >> n; 
        char sp; 
        cin >> sp; 

        map<char, int> hav;        
        map<int, char> tr;        
        vector<set<int>> sets(4);  
        
        int idx = 1; 
        hav[sp] = 0; 
        tr[0] = sp;

        for (int i = 0; i < 2*n; i++) {
            string card;
            cin >> card;
            char s = card[1];
            int v = card[0] - '0';

            if (!hav.count(s)) {
            	//si no hay el simpolo, crear
                hav[s] = idx;
                tr[idx] = s;
                idx++;
            }
            sets[hav[s]].insert(v);
        }

        stringstream output;
        bool possible = true;
        for (int i = 1; i < 4; i++) {
            int count = 0;
            for (int card : sets[i]) {
                if (count % 2 == 0) {
                    output<<card<<tr[i] << " ";
                } else {
                    output<<card<<tr[i]<<endl;
                }
                count++;
            }

            if (sets[i].size() % 2 != 0) {
                if (!sets[0].empty()) {
                    auto it = sets[0].begin();
                    output << *it << sp << endl;
                    sets[0].erase(it);
                } else {
                    possible = false; 
                }
            }
        }

        int count = 0;
        for (int card : sets[0]) {
            if (count % 2 == 0) {
                output << card << sp << " ";
            } else {
                output << card << sp << endl;
            }
            count++;
        }

        if (sets[0].size()%2 != 0) {
            possible = false;
        }

        if (possible) {
            cout<<output.str();
        } else {
            cout<<"IMPOSSIBLE" << endl;
        }
    }

    return 0;
}

