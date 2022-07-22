#include <iostream>

using namespace std;

int nums[500][500];
int path[500][500];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin>>nums[i][j];
        }
    }

    path[0][0] = nums[0][0];

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j <= i; j++){

            // 현재 대각선 좌측까지의 경로보다 (i, j)에서 가는 것이 더 크다면 갱신
            if(path[i+1][j] < path[i][j] + nums[i+1][j]){
                path[i+1][j] = path[i][j] + nums[i+1][j];
            }

            // 현재 대각선 우측까지의 경로보다 (i, j)에서 가는 것이 더 크다면 갱신
            if(path[i+1][j+1] < path[i][j] + nums[i+1][j+1]){
                path[i+1][j+1] = path[i][j] + nums[i+1][j+1];
            }
        }
    }

    int answer = path[n-1][0];
    for(int i = 1; i < n; i++){
        if(answer < path[n-1][i])
            answer = path[n-1][i];
    }

    cout<<answer;

    return 0;
}