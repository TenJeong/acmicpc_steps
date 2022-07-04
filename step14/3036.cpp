#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){

    int n;
    int first_ring;
    int another_ring;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    cin>>first_ring;

    for(int i = 1; i < n; i++){
        cin>>another_ring;
        int temp_a = first_ring, temp_b = another_ring;
        while(true){
            int gcd_num = gcd(temp_a, temp_b);
            if(gcd_num == 1) {
                cout<<temp_a<<'/'<<temp_b<<'\n';
                break;
            }
            temp_a /= gcd_num;
            temp_b /= gcd_num;
        }
    }

    return 0;
}