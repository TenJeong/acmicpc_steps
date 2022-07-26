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
    dp[1] = amount[1]; dp[2] = amount[1]+amount[2];

    for(int i = 3; i <= n; i++){
        // dp[i]�� dp[i-2], dp[i-3] + amount[i-1], dp[i-4] + amount[i-1]�� �� �߿��� ū ���� i�� ���� ���� �Ͱ� ����.
        dp[i] = max(dp[i-2], max(dp[i-3] + amount[i-1], dp[i-4] + amount[i-1])) + amount[i];
    }

    // �ִ밪�� ã�Ƽ� ����Ѵ�.
    cout<<max(dp[n],max(dp[n-1], dp[n-2]));

    return 0;
}