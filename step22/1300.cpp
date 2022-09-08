#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;

// O(n)내에 num보다 작은 수의 개수 구하기
long long lowerCount(long long num){
    long long lCount = 0;

    // i행은 i, i*2, i*3...
    // 따라서 num보다 작은 수는 num / i와 같다
    // 단 열이 n개 이므로 min(num / i, n)으로 나타낼 수 있다.
    for(long long i = 1; i <= n; i++){
        lCount += min(num / i, n);
    }
    return lCount;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    // 배열의 원소 범위는 1 ~ (n*n)이다 
    long long left = 1, right = n * n;

    while(left <= right){
        long long mid = (left + right) / 2;

        // mid보다 작은 수의 개수를 구함
        long long numCount = lowerCount(mid);

        // 개수(순서)가 k보다 작으면 더 큰 수에서 탐색
        if(numCount < k){
            left = mid + 1;
        }
        // 개수(순서)가 k보다 크거나 같으면 더 작은 수에서 탐색
        else{
            right = mid - 1;
        }
    }

    cout<<left;

    return 0;
}