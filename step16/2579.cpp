#include <iostream>
#include <algorithm>

using namespace std;

int best_score[301];
int score[301];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>score[i];
    }

    best_score[0] = 0;
    best_score[1] = score[1];
    best_score[2] = max(best_score[0], best_score[1]) + score[2];

    for(int i = 3; i <= n; i++){
        // i-2에서 오거나 i-3에서 i-1을 거쳐서 오는 경우 2가지 비교
        best_score[i] = max(best_score[i-2], best_score[i-3] + score[i-1]) + score[i];
    }

    cout<<best_score[n];

    return 0;
}