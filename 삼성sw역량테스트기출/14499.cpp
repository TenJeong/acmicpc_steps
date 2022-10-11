#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
int x, y;

int map[20][20];
int dice[7]; // 1~6은 각각 주사위의 면을 가리킨다
int moves[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool moveDice(int dir){

    // 다음 위치
    int nextX = x + moves[dir][0];
    int nextY = y + moves[dir][1];

    // 이동 가능 판단
    if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) return false;

    x = nextX;
    y = nextY;

    if(dir == 1){ // east
        int temp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = temp;
    }
    else if(dir == 2){ // west
        int temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = temp;
    }
    else if(dir == 3){ // north
        int temp = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = dice[2];
        dice[2] = temp;
    }
    else if(dir == 4){ // south
        int temp = dice[1];
        dice[1] = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = temp;
    }

    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>x>>y>>k;

    memset(dice, 0, sizeof(int) * 7);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>map[i][j];
        }
    }

    while(k--){
        int command;
        cin>>command;

        // 주사위 이동 성공시 윗칸 출력
        if(moveDice(command)) {
            cout<<dice[1]<<'\n';

            // 아랫칸 및 지도 갱신
            if(map[x][y] == 0) map[x][y] = dice[6];
            else {
                dice[6] = map[x][y];
                map[x][y] = 0;
            }
        }
    }

    return 0;
}