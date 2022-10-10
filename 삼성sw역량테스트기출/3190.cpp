#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

int map[102][102]; // 0: 벽 1: 통과가능 2: 사과 3: 몸체
int n, k, l;

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

queue<pair<int ,int> > q;

typedef struct{
    int time; // 방향 전환 시간
    char dir; // 회전 방향
} command;

command commands[100]; // 방향 변환 명령어

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    memset(map[0], 0, sizeof(int) * (n + 2));
    memset(map[n + 1], 0, sizeof(int) * (n + 2));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            map[i][j] = 1; // 이동가능 공간
        }
    }

    cin>>k;

    while(k--){
        int x, y;
        cin>>x>>y;

        map[x][y] = 2; // 사과 위치
    }

    cin>>l;

    map[1][1] = 3; // 뱀 처음 위치
    q.push(make_pair(1, 1)); // 뱀 좌표

    for(int i = 0; i < l; i++){
        int t;
        char u;

        cin>>t>>u;

        commands[i].time = t;
        commands[i].dir = u;
    }

    int curTime = 0; // 흐른 시간
    pair<int, int> head = make_pair(1, 1);
    int curCommandIdx = 0; // 수행할 회전 명령어 순서
    int curDir = 0; // 현재 이동 방향

    while(true){
        curTime++;
        int nextX = head.first + moves[curDir][0];
        int nextY = head.second + moves[curDir][1];

        // 부딪히면 종료
        if(map[nextX][nextY] == 0 || map[nextX][nextY] == 3) break;

        // 사과가 없다면 꼬리 부분을 제거하고 이동가능한 공간으로 만듬
        if(map[nextX][nextY] == 1){
            map[q.front().first][q.front().second] = 1;
            q.pop();
        }

        // 현재 머리 위치를 추가
        map[nextX][nextY] = 3;
        q.push(make_pair(nextX, nextY));

        // 회전 수행
        if(curTime == commands[curCommandIdx].time){
            switch(commands[curCommandIdx++].dir){
                case 'L':
                    curDir--;
                    if(curDir < 0) curDir = 3;
                    break;
                case 'D':
                    curDir++;
                    if(curDir > 3) curDir = 0;
                    break;
            }
        }

        // 머리 위치 갱신
        head.first = nextX;
        head.second = nextY;

    }

    cout<<curTime;

    return 0;
}