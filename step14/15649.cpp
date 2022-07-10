#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[9] = {0}; // ������ ���ڵ�
int visited[9] = {0}; // �տ��� ���� ���θ� ���� 

void find(int count){
    if(count == m){ // �� ���� ���� �� ���
        for(int i = 0; i < m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return ;
    }

    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){    // �湮������ ���ٸ�
            visited[i] = 1;     // �湮 üũ �� ����
            arr[count] = i;
            find(count+1);  // count��° ���ĸ� ������
            visited[i] = 0; // count ���ĸ� �� ���� ������ count��°�� �ʱ�ȭ
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