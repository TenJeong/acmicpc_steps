#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 10000002

using namespace std;

int n;
long long arr[100001];
int seg[10000001];

long long maxArea = 0;

// 세그먼트 트리 생성
int seginit(int node, int start, int end){

    // 구간의 길이가 1이면 arr에서의 index를 트리에 저장
    if(start == end) {
        seg[node] = start;
        return start;
    }

    // 반으로 나눴을 때의 최소 높이의 index를 받아옴
    int leftHalfIdx = seginit(node * 2, start, (end + start) / 2);
    int rightHalfIdx = seginit(node * 2 + 1, (end + start) / 2 + 1, end);

    // 최소높이를 저장하고 해당 index를 반환
    if(arr[leftHalfIdx] < arr[rightHalfIdx]){
        seg[node] = leftHalfIdx;
        return leftHalfIdx;
    }
    else{
        seg[node] = rightHalfIdx;
        return rightHalfIdx;
    }
}

// targetLeft, targetRight -> 최소 높이의 index를 찾고자 하는 범위
// rangeStart, rangeEnd -> 현재 비교하는 범위
// 목표 범위에서의 최소 높이를 구함
int findMinHeightIdx(int node, int targetLeft, int targetRight, int rangeStart, int rangeEnd){
    // 찾고자 하는 범위와 하나도 겹치지 않으면 infinite 반환
    if(targetRight < rangeStart || rangeEnd < targetLeft) return INF;

    // 조금이라도 찾는 범위와 겹치면 최소 높이의 index 반환
    if(targetLeft <= rangeStart && rangeEnd <= targetRight) return seg[node];

    // 현재 범위를 반으로 나눠서 최소 높이의 index를 받아옴
    int midPoint = (rangeEnd + rangeStart) / 2;
    int leftHalfIdx = findMinHeightIdx(2 * node, targetLeft, targetRight, rangeStart, midPoint);
    int rightHalfIdx = findMinHeightIdx(2 * node + 1, targetLeft, targetRight, midPoint + 1, rangeEnd);
 
    // 한쪽이 완전히 겹치지 않으면 반대값 반환
    if(leftHalfIdx == INF) return rightHalfIdx;
    if(rightHalfIdx == INF) return leftHalfIdx;

    // 양쪽 범위 중에서 더 작은 높이를 반환
    return arr[leftHalfIdx] < arr[rightHalfIdx] ? leftHalfIdx : rightHalfIdx;
}

void findMaxArea(int start, int end){
    if(end < start) return;

    // 현재 범위의 최소 높이의 index를 받아옴
    int minHeightIdx = findMinHeightIdx(1, start, end, 0, n - 1);


    if(minHeightIdx == INF) return ;

    // 현재 넓이 계산 후 최대 넓이 갱신
    long long currentArea = arr[minHeightIdx] * (end - start + 1);
    if(maxArea < currentArea) maxArea = currentArea;

    // 현재 index를 제외하고 나머지 영역의 최대 넓이를 구함
    findMaxArea(start, minHeightIdx - 1);
    findMaxArea(minHeightIdx + 1, end);
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        cin>>n;

        if(n == 0) break;

        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }

        maxArea = 0;

        // 세그먼트 트리 생성
        seginit(1, 0, n - 1);
        // 사각형 최대 넓이 계산
        findMaxArea(0, n - 1);

        cout<<maxArea<<'\n';
    }

    return 0;
}