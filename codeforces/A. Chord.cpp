#include <bits/stdc++.h>
using namespace std;
int main(){
	map<string, int> mp;
	mp["C"] = 0;
	mp["C#"] = 1;
	mp["D"] = 2;
	mp["D#"] = 3;
	mp["E"] = 4;
	mp["F"] = 5;
	mp["F#"] = 6;
	mp["G"] = 7;
	mp["G#"] = 8;
	mp["A"] = 9;
	mp["B"] = 10;
	mp["H"] = 11;
	
	string n1, n2, n3;
	cin>>n1>>n2>>n3;
	vector<string> notes = {n1, n2, n3};

	
    bool isMajor = false, isMinor = false;
    sort(notes.begin(), notes.end());

    do {
        int d1 = (mp[notes[1]] - mp[notes[0]] + 12) % 12;
        int d2 = (mp[notes[2]] - mp[notes[1]] + 12) % 12;
        
        if (d1 == 4 && d2 == 3) isMajor = true;
        if (d1 == 3 && d2 == 4) isMinor = true;
        
    } while (next_permutation(notes.begin(), notes.end()));
    
    if (isMajor) {
        cout << "major" << endl;
    } else if (isMinor) {
        cout << "minor" << endl;
    } else {
        cout << "strange" << endl;
    }
	
	return 0;
}