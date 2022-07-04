#include <iostream>

using namespace std;

int main(){
    int num;
    int arr[6][2];
    int count[5]={0};
    int big_area = 1;
    int small_area = 1;

    scanf("%d",&num);

    for(int i = 0; i < 6; i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        count[arr[i][0]]++;
    }


    for(int i = 0; i < 6; i++){
        if(count[arr[i][0]] == 1){
            big_area *= arr[i][1];
        }

        if(arr[i][0] == arr[(i+2)%6][0]){
            small_area *= arr[(i+1)%6][1];
        }
    }

    printf("%d",(big_area - small_area) * num);

    return 0;
}