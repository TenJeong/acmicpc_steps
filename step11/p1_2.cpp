#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n;
    int min_index;

    scanf("%d",&n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < n-1; i++){
        min_index = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

    }


    for(int i = 0; i < n; i++){
        printf("%d\n",arr[i]);
    }


    return 0;
}