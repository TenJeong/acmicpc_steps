#include <iostream>

using namespace std;

void starPrint(int num, int row){
    if(num == 1){
        printf("*");
        return ;
    }
    for(int i = 0; i < num; i+=num/3){
        if(row%num >= num / 3 && row%num < num / 3 * 2 && i >= num / 3 && i < num / 3 * 2){
            for(int j = 0; j < num/3; j++) printf(" ");
        }
        else starPrint(num/3, row);
    }
}


int main(){

    int n;

    cin>>n;

    for(int i = 0; i < n; i++){
        starPrint(n, i);
        printf("\n");
    }
    return 0;
}