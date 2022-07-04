#include <iostream>
#include <algorithm>

using namespace std;

typedef struct sPos {
    int x;
    int y;
    bool operator<(struct sPos pos2){
        if(y == pos2.y) return x < pos2.x;
        else return y < pos2.y;
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

    for(auto p : arr){
        printf("%d %d\n",p.x,p.y);
    }


    return 0;
}