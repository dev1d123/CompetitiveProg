#include <iostream>
#include <string>
using namespace std;

int count_possible_thieves(const string &s) {
    int n = s.size();
    int lastYes = -1;  // Última posición con '1'
    int firstNo = n;   // Primera posición con '0'

    // Recorrer la cadena para encontrar el último '1' y el primer '0'
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            lastYes = i;  // Guardamos la última posición donde alguien vio el cuadro
        } else if (s[i] == '0' && firstNo == n) {
            firstNo = i;  // Guardamos la primera posición donde alguien no vio el cuadro
        }
    }

    // Caso especial: si solo hay '?', todos pueden ser ladrones
    if (lastYes == -1 && firstNo == n) {
        return n;
    }

    // El número de posibles ladrones es la cantidad de personas entre [lastYes + 1, firstNo]
    return firstNo - lastYes;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << count_possible_thieves(s) << endl;
    }
    return 0;
}
