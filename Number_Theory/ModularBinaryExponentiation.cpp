#include<bits/stdc++.h>
using namespace std;

//const int mod = 1e9+7;

long long int ModularBinaryExponentiation(int base, int power,long long int mod){
    long long int result = 1;
    while(power){
        if(power&1){
            power = power -1;
            result = (result * base) % mod;
        }
        else{
            power >>= 1;
            base = (base * base) % mod;  
        }
    }
    return result;

}




// int main(){ // to debug
//     cout<<ModularBinaryExponentiation(10,9,10000000000)<<endl;
// }