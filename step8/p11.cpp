#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n;
    int x1,y1,r1;
    int x2,y2,r2;


    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        double distance = sqrt(pow(x1-x2,2) + pow(y1-y2,2));

        if(distance == 0 && r1 == r2){
            printf("-1\n");
        }
        else if (distance > r1 + r2){
            printf("0\n");
        }
        else if (distance == r1 + r2){
            printf("1\n");
        }
        else if (r1 < distance + r2 && r2 < distance + r1){
            printf("2\n");
        }
        else{
            if(distance + r1 == r2 || distance + r2 == r1){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
    }

    return 0;
}