#include <iostream>
#include <algorithm>

using namespace std;

int best_score[301][2];  // i번쨰까지 최대 비용, [i번째 계단][i-1에서 경로, i-2에서 경로]
int step[301][2]; // +1의 횟수, 2가 되면 +1 불가능
int score[301];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>score[i];
    }

    best_score[0][0] = best_score[0][1] = 0;
    step[0][0] = step[0][1] = 0;

    for(int i = 0; i < n; i++){
        // i-1을 이용하여 i+1로의 경로 계산 
        if(i + 1 <= n && step[i][0] < 2 && best_score[i+1][0] < best_score[i][0] + score[i+1]){
            step[i+1][0] = step[i][0] + 1;
            best_score[i+1][0] = best_score[i][0] + score[i+1];
        }
        // i-2를 이용하여 i+1로의 경로 계산
        if(i + 1 <= n && step[i][1] < 2 && best_score[i+1][0] < best_score[i][1] + score[i+1]){
            step[i+1][0] = step[i][1] + 1;
            best_score[i+1][0] = best_score[i][1] + score[i+1];
        }

        // i-1을 이용하여 i+2로의 경로 계산
        if(i + 2 <= n && best_score[i+2][1] < best_score[i][0] + score[i+2]){
            step[i+2][1] = 1;
            best_score[i+2][1] = best_score[i][0] + score[i+2];
        }
        // i-2를 이용하여 i+2로의 경로 계산
        if(i + 2 <= n && best_score[i+2][1] < best_score[i][1] + score[i+2]){
            step[i+2][1] = 1;
            best_score[i+2][1] = best_score[i][1] + score[i+2];
        }
    }

    cout<<max(best_score[n][0],  best_score[n][1]);

    return 0;
}