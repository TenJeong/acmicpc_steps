#include <iostream>

using namespace std;

int main(){
    long num;
    long check=1;
    cin>>num;

    for(int i = 0;;i++){
        check = check + i*6;
        if(num<=check){
            cout<<i+1;
            break;
        }
    }

    return 0;
}