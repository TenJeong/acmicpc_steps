#include <iostream>

using namespace std;

int n, count=0;

void pcheck(int num, int step){
    int check;
    while(num>=0 && num<=n){
        check = num%10+step;
        num = num*10 + check;
        if(check>=0 && check<=9 && num <= n){
            count++;
        }
        else
            break;
    }
}

int main(void){

    cin>>n;

    for(int i = 1; i <= 9; i++){
        if(i<=n) count++;
        for(int j = -9; j<=9; j++){
            pcheck(i,j);
        }
    }

    cout<<count;

    return 0;
}