#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp_asc[1001];
int dp_desc[1001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // i번째 이하에서의 정방향 증가 수열 최대 개수
    for(int i = 0; i < n; i++){
        dp_asc[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp_asc[i] = max(dp_asc[i], dp_asc[j] + 1);
            }
        }
    }

    // i번째 이상에서의 역방향 증가 수열 최대 개수
    for(int i = n-1; i >= 0; i--){
        dp_desc[i] = 1;
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[i]){
                dp_desc[i] = max(dp_desc[i], dp_desc[j] + 1);
            }
        }
    }

    int answer = 1;
    for(int i = 0; i < n; i++){
        // i번째 숫자가 중복되므로 1을 뺸 값과 비교
        answer = max(answer, dp_asc[i] + dp_desc[i] - 1);
    }

    cout<<answer;

    return 0;
}