#include <iostream>
#include <algorithm>

using namespace std;

typedef struct myPos{
    int x;
    int y;
    bool operator<(struct myPos pos2){
        if(x == pos2.x) return y<pos2.y;
        else return x < pos2.x;
    }
}pos;

int main(){

    int n;

    scanf("%d",&n);

    pos arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d %d",&arr[i].x,&arr[i].y);
    }

    sort(arr,arr+n);

    for(auto posi : arr){
        printf("%d %d\n",posi.x,posi.y);
    }

    return 0;
}