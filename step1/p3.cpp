#include <iostream>
#include <string>
using namespace std;

int main(void){
    int n1,n2;
    int total=0;

    cin>>n1>>n2;

    cout<<n1*(n2%10)<<endl;
    total+=n1*(n2%10);
    n2/=10;

    cout<<n1*(n2%10)<<endl;
    total+=n1*(n2%10)*10;
    n2/=10;

    cout<<n1*(n2%10)<<endl;;
    cout<<total+(n1*(n2%10)*100);

    return 0;
}