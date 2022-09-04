#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;

    int arr[500000];

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // bound 연산을 위한 정렬
    sort(arr, arr + n);

    cin>>m;

    while(m--){
        int query;
        cin>>query;

        // equal_range로 query값이 있는 범위를 구함
        pair<int *, int *> result = equal_range(arr, arr + n, query);

        // query 초과 위치 - query 이상 위치
        cout<<result.second - result.first<<'\n';
    }

    return 0;
}