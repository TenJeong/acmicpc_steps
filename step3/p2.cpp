#include <iostream>

using namespace std;

int main(void){
    int n, a, b;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        cout<<a+b;
        if(i!= n-1) cout<<endl;
    }

    return 0;
}