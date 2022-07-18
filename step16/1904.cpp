#include <iostream>

using namespace std;

int arr[1000001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;

    cin>>n;

    arr[1] = 1; arr[2] = 2;

    // n에서의 개수는 n-1 자리수에 1을 붙인 것과 n-2 자리수에 00을 붙인 것과 같다.
    // 따라서 (n 자리수 개수) = (n - 1 개수) + (n - 2 개수) 
    for(int i = 3; i <= n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 15746;
    }

    cout<<arr[n];

    return 0;
}