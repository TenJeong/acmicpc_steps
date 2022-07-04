#include <iostream>

using namespace std;

int main(void){
    int n,x;
    int num;

    cin.tie(NULL);

    cin>>n>>x;

    for(int i = 0; i < n; i++){
        cin>>num;
        if(num<x) cout<<num<<" ";
    }
    return 0;
}