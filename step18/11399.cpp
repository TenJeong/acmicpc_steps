#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int arr[1000];

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // 합을 구했을 떄 적은 값을 많이 더하는 것이 좋음
    // 인출 시간이 적게 걸리는 순서로 정렬
    sort(arr, arr+n);

    int answer = arr[0];
    int sum = arr[0];

    for(int i = 1; i < n; i++){
        sum += arr[i];
        answer += sum;
    }

    cout<<answer;

    return 0;
}