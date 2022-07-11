#include <iostream>

using namespace std;

int n, m;
int arr[9] = {0};

void find(int count){
    if(count == m){ // m개를 모두 선택했다면 출력
        for(int i = 1; i <= m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return ;
    }

    for(int i = arr[count]; i <= n; i++){   // 이전에 선택한 숫자 이후의 범위에서 선택함
        arr[count+1] = i;   // i를 선택
        find(count+1);      // 다음 숫자를 선택함
    }
}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    arr[0] = 1; // 1번째 선택을 위한 데이터
    find(0);

    return 0;
}