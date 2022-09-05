#include <iostream>
#include <algorithm>

using namespace std;

long long k, n;
long long arr[10000];
long long maxLength = 0;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>k>>n;

    for(int i = 0; i < k; i++){
        cin>>arr[i];
    }

    // 이중 분할 탐색을 위한 정렬
    sort(arr, arr + k);

    // 나누어진 랜선의 길이는 1 ~ (가장 긴 랜선의 길이)의 범위이다.
    // 해당 범위를 이중 분할 탐색한다.
    for(long long left = 1, right = arr[k - 1]; left <= right;){
        long long mid = (right + left) / 2;
        long long lineCount = 0;

        // 중간값으로 나누어지는 랜선 개수를 구함
        for(int i = 0; i < k; i++){
            lineCount += arr[i] / mid;
        }
        
        // 랜선 개수가 적으면 길이를 줄여서 탐색
        if(lineCount < n){
            right = mid - 1;
        }
        // 랜선 개수가 같거나 크면 길이의 최대값을 갱신하고 랜선 길이를 늘여서 탐색
        else{
            if(maxLength < mid){
                maxLength = mid;
            }
            left = mid + 1;
        }
    }

    cout<<maxLength;

    return 0;
}