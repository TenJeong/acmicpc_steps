#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000001]; // dp[i]: �ڿ��� i�� 1�� ����� �ּ� ���� Ƚ��

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;    // i-1�� 1�� ���ϴ� ����
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1); // i/2�� 2�� ���ϴ� ����
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1); // i/3�� 3�� ���ϴ� ����
    }

    cout<<dp[n];

    return 0;
}