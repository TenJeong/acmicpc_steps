#include <iostream>
#include <vector>
#define MAX_NUM 10000

using namespace std;

class MyStack{

private:
    int content[MAX_NUM];
    int content_size = 0;

public:
    void push(int x){
        content[content_size++] = x;
    }

    int top(){
        if(content_size == 0) return -1;

        return content[content_size-1];
    }

    int pop(){
        if(content_size == 0) return -1;

        return content[--content_size];
    }

    int size(){
        return content_size;
    }

    int empty(){
        if(content_size == 0) return 1;

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