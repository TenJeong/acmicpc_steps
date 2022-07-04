#include <iostream>
#include <set>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    set<string> sub_set;
    string str;
    cin>>str;

    for(int i = 0; i < str.size(); i++){
        string temp = "";
        for(int j = i; j < str.size(); j++){
            temp+=str[j];
            sub_set.insert(temp);
        }
    }

    cout<<sub_set.size();

    return 0;
}