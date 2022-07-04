#include <iostream>

using namespace std;

int main(void){
    int count[10]={0};
    int a,b,c,mul;

    cin>>a>>b>>c;
    mul = a*b*c;

    while(mul!=0){
        count[mul%10]++;
        mul/=10;
    }

    for(int n : count)
        cout<<n<<"\n";

    return 0;
}