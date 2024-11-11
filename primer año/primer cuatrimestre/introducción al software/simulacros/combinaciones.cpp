#include <iostream>
#include <vector>

using ll = long long int;

using namespace std;

#define N_BITS 8
#define N_REPETICIONES_MAX 2

vector<vector<int>> dp; // Combinaciones que cumplen con i bits.

ll get_combinaciones(int bits_restantes, int bitsRepetidos){
    if(dp[bits_restantes][bitsRepetidos] != -1) return dp[bits_restantes][bitsRepetidos];
    
    if(bits_restantes == 0) return dp[bits_restantes][bitsRepetidos] = 1;
    // cout << bits_restantes << "\n";
    if(bitsRepetidos == N_REPETICIONES_MAX) {
        return dp[bits_restantes][bitsRepetidos] = get_combinaciones(bits_restantes -1, 1);
    }else{
        return dp[bits_restantes][bitsRepetidos] = get_combinaciones(bits_restantes -1, 1) + get_combinaciones(bits_restantes -1, bitsRepetidos+1);
    }

}

int main(){
    dp.assign(N_BITS+1, vector<int>(N_REPETICIONES_MAX+1, -1));
    cout << get_combinaciones(N_BITS, 0) << "\n";
}