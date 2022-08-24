#include <iostream>

using namespace std;

char wbColor[64][64];
int n;

string dnc(int x, int y, int length){
    // 길이가 1이면 "0" 또는 "1" 반환
    if(length == 1) return string(1, wbColor[x][y]);

    string colorCheck = "";

    // 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래를 확인하여 string 형태로 확인함
    colorCheck = colorCheck + dnc(x, y, length / 2);
    colorCheck = colorCheck + dnc(x, y + length / 2, length / 2);
    colorCheck = colorCheck + dnc(x + length / 2, y, length / 2);
    colorCheck = colorCheck + dnc(x + length / 2, y + length / 2, length / 2);

    // 전체가 0일 경우 현재 크기의 사각형도 0
    if(colorCheck == "0000"){
        colorCheck = "0";
    }
    // 전체가 1일 경우 현재 크기의 사각형도 1
    else if(colorCheck == "1111"){
        colorCheck = "1";
    }
    // 하나라도 다른 것이 있다면 해당 문자열에 괄호를 더함
    else{
        colorCheck = "(" + colorCheck + ")";
    }

    return colorCheck;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        // string으로 읽어서 char 형태로 저장함
        for(int j = 0; j < n; j++){
            wbColor[i][j] = str[j];
        }
    }

    cout<<dnc(0, 0, n);

    return 0;
}