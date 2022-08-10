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
        cin>>dis[i]; // i���� i+1������ �Ÿ�
    }
    for(int i = 0; i < n; i++){
        cin>>cost[i];// i������ ���
    }

    while(cur_pos < n - 1){
        long long cur_move = dis[cur_pos]; // i���� �̵��� �Ÿ�
        int next_pos;
        // �� �� �⸧�� ���� ������ �̵��Ѵ�.
        for(next_pos = cur_pos + 1; cost[cur_pos] < cost[next_pos] && next_pos < n-1; next_pos++){
            cur_move += dis[next_pos];
        }
        // �̵��� �Ÿ��� ����� ���Ѵ�.
        answer += cost[cur_pos] * cur_move;
        cur_pos = next_pos;
    }

    cout<<answer;

    return 0;
}