#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){

    int N;
    vector<int> v, ans;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;

    for(int i = 0; i < N; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    int myGCD = v[1] - v[0];

    for(int i = 2; i < N; i++){
        myGCD = gcd(myGCD, v[i] - v[i-1]);
    }

    for(int i = 2; i * i <= myGCD; i++){
        if(myGCD % i == 0){
            ans.push_back(i);
            if(i * i != myGCD) ans.push_back(myGCD / i);
        }
    }

    ans.push_back(myGCD);
    sort(ans.begin(),ans.end());

    for(auto a : ans)
        cout<<a<<' ';
    
    
    return 0;
}