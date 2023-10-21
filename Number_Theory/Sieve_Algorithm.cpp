#include<bits/stdc++.h>
using namespace std;

const long long int N = 1e7;

vector<bool> isPrime(N, true);

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for(int i = 4; i <= N; i+=2){
        isPrime[i] = false;
    }

    for(long long int i = 3; i*i <= N; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j < N; j += 2*i){
                isPrime[j] = false;
            }
        }
    }
}


int main(){ // to debug
    sieve();
    for(int i = 0; i < 100; i++)cout<<i<<" "<<isPrime[i]<<endl;
}