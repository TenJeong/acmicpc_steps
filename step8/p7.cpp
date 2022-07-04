#include <iostream>

using namespace std;

int main(){

    int x,y,w,h;
    int length;

    cin>>x>>y>>w>>h;

    length = x;

    if(y < length) length = y;

    if(w-x < length) length = w-x;

    if(h-y < length) length = h-y;


    cout<<length;

    return 0;
}