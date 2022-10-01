#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int arr[2001];
int dp[2001][2001]; // 0: 미방문, 1: 팰린드롬 O, 2: 팰린드롬 X

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 1; i <= n; i++){
        memset(dp[i], 0, sizeof(int) * (n + 1));
        cin>>arr[i];
        dp[i][i] = 1;
    }

    for(int d = 1; d < n; d++){ // 현재 범위의 길이
        for(int i = 1; i + d <= n; i++){ // 시작 위치
            int j = i + d;
            // 길이가 1이면 arr[i]와 arr[j]값만 비교함
            if(d == 1){
                dp[i][j] = arr[i] == arr[j] ? 1 : 2;
            }
            // 맨 앞의 수와 맨 뒤의 수를 제외하고 중간 범위가 팰린드롬이어야함
            else if(dp[i + 1][j - 1] == 1 && arr[i] == arr[j]){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 2;
            }
        }
    }

    cin>>m;

    while(m--){
        int s, e;
        cin>>s>>e;

        // dp[s][e]가 1이면 팰린드롬
        int result = dp[s][e] == 1 ? 1 : 0;
        cout<<result<<'\n';
    }


    return 0;
}