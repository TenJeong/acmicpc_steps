#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    int n,m;
    set<string> noDUT, noBO;
    vector<string> result;

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;
        noDUT.insert(temp);
    }

    for(int i = 0; i < m; i++){
        string temp;
        cin>>temp;
        noBO.insert(temp);
    }

    if(n < m){
        for(auto query : noDUT){
            if(noBO.count(query)){
                result.push_back(query);
            }
        }
    }
    else{
        for(auto query : noBO){
            if(noDUT.count(query)){
                result.push_back(query);
            }
        }
    }

    cout<<result.size()<<'\n';
    for(auto str : result){
        cout<<str<<'\n';
    }


    return 0;
}