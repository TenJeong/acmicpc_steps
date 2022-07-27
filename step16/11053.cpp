#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;


    arr[0] = -1;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }

    dp[0] = 0;
    int answer = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        for(int j = i-1; j >= 1; j--){
            // 증가하는 순서면 이것에서 1을 추가했을때 가장 큰 값을 저장한다.
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        // 전체 최대값
        answer = max(dp[i], answer);
    }

    cout<<answer;

    return 0;
}