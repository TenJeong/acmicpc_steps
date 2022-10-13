#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[16][2]; //[i][0]: Ti, [i][1]: Pi
int dp[16]; // i번째까지 고려한 최대 금액

int maxProfit = 0;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    memset(dp, 0, sizeof(int) * (n + 1));

    arr[0][0] = 0; arr[0][1] = 0;

    for(int i = 1; i <= n; i++){
        // i번쨰 상담만 할 경우
        if(i + arr[i][0] <= n + 1){
            dp[i] = arr[i][1];
        }
        // 앞의 상담과 합쳤을 떄 가장 큰 금액
        for(int j = 1; j < i; j++){
            if(j + arr[j][0] <= i && i + arr[i][0] <= n + 1 && dp[j] != 0){
                dp[i] = max(dp[i], dp[j] + arr[i][1]);
            }
        }
        maxProfit = max(maxProfit, dp[i]);
    }

    cout<<maxProfit;

    return 0;
}