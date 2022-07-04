#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n,m;
    vector<long long> nums;

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    for(int i = 0; i < n; i++){
        long long temp;
        cin>>temp;
        nums.push_back(temp);
    }

    sort(nums.begin(),nums.end());

    cin>>m;

    for(int i = 0; i < m; i++){
        long long query;
        cin>>query;

        auto result = equal_range(nums.begin(),nums.end(),query);
        cout<<result.second - result.first<<' ';
    }

    return 0;
}