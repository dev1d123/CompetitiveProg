#include <bits/stdc++.h>
using namespace std;

/*bitwise operation*/

/*Check the kth bit of x is set.*/
int check_kth_bit(int x, int k){
	//return x & (i<<k);
	return (x>>k) & 1;
}

// Prints the positions of all set (1) bits in binary representation of x
void print_on_bits(int x) {
	for (int k = 0; k < 32; k++) {
		if (check_kth_bit(x, k)) {
			cout << k << ' '; // prints the position of the set bit
		}
	}
	cout << '\n';
}

// Returns the count of set (1) bits in binary representation of x
int count_on_bits(int x) {

	int ans = 0;
	for (int k = 0; k < 32; k++) {
		if (check_kth_bit(x, k)) {
			ans++;
		}
	}
	return ans;
	//return __builtin_popcount(x)
}

//count leading ceros
int count_leading_ceros(int x){
	return __builtin_clz(x);
}
//Checks if a number is even 
bool is_even(int x){
	return !(x & 1);
}

// Sets the kth bit of x to 1 and returns the result
int set_kth_bit(int x, int k) {
	return x | (1 << k);
}

// Sets the kth bit of x to 0 and returns the result
int unset_kth_bit(int x, int k) {
	return x & (~(1 << k));
}
// Toggles the kth bit of x and returns the result
int toggle_kth_bit(int x, int k) {
	return x ^ (1 << k);
}

// Checks if x is a power of 2
bool check_power_of_2(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
	//return count_on_bits(x) == 1;
}

//Return the number of bits used in x
int num_bits(int x){
	return log2(x) + 1;
}
//bitmaks, check all 2^n combinations
void bitmask(int n, vector<int> & arr){
	for(int mask = 0; mask < (1 << n); mask++){
		//do whatever
		for(int i = 0; i < n; i++){
			if(mask & (i << i)){
				//do whatever with the set bit of
			}
		}
	}
}


void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main(){
	fastIO();	

	
	
	return 0;
}