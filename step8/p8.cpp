#include <iostream>

using namespace std;

int main(){

    int arr[3][2];
    int x,y;

    for(int i = 0; i < 3; i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    if(arr[0][0] == arr[1][0]) x= arr[2][0];
    else if (arr[0][0] == arr[2][0]) x= arr[1][0];
    else x = arr[0][0];

    if(arr[0][1] == arr[1][1]) y= arr[2][1];
    else if (arr[0][1] == arr[2][1]) y= arr[1][1];
    else y = arr[0][1];

    printf("%d %d",x,y);

    return 0;
}