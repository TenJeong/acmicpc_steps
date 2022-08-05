#include <iostream>

using namespace std;

int n, m;
long long dp[1025][1025];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i <= n; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        dp[i][0] = 0;
        for(int j = 1; j <= n; j++){
            int temp;
            cin>>temp;
            // dp[i][j]: (0,0) ~ (i, j)의 모든 숫자의 합.
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + temp;
        }
    }

    while(m--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        // (0,0) ~ (x2, y2)에서 필요없는 부분을 빼고 중복으로 뺀 부분을 더함.
        cout<<dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]<<'\n';
    }

    return 0;
}