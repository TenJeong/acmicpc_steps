#include <iostream>

using namespace std;

int main(){
    int A,B,C;
    long x;
    cin>>A>>B>>C;

    if(B>=C)
        cout<<-1;
    else{
        x = A / (C-B) + 1;
        cout<<x;
    }

    return 0;
}