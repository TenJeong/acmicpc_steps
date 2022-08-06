#include <iostream>

using namespace std;

int coins[10];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    int numOfCoin = 0;

    cin>>n>>k;

    for(int i = 0; i < n; i++){
        cin>>coins[i];
    }

    // 가장 큰 가치의 동전으로 최대한 채운다.
    for(int p = n - 1; p > 0; p--){
        numOfCoin += k / coins[p];
        k %= coins[p];
    }

    // 가치가 1인 동전들
    numOfCoin += k;

    cout<<numOfCoin;

    return 0;
}