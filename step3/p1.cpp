#include <iostream>

using namespace std;

int main(void){
    int n;

    cin>>n;

    for(int i = 1; i <= 9; i++){
        cout<<n<<" * "<<i<<" = "<<n*i;
        if(i!=9) cout<<endl;
    }

    return 0;
}