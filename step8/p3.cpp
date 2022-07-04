#include <iostream>

using namespace std;

int main(){
    int num;

    cin>>num;

    for(int i = 2; num != 1; i++){
        while(num % i == 0){
            printf("%d\n",i);
            num/=i;
        }
    }


    return 0;
}