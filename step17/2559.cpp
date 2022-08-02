#include <iostream>

using namespace std;

int dp[100001];
int n, k;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int num;
        cin>>num;
        dp[i] = dp[i-1] + num; // dp[i]: i번째까지의 합
    }

    int answer = -100001;

    for(int i = k; i <= n; i++){
        if(answer < dp[i] - dp[i-k])
            answer = dp[i] - dp[i-k]; // i번째에서 K개를 제외하고 나머지를 뺌
    }

    cout<<answer;

    return 0;
}