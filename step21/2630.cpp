#include <iostream>

using namespace std;

int n;
int paperColor[128][128];
int wbCount[2] = {0 , 0};

int dnc(int x, int y, int length){
    if(length == 1) return paperColor[x][y]; // 길이가 1이면 해당 칸의 색상 반환

    int colorCheck[4]; // 범위 내 4개의 사각형들의 색상 조회 결과
    int wbResult[2] = {0, 0}; // colorCheck들의 하얀색 및 파란색 개수

    // 범위 내 4개의 사격형들의 색상 파악
    colorCheck[0] = dnc(x, y, length / 2);
    colorCheck[1] = dnc(x, y + length / 2, length / 2);
    colorCheck[2] = dnc(x + length / 2, y, length / 2);
    colorCheck[3] = dnc(x + length / 2, y + length / 2, length / 2);

    // 2일 경우 해당 사각형 내의 색상이 단일 색상이 아님
    // 단일이라면 개수 파악
    for(int i = 0; i < 4; i++){
        if(colorCheck[i] != 2){
            wbResult[colorCheck[i]]++;
        }
    }

    // 4개의 사각형 모두 같은 색상이면 해당 색상 반환
    if(wbResult[0] == 4){
        return 0;
    } 
    if(wbResult[1] == 4){
        return 1;
    }

    // 하나라도 다를 경우 전체 개수를 갱신하고 2를 반환
    wbCount[0] += wbResult[0];
    wbCount[1] += wbResult[1];
    return 2;

}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>paperColor[i][j];
        }
    }

    int result = dnc(0, 0, n); // 전체 수행 결과

    if(result != 2) wbCount[result]++; // 같은 색의 사각형 하나라면 마지막에 결과를 더해줌

    cout<<wbCount[0]<<'\n'<<wbCount[1];

    return 0;
}