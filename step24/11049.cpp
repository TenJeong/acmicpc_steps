#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int n;
int dpTotal[501][501]; // dpTotal[i][j]: i ~ j번째까지 행렬 곱 횟수 최소합
int dpRowCol[501][501][2]; // dpRowCol[i][j]: i ~ j번째까지 행렬 곱의 행과 열

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 1; i <= n; i++){
        int r, c;
        cin>>r>>c;
        // (i, i)에 해당 행렬의 행과 열 값을 입력 받음
        dpRowCol[i][i][0] = r; dpRowCol[i][i][1] = c;
        // (i, i)는 합을 0하고 나머지 범위는 INT_MAX
        for(int j = 1; j <= n; j++){
            dpTotal[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }

    // 범위 길이
    for(int d = 1; d < n; d++){
        // 시작 지점
        for(int i = 1; i + d <= n; i++){
            // 끝 지점 계산
            int j = i + d;
            // 중간 포인트 p를 정함
            for(int p = i; p < j; p++){
                // 점화식: [i][p] 횟수 + [p+1][j] 횟수 + ([i][p] 와 [p+1][j] 곱에서의 계산 횟수)
                int curTotal = dpTotal[i][p] + dpTotal[p + 1][j] + dpRowCol[i][p][0] * dpRowCol[i][p][1] * dpRowCol[p + 1][j][1];

                // 최소값 갱신
                if(curTotal < dpTotal[i][j]){
                    dpTotal[i][j] = curTotal;
                    dpRowCol[i][j][0] = dpRowCol[i][p][0];
                    dpRowCol[i][j][1] = dpRowCol[p + 1][j][1];
                }
            }
        }
    }

    cout<<dpTotal[1][n];

    return 0;
}