#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;

    scanf("%d",&n);

    pair<int, int> arr[n];

    for(int i = 0 ; i < n; i++){
        int tempX, tempY;
        scanf("%d %d",&tempX,&tempY);
        arr[i] = make_pair(tempX,tempY);
    }

    sort(arr,arr+n);

    for(auto pos : arr){
        printf("%d %d\n",pos.first,pos.second);
    }

    return 0;
}