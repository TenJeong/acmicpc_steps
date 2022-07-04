#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b); 
}

int main(){

    int case_num;
    int numA, numB;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>case_num;

    for(int i = 0; i < case_num; i++){
        cin>>numA>>numB;
        cout<<numA * numB / gcd(numA, numB)<<'\n';
    }

    return 0;
}