#include <iostream>

using namespace std;

int arr[9] = {0};
int visited[9] = {0};

int n, m;

void find(int start, int count){
    if(count == m){ // m ���� ���� �����ߴٸ� ���
        for(int i = 0; i < m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = start; i <= n; i++){
        if(visited[i] == 0){    // i�� �������� �ʾҴٸ�
            visited[i] = 1;     // i�� ������
            arr[count] = i;     // ��� ��Ͽ� ����
            find(i+1,count+1);  // ���� ���ڸ� ������
            visited[i] = 0;     // i ������ �����
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