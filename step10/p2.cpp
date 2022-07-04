#include <iostream>

using namespace std;

int main(){

    int n;
    int nlen=0;

    scanf("%d",&n);

    for(int t = n; t > 0; t/=10){
        nlen++;
    }


    for(int i = n - nlen * 9; i < n; i++){
        int m = i;
        for(int check = i; check > 0; check /= 10){
            m += check % 10;
        }

        if(m == n){
            printf("%d",i);
            return 0;
        }
    }

    printf("0");


    return 0;
}