#include <iostream>
#include <cmath>

using namespace std;

int n;
int arrS[20][20] = {0}; // S
int team_start[10], team_link[10];  // 각 팀의 목록
int start_count = 0, link_count = 0; // 각 팀의 인원수
int answer = 2001;

void calc(int count, int total_start, int total_link){  // count: 분류 횟수이면서 이번에 분류할 인원, total_start: 스타트팀 능력치, total_link: 링크팀 능력치
    if(count == n){ // n명을 모두 분류 했으면 최소값 비교
        int diff = abs(total_start - total_link);
        if(diff < answer) answer = diff;
        return;
    }

    if(start_count != n / 2){   // 스타트팀이 덜 채워졌다면
        team_start[start_count++] = count;  // 해당 인원을 스타트팀에 배정
        int cur_total_start = total_start;  // 새 인원과의 능력치 계산 후 추가
        for(int i = 0; i < start_count; i++){
            cur_total_start += arrS[team_start[i]][count] + arrS[count][team_start[i]];
        }
        calc(count+1, cur_total_start, total_link); // 다음 인원 선택
        team_start[start_count--] = 0;  // 원상 복구
    }

    if(link_count != n / 2){    // 링크팀이 덜 채워졌다면
        team_link[link_count++] = count;    // 해당 인원을 링크팀에 배정
        int cur_total_link = total_link;    // 새 인원과의 능력치 계산 후 추가
        for(int i = 0; i < link_count; i++){
            cur_total_link += arrS[team_link[i]][count] + arrS[count][team_link[i]];
        }
        calc(count+1, total_start, cur_total_link); // 다음 인원 선택
        team_link[link_count--] = 0;    // 원상 복구
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