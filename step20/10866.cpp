#include <iostream>
#include <vector>

using namespace std;

class deque{

private:
    vector<int> arr;

public:
    void push_front(int x){
        arr.insert(arr.begin(), x);
    }
    void push_back(int x){
        arr.push_back(x);
    }
    int pop_front(){
        if(arr.empty()) return -1;

        int front = arr.front();
        arr.erase(arr.begin());
        return front;
    }
    int pop_back(){
        if(arr.empty()) return -1;

        int back = arr.back();
        arr.pop_back();
        return back;
    }
    int size(){
        return (int)arr.size();
    }
    int empty(){
        if(size() == 0) return 1;
        return 0;
    }
    int front(){
        if(arr.empty()) return -1;
        return arr.front();
    }
    int back(){
        if(arr.empty()) return -1;
        return arr.back();
    }

};

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    deque myDeque;

    while(n--){
        string query;
        cin>>query;

        if(query == "push_front"){
            cin>>query;
            myDeque.push_front(stoi(query));
        }
        else if(query == "push_back"){
            cin>>query;
            myDeque.push_back(stoi(query));
        }
        else if(query == "pop_front"){
            cout<<myDeque.pop_front()<<'\n';
        }
        else if(query == "pop_back"){
            cout<<myDeque.pop_back()<<'\n';
        }
        else if(query == "size"){
            cout<<myDeque.size()<<'\n';
        }
        else if(query == "empty"){
            cout<<myDeque.empty()<<'\n';
        }
        else if(query == "front"){
            cout<<myDeque.front()<<'\n';
        }
        else if(query == "back"){
            cout<<myDeque.back()<<'\n';
        }
    }

    return 0;
}