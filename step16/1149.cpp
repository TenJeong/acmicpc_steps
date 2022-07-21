#include <iostream>

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
            
            int num_a = arr[i-1][(j+1)%3]; // i번째와 다른 색상을 가진 i-1에서의 비용들
            int num_b = arr[i-1][(j+2)%3];
            
            arr[i][j] = num_a < num_b ? num_a + temp : num_b + temp; // 해당 색상 선택시 최소비용
        }
    }

    int min = arr[n-1][0];  // 마지막에서 최소값을 찾음
    for(int i = 1; i < 3; i++){
        if(arr[n-1][i] < min)
            min = arr[n-1][i];
    }

    cout<<min;

    return 0;
}