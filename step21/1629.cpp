#include <iostream>

using namespace std;

int A, B, C;

long long mul(int exp){
    if(exp == 1) return A % C;

    // A^(exp / 2)를 구함
    long long halfMul = mul(exp / 2);

    // A^(exp/2)로 A^(exp)를 구함
    if(exp % 2 == 0){
        halfMul = halfMul * halfMul % C;
    }
    else{
        halfMul = halfMul * (halfMul * (A % C) % C) % C;
    }

    return halfMul;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>A>>B>>C;

    cout<<mul(B);

    return 0;
}