#include <iostream>

using namespace std;

int arr[21][21][21] = {0};
bool isCalculated[21][21][21] = {false};

int func_w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }

    if(a > 20 || b > 20 || c > 20){
        return func_w(20, 20, 20);
    }

    if(isCalculated[a][b][c])   return arr[a][b][c];

    isCalculated[a][b][c] = true;

    if(a < b && b < c){
        int result = func_w(a, b, c - 1) + func_w(a, b - 1, c - 1) - func_w(a, b - 1, c);
        arr[a][b][c] = result;
        return result;
    }

    int result = func_w(a - 1, b, c) + func_w(a - 1, b - 1, c) + func_w(a - 1, b, c - 1) - func_w(a - 1, b - 1, c - 1);
    arr[a][b][c] = result;
    return result;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true){
        int a, b, c;
        cin>>a>>b>>c;

        if(a == -1 && b == -1 && c == -1) break;

        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<func_w(a, b, c)<<'\n';
    }


    return 0;
}