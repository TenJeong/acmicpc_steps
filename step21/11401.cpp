#include <iostream>

using namespace std;

long long n, k;
long long numer = 1, denom = 1;
long long DIVISOR = 1000000007;

//n!/(k!(n-k)!)
long long dnc(long long counts){
    if(counts == 1) return denom % DIVISOR;

    long long cal = dnc(counts / 2) % DIVISOR;

    // 지수가 2의 배수일 경우 제곱근을 서로 곱한다
    if(counts % 2 == 0){
        cal = cal * cal % DIVISOR;
    }
    // 지수가 2의 배수가 아니면 지수를 2로 나눈 값을 구해서 곱하고 밑을 한번 더 곱해준다
    else{
        cal = cal * (cal * denom % DIVISOR) % DIVISOR;
    }

    return cal;
}
int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    // nCk = n! / (k!(n-k)!) = (n - k + 1)! / k!

    // (n - k + 1)!
    for(long long i = n; i >= n - k + 1; i--){
        numer *= i;
        numer %= DIVISOR;
    }

    // k!
    for(long long i = k; i > 1; i--){
        denom *= i;
        denom %= DIVISOR;
    }

    // 페르마의 소정리 이용: k와 k^p는 p에 대해 합동이다 (p로 나누었을 때 나머지가 같다)
    // k^(-1)은 k^(p-2)과 합동이다
    // 따라서 ((n - k + 1)! % (10^9+7))와 (k^(10^9 + 7 - 2) % (10^9 + 7))을 구해서 곱해준다
    cout<< numer * dnc(DIVISOR - 2) % DIVISOR;

    return 0;
}