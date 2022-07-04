#include <iostream>

using namespace std;

int main(){

    int n;
    int num, count = 0;

    scanf("%d\n",&n);

    for(int i = 0; i < n; i++){
        scanf("%d",&num);
        for(int j = 2; j <= num; j++){
            if(j == num){
                count++;
                break;
            }
            if(num % j == 0) break;
        }
    }

    printf("%d",count);

    return 0;
}