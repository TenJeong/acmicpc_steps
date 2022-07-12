#include <iostream>
#include <cmath>

using namespace std;

int n;
int case_count = 0;
int arr[16] = {0};

void nqueens(int qnum){
    if(qnum == n + 1){ // n개를 모두 선택했을 경우 count
        case_count++;
        return ;
    }

    for(int i = 1; i <= n; i++){    // qnum 번째 열의 퀸 위치 선정
        bool fittable = true;   // i번째 행에 퀸을 놓을 수 있는가?
        for(int j = 1; j < qnum; j++){  // 이전 행들의 퀸과 비교
            if(arr[j] == i || abs(qnum - j) == abs(i - arr[j])){    // 같은 열에 있거나 대각선에 존재 할 경우...
                fittable = false;   // i에 놓지 못함
                break;
            }
        }
        if(!fittable) continue;
        arr[qnum] = i;  // 놓을 수 있다면 i 열를 선택하고 다음 행의 퀸을 선택함
        nqueens(qnum + 1);
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    nqueens(1);

    cout<<case_count;

    return 0;
}