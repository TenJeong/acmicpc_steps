#include <iostream>

using namespace std;

long long arr[101] = {0};

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int t,n;
    int max = 5; // ���� ��� �ִ밪

    cin>>t;

    arr[0] = 0; arr[1] = 1; arr[2] = 1; arr[3] = 1;
    arr[4] = 2; arr[5] = 2;
    while(t--){
        cin>>n;
        if(n > max){ // ���� ������� ���� ��
            for(int i  = max + 1; i <= n; i++){ // i-1��°�� i-5��°�� �հ� ����
                arr[i] = arr[i - 1] + arr[i - 5];
            }
            max = n;
        }
        cout<<arr[n]<<'\n';
    }

    return 0;
}