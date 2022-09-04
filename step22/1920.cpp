#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int arr[100000];
    int n, m;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // binary search전에 sorting 필요
    sort(arr, arr + n);
    
    cin>>m;

    while(m--){
        int query;
        cin>>query;

        // binary search 수행
        if(binary_search(arr, arr + n, query)){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }

    return 0;
}