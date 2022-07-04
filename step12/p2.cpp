#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<string> string_list;
    int n,m;
    int count = 0;

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        string temp_str;
        cin>>temp_str;

        string_list.push_back(temp_str);
    }

    sort(string_list.begin(),string_list.end());

    for(int i = 0; i < m; i++){
        string target;
        cin>>target;
        if(binary_search(string_list.begin(),string_list.end(),target))
            count++;
    }

    cout<<count;

    
    return 0;
}