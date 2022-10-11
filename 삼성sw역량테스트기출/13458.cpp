#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, b, c;
vector<int> v;
long long counts = 0;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    long long answer = 0;

    cin>>n;

    for(int i = 0; i < n; i++){
        int num;
        cin>>num;

        v.push_back(num);
    }

    cin>>b>>c;

    for(int i = 0; i < n; i++){
        if(v[i] - b >= 0){
            // 총감독관 + (나머지 인원 / 부감독관 담당 가능 인원)
            counts += ((v[i] - b) / c) + 1;

            // 나누어 떨이지지 않으면 한 명 더 필요
            if((v[i] - b) % c != 0) counts++;
        }
        else counts++;
    }

    cout<<counts;

    return 0;
}