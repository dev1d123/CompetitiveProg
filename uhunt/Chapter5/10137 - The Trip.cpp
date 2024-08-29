#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    stringstream output;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<double> arr(n);
        double sum = 0.0;
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        
        double media = sum / n;
    	
    	//redondeo a dos cifras....hacia arriba y hacia abajo...(por que la media puede variar en un centavo)
    	//con r1 se trabajan los que estan arriba 
    	//con r2 se trabajan los que estan abajo

        double r1 = ceil(media * 100.0) / 100.0;
        double r2 = floor(media * 100.0) / 100.0;
        
        double sum1 = 0.0;
        double sum2 = 0.0;
        
        for (int i = 0; i < n; i++) {
        	//cuanto necesitan dar los de arriba
            if (arr[i] > r1) {
                sum1 += arr[i] - r1;
            }
            
            //cuanto necesitan recibir los de abajo
            if (arr[i] < r2) {
                sum2 += r2 - arr[i];
            }
        }
        //EL maximo siempre sera el correcto por que abarca la cantidad mas precisa.
        output << "$" << fixed << setprecision(2) << max(sum1, sum2) << endl;
    }
    
    cout << output.str();
    return 0;
}
