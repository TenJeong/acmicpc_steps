#include <iostream>
#include <algorithm>

using namespace std;

int amount[10001];
int dp[10001];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>amount[i];
    }

    // dp[i]�� i���� �۰ų� ���� �͵� �߿��� �������� i�� ������ ���� �ִ밪
    amount[0] = dp[0] = 0;
    dp[1] = amount[1]; dp[2] = amount[1] + amount[2];

    dp[3] = max(amount[1] + amount[3], max(amount[2] + amount[3], amount[1] + amount[2]));

    for(int i = 4; i <= n; i++){
        // 1. i�� ���ð� i-1�� ���� ��� 2. i�� ���ð� i-1�� ������ ���� ��� 3. i�� ������ ���� ���
        dp[i] = max(dp[i-3] + amount[i-1] + amount[i], max(dp[i-2] + amount[i], dp[i-1]));
    }

    // �ִ밪�� ã�Ƽ� ����Ѵ�.
    cout<<dp[n];

    return 0;
}