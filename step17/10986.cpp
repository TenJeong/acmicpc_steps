#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long sum;
long long interval_remain[1000] = {0};
long long answer = 0;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    sum = 0;

    for(int i = 1; i <= n; i++){
        int temp;
        cin>>temp;

        // i번째까지의 수들의 '나머지'들의 합의 '나머지'
        sum += temp;

        interval_remain[sum % m]++;
    }

    // 나머지가 0인 [0, i] 구간 개수
    answer += interval_remain[0];

    for(int i = 0; i <= m; i++){
        // 같은 나머지를 가지는 것들 중에서 2개(시작, 끝)를 고를 경우의 수
        answer += ((interval_remain[i] * (interval_remain[i] - 1)) / 2);
    }

    cout<<answer;

    return 0;
}