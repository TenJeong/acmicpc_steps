#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int arr[100001];
int total = 0;

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        total += arr[i]; // ��ü �� ����
    }

    while(m--){
        int start, end;
        cin>>start>>end;

        // ���� ���̰� ��ü ������ �� �̻��� ���
        if(end - start > (n / 2)){
            int front = 0, rear = 0;
            // ���� ���� ��
            for(int i = 1; i < start; i++){
                front += arr[i];
            }
            // ���� ���� ��
            for(int i = end + 1; i <= n; i++){
                rear += arr[i];
            }
            // ���� �յڸ� ��ü���� ��
            cout<<total - front - rear<<'\n';
        }
        else{
            int sum = 0;
            // ������ ª�� ��� �׳� ����
            for(int i = start; i <= end; i++){
                sum += arr[i];
            }
            cout<<sum<<'\n';
        }
    }
    

    return 0;
}