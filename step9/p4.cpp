#include <iostream>

using namespace std;

int count = 0;
string ans = "";

void movePlate(int m, int src, int des){
    if(m == 1) {
        ans += to_string(src) + " " + to_string(des) + "\n";
        count++;
    }
    else{
        int routePoint = 6 - src - des;
        movePlate(m-1, src, routePoint);
        ans += to_string(src) + " " + to_string(des) + "\n";
        count++;
        movePlate(m-1, routePoint, des);
    }
}

int main(){
    int n;

    cin>>n;

    movePlate(n, 1, 3);
    cout<<count<<'\n'<<ans;


    return 0;
}