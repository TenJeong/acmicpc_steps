#include <iostream>
#include <cmath>

using namespace std;

int n;
int case_count = 0;
int arr[16] = {0};

bool check(int qnum){
    int current = arr[qnum];
    for(int i = 1; i < qnum; i++){  // 이전 행들의 퀸과 비교
        if(arr[i] == current || (qnum - i) == abs(current - arr[i]))    // 같은 열에 있거나 대각선에 존재 할 경우...
            return false;
    }
    return true;
}

void nqueens(int qnum){
    if(qnum == n + 1){ // n개를 모두 선택했을 경우 count
        case_count++;
        return ;
    }

    for(int i = 1; i <= n; i++){    // qnum번째 열의 퀸 위치 선정
        arr[qnum] = i;  // qnum의 i열을 선택
        if(check(qnum))    // qnum행의 i열에 퀸을 놓을 수 있는가?
            nqueens(qnum+1);   // 놓을 수 있다면 다음 행의 퀸을 선택함
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