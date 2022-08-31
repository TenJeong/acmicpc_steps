#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[100000];
long long seg[1000001];

long long maxArea = 0;

// 세그먼트 트리 생성
long long seginit(int node, int start, int end){

    // 구간의 길이가 1이면 현재 높이를 node에 저장 및 반환
    if(start == end) {
        seg[node] = arr[start];
        return seg[node];
    }

    // 반으로 나눴을 때 최소 높이를 구해서 자식 node에 저장
    long long leftHalf_height = seginit(node * 2, start, (end + start) / 2);
    long long rightHalf_height = seginit(node * 2 + 1, (end + start) / 2 + 1, end);

    // 자식 중에서 더 작은 높이를 저장
    long long current_height = min(leftHalf_height, rightHalf_height);

    seg[node] = current_height;
    return current_height;
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin>>n;

        if(n == 0) break;

        maxArea = 0;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        seginit(1, 0, n - 1);
        cout<<maxArea<<'\n';
    }

    return 0;
}