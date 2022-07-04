#include <iostream>

using namespace std;

int factorial(int i){
    if(i <= 1) return 1;
    return i * factorial(i-1);
}

int main(){

    int n, k;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    cout<<factorial(n) / (factorial(k) * factorial(n-k));


    return 0;
}