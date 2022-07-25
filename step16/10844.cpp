#include <iostream>

using namespace std;

long long counts[101][10];

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    counts[1][0] = 0;
    for(int i = 1; i <= 9; i++){
        counts[1][i] = 1;
    }

    for(int i = 1; i < n; i++){
        counts[i+1][1] += counts[i][0] % 1000000000; // i번째 자리수가 0인 개수를 i+1번째 자리수가 1인 개수에 더함
        counts[i+1][8] += counts[i][9] % 1000000000; // i번째 자리수가 9인 개수를 i+1번째 자리수가 8인 개수에 더함

        for(int j = 1; j <= 8; j++){ // i번째 자리수가 j인 개수를 i+1번째 자리수가 j-1과 j+1인 개수에 더함
            counts[i+1][j-1] += counts[i][j] % 1000000000;
            counts[i+1][j+1] += counts[i][j] % 1000000000;
        }
    }

    long long answer = 0;

    for(int i = 0; i <= 9; i++){
        answer += counts[n][i];
        answer %= 1000000000;
    }

    cout<<answer;

    return 0;
}