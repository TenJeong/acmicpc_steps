#include <iostream>

using namespace std;

int main(){

    int n;

    scanf("%d\n",&n);

    int arr[n][2];

    for(int i = 0; i < n; i++){ 
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }

    for(int i = 0; i < n; i++){
        int count = 0;

        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) count++;
        }

        printf("%d ",count+1);
    }

    return 0;
}