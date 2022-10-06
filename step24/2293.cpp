#include <iostream>
#include <cstring>

using namespace std;

int n, k;
int counts[40001]; //counts[i]: i원을 만들 수 있는 경우의 수

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;

    memset(counts, 0, sizeof(int) * (k + 1));
    counts[0] = 1; // 아무것도 선택하지 않을 경우의 수

    for(int i = 0; i < n; i++){
        int c;
        cin>>c;

        // j-(i번째 동전 가치)의 경우의 수를 계속 더한다
        for(int j = c; j <= k; j++){
            counts[j] += counts[j - c];
        }
    }

    cout<<counts[k];

    return 0;
}