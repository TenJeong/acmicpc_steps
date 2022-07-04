#include <iostream>
#include <cstring>

using namespace std;

int arr[31][31];

int pascal(int n, int c){
    if(n == c || c == 0) return 1;
    if(arr[n][c] == 0) {
        int temp = pascal(n-1, c-1) + pascal(n-1, c);
        arr[n][c] = temp;
        return temp;
    }
    return arr[n][c];
}

int main(){

    int t;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;

    // array �ʱ�ȭ
    memset(arr[0], 0, sizeof(int) * 31 * 31);

    for(int i = 0; i < t; i++){
        int n,m;
        cin>>n>>m;
        //m���� ����Ʈ���� n���� �����ϴ� �Ͱ� �����ϴ�.
        cout<<pascal(m, n)<<'\n';
    }

    return 0;
}