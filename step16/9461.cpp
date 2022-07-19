#include <iostream>

using namespace std;

long long arr[101] = {0};

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t,n;
    int max = 5; // 현재 계산 최대값

    cin>>t;

    arr[0] = 0; arr[1] = 1; arr[2] = 1; arr[3] = 1;
    arr[4] = 2; arr[5] = 2;
    while(t--){
        cin>>n;
        if(n > max){ // 아직 계산하지 않은 값
            for(int i  = max + 1; i <= n; i++){ // i-1번째와 i-5번째의 합과 같음
                arr[i] = arr[i - 1] + arr[i - 5];
            }
            max = n;
        }
        cout<<arr[n]<<'\n';
    }

    return 0;
}