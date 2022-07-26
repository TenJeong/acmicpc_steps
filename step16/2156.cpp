#include <iostream>
#include <algorithm>

using namespace std;

int amount[10001];
int dp[10001];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>amount[i];
    }

    // dp[i]는 i보다 작거나 같은 것들 중에서 마지막에 i를 마셨을 때의 최대값
    amount[0] = dp[0] = 0;
    dp[1] = amount[1]; dp[2] = amount[1] + amount[2];

    dp[3] = max(amount[1] + amount[3], max(amount[2] + amount[3], amount[1] + amount[2]));

    for(int i = 4; i <= n; i++){
        // 1. i를 마시고 i-1를 마실 경우 2. i를 마시고 i-1를 마시지 않을 경우 3. i를 마시지 않을 경우
        dp[i] = max(dp[i-3] + amount[i-1] + amount[i], max(dp[i-2] + amount[i], dp[i-1]));
    }

    // 최대값을 찾아서 출력한다.
    cout<<dp[n];

    return 0;
}