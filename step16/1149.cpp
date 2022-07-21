#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000][3];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 0; i < 3; i++){
        int temp;
        cin>>temp;

        arr[0][i] = temp; // 첫번째 rgb 비용들 저장
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            int temp;
            cin>>temp;
            
            // i번째와 다른 색상을 가진 i-1에서의 비용 구해서 최저비용 계산
            arr[i][j] =  min(arr[i-1][(j+1)%3], arr[i-1][(j+2)%3]) + temp;
        }
    }

    int min_cost = min(arr[n-1][2], min(arr[n-1][0], arr[n-1][1]));

    cout<<min_cost;

    return 0;
}