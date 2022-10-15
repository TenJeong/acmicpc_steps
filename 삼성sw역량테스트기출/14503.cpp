#include <iostream>

using namespace std;

int n, m;
int map[50][50];
int cleared = 0;

int curR, curC, curDir;
int moves[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// 왼쪽 방향
int leftDir(int i){
    int left = i - 1;

    if(left < 0) return 3;
    return left;
}

void clearing(){

    while(true){
        // 현재 바닥 청소
        if(map[curR][curC] != 2){
            map[curR][curC] = 2;
            cleared++;
        }

        int d = curDir;
        bool isMoveable = false;

        // 4번 회전하면서 청소가 가능한지 탐색
        for(int i = 0; i < 4; i++){
            d = leftDir(d);
            // 청소가 가능하면 회전 후 이동
            if(map[curR + moves[d][0]][curC + moves[d][1]] == 0){
                curR += moves[d][0];
                curC += moves[d][1];
                curDir = d;
                isMoveable = true;
                break;
            }
        }

        if(isMoveable) continue;

        // 현재 방향의 반대 위치
        int backR = curR + (moves[d][0] * (-1));
        int backC = curC + (moves[d][1] * (-1));
        
        // 뒤로 가지 못하면 중지
        if(map[backR][backC] == 1) break;

        // 뒤로 이동
        curR = backR;
        curC = backC;
        curDir = d;
    }

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    cin>>curR>>curC>>curDir;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>map[i][j];
        }
    }

    clearing();

    cout<<cleared;

    return 0;
}