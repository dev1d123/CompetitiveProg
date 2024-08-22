#include <bits/stdc++.h>
using namespace std;

string bigIntegerSum(string s1, string s2) {
    string a = s2, b = s1;
    if (s1.length() >= s2.length()) {
        a = s1;
        b = s2;
    }
    string ans = "";
    int idx1 = a.length() - 1;
    int idx2 = b.length() - 1;
    int carry = 0;
    for (int i = 0; i < a.length(); i++) {
        int digitA = a[idx1] - '0';  
        int digitB = idx2 >= 0 ? b[idx2] - '0' : 0; 
        int res = digitA + digitB + carry;     
        if (res >= 10) {
            carry = 1;
            res -= 10;
        } else {
            carry = 0;
        }
        ans = to_string(res) + ans;
        
        idx1--;
        idx2--;
    }
    if (carry) {
        ans = '1' + ans;
    }
    return ans;
}

string bigIntegerDiv(string num, int divisor) {
    string ans = "";
    int idx = 0;
    int temp = num[idx] - '0'; //contiene la porcion actual del numero que se está dividiendo.
    
    //inicializar apropiadamente el temp para realizar la p
    while (temp < divisor) {
        if (++idx < num.length()) {
			temp = temp * 10 + (num[idx] - '0');
        } else {
            break;
        }
    }
    //procesar todos los digitos restantes...
    while (num.length() > idx) {
        ans += (temp / divisor) + '0'; //Aqui se hace la division con la parte simple que has seleccionado....
        temp = (temp % divisor) * 10 + num[++idx] - '0'; // Bro literalmente aqui ya estas restando y bajando el siguiente...
        //casos....
        //temp es menor que divisor -> se aumenta un 0 al cociente y se sigue construyendo temp hasta poder dividir apropiadamente
        //temp es 0 -> se aumenta un 0 al cociente hasta encontrar a otra cifra significativa.
        // temp es mayor que el divisor -> division normal, resta y construir el temp con lo demas
    }
    
    if (ans.length() == 0) {
        return "0";
    }
    
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, f;
    stringstream output;
    int count = 1;
    while (cin >> n >> f) {
        if (n == 0 && f == 0) {
            break;
        }
        string total = "0";
        while (n--) {
            string w;
            cin >> w;
            total = bigIntegerSum(total, w);
        }
        string ans = bigIntegerDiv(total, f); 
        
        output << "Bill #" << count << " costs " << total << ": each friend should pay " << ans << '\n';
        output<<'\n';
        count++;
    }
    cout << output.str();
    
    return 0;
}
