#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int num1, num2;
        cin>>num1>>num2;

        if(num1 == 0){
            break;
        }

        if(num1 < num2 && num2 % num1 == 0){
            cout<<"factor\n";
        }
        else if (num1 > num2 && num1 % num2 == 0){
            cout<<"multiple\n";
        }
        else{
            cout<<"neither\n";
        }
    }

    return 0;
}