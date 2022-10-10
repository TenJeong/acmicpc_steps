#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[20][20];
int n;

int maxNum = 0;

//int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void slide(int dir, int curBoard[20][20], int cnt){

    if(dir == 0){ // right
        for(int i = 0; i < n; i++){
            // 빈칸 없이 오른쪽으로 밀기
            for(int j = n - 2; j >= 0; j--){
                if(curBoard[i][j] != 0){
                    int nextIdx = j;

                    while(nextIdx < n - 1 && curBoard[i][nextIdx + 1] == 0) nextIdx++;

                    if(j != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[i][nextIdx];
                        curBoard[i][nextIdx] = temp;
                    }
                }
            }

            // 이웃하는 같은 숫자 합치기
            for(int j = n - 1; j > 0;){
                if(curBoard[i][j] == curBoard[i][j - 1]){
                    curBoard[i][j] *= 2;
                    curBoard[i][j - 1] = 0;
                    if(maxNum < curBoard[i][j]) maxNum = curBoard[i][j];
                    j -= 2;
                }
                else j--;
            }

            // 빈칸 없이 오른쪽으로 밀기
            for(int j = n - 2; j >= 0; j--){
                if(curBoard[i][j] != 0){
                    int nextIdx = j;

                    while(nextIdx < n - 1 && curBoard[i][nextIdx + 1] == 0) nextIdx++;

                    if(j != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[i][nextIdx];
                        curBoard[i][nextIdx] = temp;
                    }
                }
            }
        }
    }
    else if (dir == 1){ // left
        for(int i = 0; i < n; i++){
            // 빈칸 없이 왼쪽으로 밀기
            for(int j = 1; j < n; j++){
                if(curBoard[i][j] != 0){
                    int nextIdx = j;

                    while(nextIdx > 0 && curBoard[i][nextIdx - 1] == 0) nextIdx--;

                    if(j != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[i][nextIdx];
                        curBoard[i][nextIdx] = temp;
                    }
                }
            }

            // 이웃하는 같은 숫자 합치기
            for(int j = 0; j < n - 1;){
                if(curBoard[i][j] == curBoard[i][j + 1]){
                    curBoard[i][j] *= 2;
                    curBoard[i][j + 1] = 0;
                    if(maxNum < curBoard[i][j]) maxNum = curBoard[i][j];
                    j += 2;
                }
                else j++;
            }

            // 빈칸 없이 왼쪽으로 밀기
            for(int j = 1; j < n; j++){
                if(curBoard[i][j] != 0){
                    int nextIdx = j;

                    while(nextIdx > 0 && curBoard[i][nextIdx - 1] == 0) nextIdx--;

                    if(j != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[i][nextIdx];
                        curBoard[i][nextIdx] = temp;
                    }
                }
            }
        }
    }
    else if (dir == 2){ // down
        for(int j = 0; j < n; j++){
            // 빈칸 없이 아래쪽으로 밀기
            for(int i = n - 2; i >= 0; i--){
                if(curBoard[i][j] != 0){
                    int nextIdx = i;

                    while(nextIdx < n - 1 && curBoard[nextIdx + 1][j] == 0) nextIdx++;

                    if(i != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[nextIdx][j];
                        curBoard[nextIdx][j] = temp;
                    }
                }
            }

            // 이웃하는 같은 숫자 합치기
            for(int i = n - 1; i > 0;){
                if(curBoard[i][j] == curBoard[i - 1][j]){
                    curBoard[i][j] *= 2;
                    curBoard[i - 1][j] = 0;
                    if(maxNum < curBoard[i][j]) maxNum = curBoard[i][j];
                    i -= 2;
                }
                else i--;
            }

            // 빈칸 없이 아래쪽으로 밀기
            for(int i = n - 2; i >= 0; i--){
                if(curBoard[i][j] != 0){
                    int nextIdx = i;

                    while(nextIdx < n - 1 && curBoard[nextIdx + 1][j] == 0) nextIdx++;

                    if(i != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[nextIdx][j];
                        curBoard[nextIdx][j] = temp;
                    }
                }
            }
        }
    }
    else if (dir == 3){ // up
        for(int j = 0; j < n; j++){
            // 빈칸 없이 윗쪽으로 밀기
            for(int i = 1; i < n; i++){
                if(curBoard[i][j] != 0){
                    int nextIdx = i;

                    while(nextIdx > 0 && curBoard[nextIdx - 1][j] == 0) nextIdx--;

                    if(i != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[nextIdx][j];
                        curBoard[nextIdx][j] = temp;
                    }
                }
            }

            // 이웃하는 같은 숫자 합치기
            for(int i = 0; i < n - 1;){
                if(curBoard[i][j] == curBoard[i + 1][j]){
                    curBoard[i][j] *= 2;
                    curBoard[i + 1][j] = 0;
                    if(maxNum < curBoard[i][j]) maxNum = curBoard[i][j];
                    i += 2;
                }
                else i++;
            }

            // 빈칸 없이 윗쪽으로 밀기
            for(int i = 1; i < n; i++){
                if(curBoard[i][j] != 0){
                    int nextIdx = i;

                    while(nextIdx > 0 && curBoard[nextIdx - 1][j] == 0) nextIdx--;

                    if(i != nextIdx){
                        int temp = curBoard[i][j];
                        curBoard[i][j] = curBoard[nextIdx][j];
                        curBoard[nextIdx][j] = temp;
                    }
                }
            }
        }
    }

    if(cnt >= 4) return ;

    for(int i = 0; i < 4; i++){
        int nextBoard[20][20];
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                nextBoard[row][col] = curBoard[row][col];
            }
        }
        slide(i, nextBoard, cnt + 1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>board[i][j];
            if(maxNum < board[i][j]) maxNum = board[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        int curBoard[20][20];
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                curBoard[row][col] = board[row][col];
            }
        }
        slide(i, curBoard, 0);
    }
    
    cout<<maxNum;

    return 0;
}