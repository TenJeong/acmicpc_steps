#include <iostream>


using namespace std;

int main(){

    string A,B;
    string ans = "";
    int carry = 0;


    cin.tie(NULL);
    cout.tie(NULL);

    cin>>A>>B;

    int ptrA = A.size()-1;
    int ptrB = B.size()-1;

    while(ptrA >= 0 && ptrB >= 0){
        int numA = A[ptrA--] - '0';
        int numB = B[ptrB--] - '0';

        ans = to_string((numA + numB + carry) % 10) + ans;
        carry = (numA + numB + carry) / 10;
    }

    if(ptrA >= 0 && ptrB<0){
        while(ptrA>=0){
            int numA = A[ptrA--] - '0';

            ans = to_string((numA + carry) % 10) + ans;
            carry = (numA + carry) / 10;
        }
    }
    else if (ptrB >= 0 && ptrA < 0){
        while(ptrB>=0){
            int numB = B[ptrB--] - '0';

            ans = to_string((numB + carry) % 10) + ans;
            carry = (numB + carry) / 10;
        }
    }

    if(carry) ans = to_string(carry) + ans;

    cout<<ans;

    return 0;
}