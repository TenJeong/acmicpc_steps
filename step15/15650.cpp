#include <iostream>

using namespace std;

int arr[9] = {0};
int visited[9] = {0};

int n, m;

void find(int start, int count){
    if(count == m){ // m 개를 전부 선택했다면 출력
        for(int i = 0; i < m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = start; i <= n; i++){
        if(visited[i] == 0){    // i를 선택하지 않았다면
            visited[i] = 1;     // i를 선택함
            arr[count] = i;     // 출력 목록에 넣음
            find(i+1,count+1);  // 다음 숫자를 선택함
            visited[i] = 0;     // i 선택을 취소함
        }
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    find(1, 0);    

    return 0;
}