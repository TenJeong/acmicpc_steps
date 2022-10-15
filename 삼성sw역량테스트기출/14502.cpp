#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int templab[8][8];
int lab[8][8];
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int maxSafeArea = 0;

queue<pair<int, int> > initVirus;

bool isMoveable(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || lab[x][y] != 0) return false;
    return true;
}

void copylab(int srclab[8][8], int dstlab[8][8]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dstlab[i][j] = srclab[i][j];
        }
    }
}

void makeWall(int cnt){
    // 벽이 3개 생성됐다면 bfs로 바이러스 전파 결과 확인
    if(cnt == 3){
        // 임시 공간에 lab정보 저장
        copylab(lab, templab);
        queue<pair<int, int> > virus = initVirus;

        // bfs
        while(!virus.empty()){
            int curX = virus.front().first;
            int curY = virus.front().second;
            virus.pop();
            for(int i = 0; i < 4; i++){
                int nx = curX + moves[i][0];
                int ny = curY + moves[i][1];

                if(isMoveable(nx, ny)){
                    lab[nx][ny] = 2;
                    virus.push(make_pair(nx, ny));
                }
            }
        }

        // 안전 영역 계산
        int safeArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(lab[i][j] == 0) safeArea++;
            }
        }

        maxSafeArea = max(maxSafeArea, safeArea);
        
        // lab 원복
        copylab(templab, lab);

        return;
    }

    // 3개의 벽 생성
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(lab[i][j] == 0){
                lab[i][j] = 1;
                makeWall(cnt + 1);
                lab[i][j] = 0;
            }
        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>lab[i][j];
            
            // 초기 바이러스 위치 저장
            if(lab[i][j] == 2) initVirus.push(make_pair(i, j));
        }
    }

    makeWall(0);

    cout<<maxSafeArea;

    return 0;
}