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

    bool isMinusOne = true, isZero = true, isOne = true;

    for(int i = x; i < x + length; i++){
        for(int j = y; j < y + length; j++){
            // 사각형 범위 내를 검사해서 해당 숫자 외의 값은 false
            if(numMAT[i][j] == -1){
                isZero = false;
                isOne = false;
            }
            else if(numMAT[i][j] == 0){
                isMinusOne = false;
                isOne = false;
            }
            else if(numMAT[i][j] == 1){
                isMinusOne = false;
                isZero = false;
            }
        }
        
        // 전부 false라면 두 개 이상의 수가 존재함
        // 따라서 9개의 사각형으로 나누어서 다시 계산
        if(!isMinusOne && !isZero && !isOne){
            dnc(x, y, length / 3);
            dnc(x, y + length / 3, length / 3);
            dnc(x, y + length * 2 / 3, length / 3);
            dnc(x + length / 3, y, length / 3);
            dnc(x + length / 3, y + length / 3, length / 3);
            dnc(x + length / 3, y + length * 2 / 3, length / 3);
            dnc(x + length * 2 / 3, y, length / 3);
            dnc(x + length * 2 / 3, y + length / 3, length / 3);
            dnc(x + length * 2 / 3, y + length * 2 / 3, length / 3);
            return;
        }
    }

    // 하나의 숫자만 존재한다면 해당 숫자를 1개 count함
    if(isMinusOne){
        numCount[0]++;
    }
    else if(isZero){
        numCount[1]++;
    }
    else if(isOne){
        numCount[2]++;
    }
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
