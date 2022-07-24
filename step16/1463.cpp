#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001]; // dp[i]: 자연수 i를 1로 만드는 최소 연산 횟수

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;    // i-1에 1을 더하는 연산
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1); // i/2에 2를 곱하는 연산
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1); // i/3에 3을 곱하는 연산
    }

    cout<<dp[n];

    return 0;
}