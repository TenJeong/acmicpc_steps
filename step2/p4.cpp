#include <iostream>

using namespace std;

int main(void){
    int xpos, ypos;

    cin>>xpos>>ypos;

    if(xpos>0){
        if(ypos>0) cout<<'1';
        else cout<<'4';
    }
    else{
        if(ypos>0) cout<<'2';
        else cout<<'3';
    }

    return 0;
}