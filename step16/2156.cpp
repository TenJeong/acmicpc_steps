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
    dp[1] = amount[1]; dp[2] = amount[1]+amount[2];

    for(int i = 3; i <= n; i++){
        // dp[i]는 dp[i-2], dp[i-3] + amount[i-1], dp[i-4] + amount[i-1]의 값 중에서 큰 값에 i의 값을 더한 것과 같다.
        dp[i] = max(dp[i-2], max(dp[i-3] + amount[i-1], dp[i-4] + amount[i-1])) + amount[i];
    }

    // 최대값을 찾아서 출력한다.
    cout<<max(dp[n],max(dp[n-1], dp[n-2]));

    return 0;
}