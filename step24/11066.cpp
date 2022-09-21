#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int nums[501]; // 각각의 비용
int sums[501]; // sums[i]: 1 ~ i까지의 비용의 합
int dp[501][501]; // dp[x][y]: x ~ y까지의 최소 비용

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t, k;

    cin>>t;

    while(t--){
        cin>>k;

        nums[0] = 0;
        sums[0] = 0;

        for(int i = 1; i <= k; i++){
            cin>>nums[i];
            sums[i] = sums[i-1] + nums[i];
        }

        // distance: x와 y의 거리
        for(int distance = 1; distance < k; distance++){
            for(int x = 1; x + distance <= k; x++){
                int y = x + distance;

                dp[x][y] = INT_MAX;

                // (x, y)를 두 부분으로 나누어서 최소합을 구함
                for(int p = x; p < y; p++){
                    // 점화식: dp[x][p] + dp[p + 1][y] + sums[y] - sums[x - 1]
                    dp[x][y] = min(dp[x][y], dp[x][p] + dp[p + 1][y] + sums[y] - sums[x - 1]);
                }
            }
        }

        cout<<dp[1][k]<<'\n';

    }

    return 0;
}