#include <iostream>

using namespace std;

long long cost[100000];
long long dis[100000];
int n, cur_pos = 0;
long long answer = 0;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    cin>>n;

    for(int i = 0; i < n-1; i++){
        cin>>dis[i]; // i에서 i+1까지의 거리
    }
    for(int i = 0; i < n; i++){
        cin>>cost[i];// i에서의 비용
    }

    while(cur_pos < n - 1){
        long long cur_move = dis[cur_pos]; // i에서 이동할 거리
        int next_pos;
        // 더 싼 기름이 나올 때까지 이동한다.
        for(next_pos = cur_pos + 1; cost[cur_pos] < cost[next_pos] && next_pos < n-1; next_pos++){
            cur_move += dis[next_pos];
        }
        // 이동한 거리와 비용을 곱한다.
        answer += cost[cur_pos] * cur_move;
        cur_pos = next_pos;
    }

    cout<<answer;

    return 0;
}