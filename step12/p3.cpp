#include <iostream>
#include <map>

using namespace std;

bool is_number(const string s){
    for(auto ch : s){
        if(!isdigit(ch)) return false;
    }

    return true;
}

int main(){
    int n,m;
    map<string, int> pokemon_list_name_index;
    map<int, string> pokemon_list_num_index;

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        string temp;
        cin>>temp;
        pokemon_list_name_index.insert({temp, i+1});
        pokemon_list_num_index.insert({i+1,temp});
    }

    for(int i = 0; i < m; i++){
        string query;
        cin>>query;
        if(is_number(query)) {
            int num = stoi(query);
            auto result = pokemon_list_num_index.find(num);
            cout<<result->second<<'\n';
        }
        else{
            auto result = pokemon_list_name_index.find(query);
            cout<<result->second<<'\n';
        }
    }

    return 0;
}