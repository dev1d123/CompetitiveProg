#include <bits/stdc++.h>
using namespace std;



string bigIntegerMod17(string &num) {
	/*
	(a×10+b)modm=[((a mod m)×(10 mod m))mod m+(b mod m)]modm
	*/
	//Es como ir construyendo el numero de izq a der...
	//A medida que se agregan 'unidades' se calcula el modulo posible (el modulo tambien se construye)....por ejemplo con el caso 12345
	/*
	1%17 -> 1 (No es multiplo, pero ese residuo pasa *10, para seguir construyendo el numero)
	12%17 -> 12 (del mismo modo)
	123%17 -> 4 (El modulo es 4, como hay mas cifras seguir analizando)
	45%17 -> 11 
	115%17 -> 13
	
	12345%17 -> 13
	*/
    int divisor = 17;
    int temp = 0;
    
    for (int i = 0; i < num.length(); i++) {
    	//se multiplica por 10 ya que temp es el digito anterior (o numero), sumado por el nuevo digito actual.
        temp = (temp*10 + (num[i] - '0')) % divisor;
        
    }
    return to_string(temp);
}

int main(){
	string s;
	stringstream output;
	while(cin>>s){
		if(s=="0"){
			break;
		}

		if(bigIntegerMod17(s) == "0"){
			output<<1<<endl;
		}else{
			output<<0<<endl;
		}
	}
	cout<<output.str();
	
	
	
	return 0;
}