#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct thing {
    int w;
    int v;
};

int dp[101][100001]; //dp[i][j]: 현재 배낭의 무게가 j일 때 i번째 물체 넣기 시도 할 때의 최대
struct thing arr[101];
int n, k;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        cin>>arr[i].w>>arr[i].v;
    }

    memset(dp, 0, sizeof(int) * 100001);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(j < arr[i].w){
                dp[i][j] = dp[i-1][j];
                continue;
            }

            // i번째 물체를 넣을 때와 넣지 않을 때를 비교
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i].w] + arr[i].v);
        }
    }

    cout<<dp[n][k];

    return 0;
}