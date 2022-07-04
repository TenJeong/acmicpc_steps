#include <iostream>

using namespace std;

int main(){

    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    while(a!=0 || b!=0 || c!= 0){
        if(a>b && a>c){
            int temp = a;
            a = c;
            c = temp;
        }
        else if (b>a && b>c){
            int temp = b;
            b = c;
            c = temp;
        }

        if(a*a + b*b == c*c){
            printf("right\n");
        }
        else{
            printf("wrong\n");
        }
        scanf("%d %d %d",&a,&b,&c);
    }

    return 0;
}