#include<bits/stdc++.h>
using namespace std;

const long long int N = 1e7;

vector<int> isPrime(N);

void sieveForPrimeFactorization(){
    isPrime[0] = isPrime[1] = 1;
    
    for(int i = 2; i<=N; i++){
        if(i%2) isPrime[i] = i;
        else isPrime[i] = 2;
    }

    for(long long int i = 3; i*i <= N; i+=2){
        if(isPrime[i] == i){
            for(int j = i*i; j < N; j += 2*i){
                if(isPrime[j] == j)isPrime[j] = i;
            }
        }
    }
}
vector<long long int> PrimeFactorization(long long int n){ //log(N)
    vector<long long int> ans;
    while(n>1){
        ans.push_back(isPrime[n]);
        n = n/isPrime[n];

    }
    return ans;
}


vector<long long int> PrimeFactorizationInSqrtN(long long int n){ // sqrt(N)
    vector<long long int> ans;
    while(n%2 == 0){
            n >>= 1;
            ans.push_back(2);
        }

    for(long long int i = 3; i*i <= n; i+=2){
        while(n%i == 0){
            n /= i;
            ans.push_back(i);
        }
    }
    if(n>2) ans.push_back(n);
    return ans;
}




// int main(){ // to debug
//     sieveForPrimeFactorization();
//     // vector<long long int> pf = PrimeFactorizationInSqrtN(210);
//     // for(auto i:pf) cout<<i<<" "; cout<<endl;
//     vector<long long int> pf = PrimeFactorization(10000000);
//     for(auto i:pf) cout<<i<<" "; cout<<endl;
// }