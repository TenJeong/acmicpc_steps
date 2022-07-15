#include <iostream>
#include <cmath>

using namespace std;

int n;
int arrS[20][20] = {0}; // S
int team_start[10], team_link[10];  // �� ���� ���
int start_count = 0, link_count = 0; // �� ���� �ο���
int answer = 2001;

void calc(int count, int total_start, int total_link){  // count: �з� Ƚ���̸鼭 �̹��� �з��� �ο�, total_start: ��ŸƮ�� �ɷ�ġ, total_link: ��ũ�� �ɷ�ġ
    if(count == n){ // n���� ��� �з� ������ �ּҰ� ��
        int diff = abs(total_start - total_link);
        if(diff < answer) answer = diff;
        return;
    }

    if(start_count != n / 2){   // ��ŸƮ���� �� ä�����ٸ�
        team_start[start_count++] = count;  // �ش� �ο��� ��ŸƮ���� ����
        int cur_total_start = total_start;  // �� �ο����� �ɷ�ġ ��� �� �߰�
        for(int i = 0; i < start_count; i++){
            cur_total_start += arrS[team_start[i]][count] + arrS[count][team_start[i]];
        }
        calc(count+1, cur_total_start, total_link); // ���� �ο� ����
        team_start[start_count--] = 0;  // ���� ����
    }

    if(link_count != n / 2){    // ��ũ���� �� ä�����ٸ�
        team_link[link_count++] = count;    // �ش� �ο��� ��ũ���� ����
        int cur_total_link = total_link;    // �� �ο����� �ɷ�ġ ��� �� �߰�
        for(int i = 0; i < link_count; i++){
            cur_total_link += arrS[team_link[i]][count] + arrS[count][team_link[i]];
        }
        calc(count+1, total_start, cur_total_link); // ���� �ο� ����
        team_link[link_count--] = 0;    // ���� ����
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arrS[i][j];
        }
    }

    calc(0, 0, 0);

    cout<<answer;

    return 0;
}