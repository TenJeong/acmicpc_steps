#include <iostream>

using namespace std;

int W, H, X, Y, P;

bool isInRink(int x, int y){
    if(x >= X && x <= X+W && y >= Y && y <= Y+H)
        return true;
    int radius = H/2;
    if(x <= X && x >= X - radius && (X - x) * (X - x)  + (Y + radius - y) * (Y + radius - y) <= radius * radius)
        return true;
    if(x >= X + W && x <= X + W + radius && (X + W - x) * (X + W - x) + (Y + radius - y) * (Y + radius - y) <= radius * radius)
        return true;
    return false;
}

int main(){
    int count=0;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>W>>H>>X>>Y>>P;

    for(int i = 0; i < P; i++){
        int p_x, p_y;
        cin>>p_x>>p_y;
        if(isInRink(p_x, p_y)) {
            count++;
        }
    }

    cout<<count;

    return 0;
}