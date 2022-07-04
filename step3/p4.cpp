#include <iostream>

using namespace std;

int main(void){
    int n,a,b;

    cin.tie(NULL);
    cin.sync_with_stdio(false);


    cout.tie(NULL);
    cout.sync_with_stdio(false);

    cin>>n;

    for(int i =0; i < n; i++){
        cin>>a>>b;
        cout<<a+b<<"\n";
    }

    return 0;
}