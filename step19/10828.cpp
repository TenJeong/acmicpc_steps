#include <iostream>
#include <vector>

using namespace std;

class MyStack{

private:
    vector<int> content;

public:
    void push(int x){
        content.push_back(x);
    }

    int top(){
        if(content.size() <= 0) return -1;

        int num_pop = content.back();

        return num_pop;
    }

    int pop(){
        int cur_top = top();
        if(cur_top != -1) content.pop_back();

        return cur_top;
    }

    int size(){
        return content.size();
    }

    int empty(){
        if(content.empty()) return 1;
        return 0;
    }

};

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    MyStack mystack;

    while(n--){
        string query;
        cin>>query;

        if(query == "push"){
            cin>>query;
            mystack.push(stoi(query));
        }
        else if(query == "pop"){
            cout<<mystack.pop()<<'\n';
        }
        else if(query == "size"){
            cout<<mystack.size()<<'\n';
        }
        else if(query == "empty"){
            cout<<mystack.empty()<<'\n';
        }
        else if(query == "top"){
            cout<<mystack.top()<<'\n';
        }
    }

    return 0;
}