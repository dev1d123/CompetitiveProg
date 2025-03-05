#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (auto &it : a) cin >> it;

    vector<int> ori = a;
    sort(a.begin(), a.end(), greater<int>()); // Ordenar de mayor a menor

    multiset<int> ms;
    int sum = 0;
    vector<int> idx;

    // Seleccionamos los k números más grandes
    for (int i = 0; i < k; i++) {
        sum += a[i];
        ms.insert(a[i]);
    }

    // Encontramos sus posiciones en el array original
    for (int i = 0; i < n; i++) {
        if (ms.count(ori[i])) {
            idx.push_back(i);
            ms.erase(ms.find(ori[i])); // Eliminamos una sola ocurrencia
        }
    }

    // Ordenamos los índices para dividir correctamente
    sort(idx.begin(), idx.end());

    cout << sum << endl; // Imprimir la suma máxima

    // **Dividir en exactamente k grupos**
    vector<int> group_sizes;
    int prev = -1;
    
    for (int i = 0; i < k - 1; i++) {
        group_sizes.push_back(idx[i] - prev);
        prev = idx[i];
    }
    
    // El último grupo toma el resto del array
    group_sizes.push_back(n - prev - 1);

    // **Imprimir los tamaños de los grupos**
    for (int size : group_sizes) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
