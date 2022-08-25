#include <iostream>
#define MAX_LINE_NUM 2187

using namespace std;

int numMAT[MAX_LINE_NUM][MAX_LINE_NUM];
int n;
// [0], [1], [2] -> -1, 0, 1
int numCount[3] = {0, 0, 0};

void dnc(int x, int y, int length){
    // length가 1이라면 해당 칸의 숫자를 count함
    if(length == 1) {
        numCount[numMAT[x][y] + 1]++;
        return ;
    }

    int startNum = numMAT[x][y];

    for(int i = x; i < x + length; i++){
        for(int j = y; j < y + length; j++){
            // 다른 수가 존재하면 9개의 사각형으로 나누어서 다시 계산
            if(!(i == x && j == y) && numMAT[i][j] != startNum){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        dnc(x + length * k / 3, y + length * l / 3, length / 3);
                    }
                }
                return;
            }
        }
    }

    // 모두 같다면 해당 수 count
    numCount[startNum + 1]++;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>numMAT[i][j];
        }
    }

    dnc(0, 0, n);

    cout<<numCount[0]<<'\n'<<numCount[1]<<'\n'<<numCount[2];

    return 0;
}
