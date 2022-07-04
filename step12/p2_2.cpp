#include <iostream>
#include <set>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n,m;
    long long count = 0;
    set<string> str_set;

    cin>>n>>m;

    for(long i = 0; i < n; i++){
        string temp_str;
        cin>>temp_str;

        str_set.insert(temp_str);
    }

    for(int i = 0; i < m; i++){
        string target;
        cin>>target;

        if(str_set.count(target)){
            count++;
        }
    }

    cout<<count;

    
    return 0;
}