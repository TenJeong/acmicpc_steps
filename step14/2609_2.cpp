#include <iostream>

using namespace std;

int gcd(int a, int b){
    int g;
    while(b != 0){
        g = a % b;
        a = b;
        b = g;
    }

    return a;
}

int main(){

    int numA, numB;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>numA>>numB;

    int numG = gcd(numA, numB);

    cout<<numG<<'\n'<<numA * numB / numG;

    return 0;
}