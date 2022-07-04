#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,m;
    map<long long, int> nums;

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i = 0; i < n; i++){
        long long temp;
        cin>>temp;
        auto result = nums.find(temp);
        if(result == nums.end()){
            nums.insert({temp,1});
        }
        else{
            result->second++;
        }
    }

    cin>>m;

    for(int i = 0; i < m; i++){
        long long temp;
        cin>>temp;
        auto search_result = nums.find(temp);
        if(search_result == nums.end()){
            cout<<"0 ";
        }
        else{
            cout<<search_result->second<<' ';
        }
    }

    return 0;
}