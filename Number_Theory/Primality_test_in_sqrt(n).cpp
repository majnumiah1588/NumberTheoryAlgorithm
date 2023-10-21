#include<bits/stdc++.h>
using namespace std;

bool primalityTestInSqrtN(long long int n){

    for(long long int i = 2; i*i <= n ; i++){
        if(!(n%i)) return false;
    }
    
    return true;
}

// int main(){ // to debug
//     cout<<primalityTestInSqrtN(37LL)<<endl;
// }