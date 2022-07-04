#include <iostream>

using namespace std;

int main(){
    int n;
    bool isPrime = true;

    scanf("%d\n",&n);
    while(n!=0){
        int n2 = 2*n;
        int count = 0;
        for(int i = n+1; i <= n2; i++){
            if(i == 1) continue;
            isPrime = true;
            for(int j = 2; j * j <= i; j++){
                if(i%j ==0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) count++;
        }

        printf("%d\n",count);

        scanf("%d\n",&n);
    }

    return 0;
}