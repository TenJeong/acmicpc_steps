#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int dp[100001];

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int num;
        cin>>num;
        dp[i] = dp[i-1] + num;  // dp[i]: 1 ~ i까지의 숫자 합
    }

    while(m--){
        int start, end;
        cin>>start>>end;

        cout<<dp[end] - dp[start-1]<<'\n';
    }
    

    return 0;
}