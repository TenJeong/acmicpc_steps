#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    string str;
    vector<char> list;
    bool dup = false;
    int count=0;

    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>str;
        for(const auto &c : str){
            if(list.size()==0){
                list.push_back(c);
            }
            else{
                for(int i=0; i < list.size()-1; i++){
                    if(c==list[i]){
                        dup = true;
                        break;
                    }
                }
                if(dup == false && list.back() != c){
                    list.push_back(c);
                }
            }
        }
        if(dup == false){
            count++;
        }
        dup=false;
        list.clear();
    }

    cout<<count;
    
    return 0;
}