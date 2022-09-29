#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int tripMap[500][500];
int m, n;
int dp[500][500];   // tripMap[r][c]: (r, c)에서 (m - 1, n - 1)까지의 경로 수
bool visited[500][500]; // (r, c) 방문 여부

bool isMoveable(int r, int c, int dir){
    // dir 방향의 이전 좌표 계산
    int nr = r + moves[dir][0], nc = c + moves[dir][1];

    // 범위 내, 내림차순 확인
    if(nr >= 0 && nr < m && nc >= 0 && nc < n && tripMap[r][c] > tripMap[nr][nc]) return true;

    return false;
}

int pathCheck(int r, int c){

    // 종점 위치라면 1을 반환해서 이전 위치에 +1을 수행한다.
    if(r == m - 1 && c == n - 1) return 1;

    // 이미 방문 했던 곳이라면 0으로 현재 위치에서의 경로 개수를 반환한다.
    if(visited[r][c]) return dp[r][c];

    // 방문하지 않았다면 4방향에 대해 경로를 계산한다.
    for(int i = 0; i < 4; i++){
        if(isMoveable(r, c, i)){
            int nr = r + moves[i][0], nc = c + moves[i][1];
            dp[r][c] += pathCheck(nr, nc);
        }
    }

    // 방문 확인
    visited[r][c] = true;

    return dp[r][c];
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>m>>n;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>tripMap[i][j];
        }
        memset(dp[i], 0, sizeof(int) * n);
        memset(visited[i], 0, sizeof(bool) * n);
    }

    cout<<pathCheck(0, 0);

    return 0;
}