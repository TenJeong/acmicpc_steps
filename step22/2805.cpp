#include <iostream>

using namespace std;

int n, m;
long long arr[1000000];
long long maxHeight = 0;
long long answer = 0;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
        // 최대 절단기 높이 = 최대 나무 높이
        if(maxHeight < arr[i]) maxHeight = arr[i];
    }

    long long left = 0, right = maxHeight;
    // 0 ~ (절단기 최대 가능 높이) 범위를 이분 탐색 한다
    while(left <= right){
        long long mid = (right + left) / 2;
        long long result = 0;
        // 가져갈 수 있는 나무 길이 계산
        for(int i = 0; i < n; i++){
            if(mid < arr[i]) result += arr[i] - mid;
        }

        // 나무 길이가 부족하면 절단기 높이를 줄여서 탐색
        if(result < m){
            right = mid - 1;
        }
        // 나무 길이가 충분하면 절단기 높이를 늘여서 탐색
        else{
            // 최대 절단기 높이 갱신
            if(answer < mid) answer = mid;
            left = mid + 1;
        }
    }

    cout<<answer;

    return 0;
}