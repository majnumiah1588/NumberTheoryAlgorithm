#include<bits/stdc++.h>
using namespace std;

void matrixMultiplication(vector<vector<long long int>> &a, vector<vector<long long int>> &b,long long int mod){
    int i,j,k;
    vector<vector<long long int>> ans(a.size(), vector<long long int>(a.size(),0));
    int n = a.size();
    int curr;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            curr = 0;
            for(int k = 0; k < n; k++){
                
                curr =(curr + (a[i][k] * b[k][j]) % mod) % mod;
            }
            ans[i][j] = curr;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = ans[i][j];
        }
    }
}
vector<vector<long long int>> ModularMatrixExponentiation(vector<vector<long long int>> &base, int power,long long int mod){
    vector<vector<long long int>> result(base.size(), vector<long long int>(base[0].size(),0));
    for(int i = 0; i<base.size();i++){
        result[i][i] = 1;
    }
    while(power){
        if(power&1){
            power = power -1;
            matrixMultiplication(result,base,mod);
        }
        else{
            power >>= 1;
            matrixMultiplication(base,base,mod);  
        }
    }
    return result;

}




// int main(){ // to debug
//     vector<vector<long long int>> base = {{1,2},{3,4}};
//     vector<vector<long long int>> ans = ModularMatrixExponentiation(base,2,10);
//     for(int i = 0; i < 2; i++){
//         for(int j = 0; j < 2; j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }