#include <iostream>

using namespace std;

int n, m;
int arr[9] = {0};

void find(int count){
    if(count == m){ // m���� ��� �����ߴٸ� ���
        for(int i = 1; i <= m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return ;
    }

    for(int i = arr[count]; i <= n; i++){   // ������ ������ ���� ������ �������� ������
        arr[count+1] = i;   // i�� ����
        find(count+1);      // ���� ���ڸ� ������
    }
}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    arr[0] = 1; // 1��° ������ ���� ������
    find(0);

    return 0;
}