#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n;
int dp[501][501]; // dpTotal[i][j]: i ~ j번째까지 행렬 곱 횟수 최소합
int mat[501][2];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>mat[i][0]>>mat[i][1];
        dp[i][i] = 0;
    }

    // 범위 길이
    for(int d = 1; d < n; d++){
        // 시작 지점
        for(int i = 1; i + d <= n; i++){

            // 끝 지점 계산
            int j = i + d;
            dp[i][j] = INT_MAX;

            // 중간 포인트 p를 정함
            for(int p = i; p < j; p++){
                // 점화식: (i ~ p 연산 최소 횟수) + (p + 1 ~ j 연산 최소 횟수) + (i번째 행 * p번째 열 * j번째 열)
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] + (mat[i][0] * mat[p][1] * mat[j][1]));
            }
        }
    }

    cout<<dp[1][n];

    return 0;
}