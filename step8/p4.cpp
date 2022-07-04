#include <iostream>

using namespace std;

int main(){

    int min, max;
    bool isPrime = true;
    scanf("%d %d",&min,&max);

    for(int i = min; i <= max; i++){
        if(i == 1) continue;

        isPrime = true;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime) printf("%d\n", i);
    }


    return 0;
}