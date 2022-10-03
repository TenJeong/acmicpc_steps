#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int arr[31]; // 더미 데이터 1개를 포함한 31개 
bool dp[31][15001]; // dp[i][w]: i개까지 사용했을 떄 w인 무게의 가능 여부
int n, m;

void weightCheck(int i, int weight){
    if(i > n || dp[i][weight]) return ;
    dp[i][weight] = true; // i개를 사용 여부 결정, weight가 만들어질 수 있음

    weightCheck(i + 1, weight); // i번째를 저울에 올리지 않음
    weightCheck(i + 1, weight + arr[i]); // i번째를 구슬 반대에 놓음
    weightCheck(i + 1, abs(weight - arr[i])); // i번째를 구슬 위치에 놓음
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    weightCheck(0, 0);

    cin>>m;
    
    while(m--){
        int w;
        cin>>w;

        if(w > 15000) cout<<"N ";
        else if(dp[n][w]) cout<<"Y ";
        else cout<<"N ";
    }

    return 0;
}