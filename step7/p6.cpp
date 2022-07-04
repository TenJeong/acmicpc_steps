#include <iostream>

using namespace std;

int main(){
    int case_num;
    int k,n;

    cin>>case_num;

    for(int i = 0;i < case_num; i++){
        cin>>k>>n;
        int arr[k+1][n+1]={0};

        for(int j = 1; j <= n; j++){
            arr[0][j] = j;
        }

        for(int j = 1; j <= k; j++){
            for(int v = 1; v <= n; v++){
                for(int w = 1; w <= v; w++){
                    arr[j][v] += arr[j-1][w];
                }
            }
        }
        
        cout<<arr[k][n]<<'\n';
    }


    return 0;
}