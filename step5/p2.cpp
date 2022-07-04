#include <iostream>

using namespace std;

int arr[10001]={0};

void checking(int num){
    int next=0;
    int pnum = num;

    if(num>10000) return;

    while(pnum!=0){
        next += pnum % 10;
        pnum/=10;
    }

    next+=num;

    arr[next]=1;
    
    checking(next);
}

int main(void){

    cout.tie(NULL);

    for(int i = 1; i < 10001; i++){
        checking(i);
    }

    for(int i = 1; i < 10001; i++){
        if(arr[i] == 0)
            cout<<i<<'\n';
    }


    return 0;
}