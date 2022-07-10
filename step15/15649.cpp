#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9] = {0}; // 선택한 숫자들
int visited[9] = {0}; // 앞에서 선택 여부를 저장 

void find(int count){
    if(count == m){ // 다 선택 했을 시 출력
        for(int i = 0; i < m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return ;
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){    // 방문한적이 없다면
            visited[i] = 1;     // 방문 체크 후 저장
            arr[count] = i;
            find(count+1);  // count번째 이후를 선택함
            visited[i] = 0; // count 이후를 다 선택 했으면 count번째를 초기화
        }
    }
}


int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    find(0);

    return 0;
}