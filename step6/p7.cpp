#include <iostream>

using namespace std;

int main(){

    int num1, num2;

    cin>>num1>>num2;

    num1 = num1/100 + num1/10%10*10 + num1%10*100;
    num2 = num2/100 + num2/10%10*10 + num2%10*100;
    cout<<(num1>num2?num1:num2);

    return 0;
}