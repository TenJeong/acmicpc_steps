#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int r;
    double pi = M_PI;
    cin>>r;

    cout.precision(6);
    cout<< fixed;

    cout<<r*r*pi<<'\n';
    cout<<2.0*r*r;

    return 0;
}