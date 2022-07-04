#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int x;
    int y;
}pos;

int compare(pos n1, pos n2){
    if(n1.x == n2.x)
        return n1.y < n2.y;
    else return n1.x < n2.x;
}

int main(){

    int n;

    scanf("%d",&n);

    pos arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }

    sort(arr,arr+n,compare);

    for(auto i : arr){
        printf("%d %d\n",i.x,i.y);
    }


    return 0;
}