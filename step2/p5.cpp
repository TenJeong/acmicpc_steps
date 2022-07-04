#include <iostream>

using namespace std;

int main(void){
    int hh,mm;

    cin>>hh>>mm;

    mm-=45;

    if(mm<0){
        if(hh==0) hh=23;
        else hh--;

        mm+=60;
    }

    cout<<hh<<" "<<mm;

    return 0;
}