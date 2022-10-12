#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int paper[500][500];
int maxArea = 0;
bool visited[500][500];

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

/* 다른 모양들은 depth가 4인 dfs로 파악이 가능하지만 'ㅗ' 모양은 불가능하다.
    따라서 다른 각 좌표들에 대해 dfs로 4개의 모양을 모두 조사한 후
    'ㅗ' 모양만 따로 조사한다.*/

// 종이 내의 좌표인지 파악
bool isMoveable(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void findShape(int x, int y, int curArea, int counts){
    if(counts > 4) return;
    
    // 4칸이 됐을 경우 최대 크기 갱신
    if(counts == 4) {
        maxArea = max(maxArea, curArea);
        return;
    }

    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];

        if(isMoveable(nx, ny) && !visited[nx][ny]){
            findShape(nx, ny, curArea + paper[x][y], counts + 1);
        }
    }

    visited[x][y] = false;
}

void extraShape(int x, int y){
    // ㅏ, ㅓ, ㅗ, ㅜ 모양을 검사한다

    // ㅏ
    if(x + 2 < n && y + 1 < m){
        int curArea = paper[x][y] + paper[x + 1][y] + paper[x + 1][y + 1] + paper[x + 2][y];
        maxArea = max(maxArea, curArea);
    }
    // ㅓ
    if(x + 2 < n && y - 1 >= 0){
        int curArea = paper[x][y] + paper[x + 1][y] + paper[x + 1][y - 1] + paper[x + 2][y];
        maxArea = max(maxArea, curArea);
    }
    // ㅗ
    if(x + 1 < n && y - 1 >= 0 && y + 1 < m){
        int curArea = paper[x][y] + paper[x + 1][y] + paper[x + 1][y - 1] + paper[x + 1][y + 1];
        maxArea = max(maxArea, curArea);
    }
    // ㅜ
    if(x + 1 < n && y + 2 < m){
        int curArea = paper[x][y] + paper[x][y + 1] + paper[x + 1][y + 1] + paper[x][y + 2];
        maxArea = max(maxArea, curArea);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>paper[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // dfs와 'ㅗ' 모양 조사
            findShape(i, j, 0, 0);
            extraShape(i, j);
        }
    }

    cout<<maxArea;

    return 0;
}