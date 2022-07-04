#include <iostream>

using namespace std;

int main(){
    long A,B,V;
    long height=0;
    int days=0;

    cin>>A>>B>>V;

    V-=A;

    days = V / (A-B) + 1;

    if(V%(A-B)!=0)
        days+=1;

    cout<<days;


    return 0;
}