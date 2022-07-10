#include <iostream>

using namespace std;

int n, m;
int arr[8] = {0};

void find(int count){
    if(count == m){
        for(int i = 0; i < m; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        arr[count] = i;
        find(count+1);
    }
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    find(0);

    return 0;
}