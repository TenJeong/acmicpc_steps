#include <iostream>
#include <cmath>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin>>n;

    // 0의 개수는 곱해지는 10의 개수로 파악한다.
    // 10 = 2 x 5이며, 모든 자연수의 팩토리얼을 소인수분해하면 2가 5보다 압도적으로 많다.
    // 따라서 5가 곱해지는 개수를 찾는다.

    int count = 0;
    for(int i = 5; i <= n; i *= 5){
        count += (n / i);
    }

    cout<<count;

    return 0;
}