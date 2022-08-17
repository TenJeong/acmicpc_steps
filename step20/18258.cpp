#include <iostream>

using namespace std;

class MyQueue{

private:
    int arr[2000000];
    int frontPtr, rearPtr;

public:
    MyQueue(){
        frontPtr = 0;
        rearPtr = -1;
    }
    void push(int x){
        if(rearPtr < frontPtr){
            arr[frontPtr] = x;
            rearPtr = frontPtr;
        }
        else{
            arr[++rearPtr] = x;
        }
    }

    int pop(){
        if(rearPtr < frontPtr) return -1;

        return arr[frontPtr++];
    }

    int size(){
        if(rearPtr < frontPtr) return 0;
        return rearPtr - frontPtr + 1;
    }

    int empty(){
        if(size() == 0) return 1;
        return 0;
    }

    int front(){
        if(empty()) return -1;
        return arr[frontPtr];
    }

    int back(){
        if(empty()) return -1;
        return arr[rearPtr];
    }
};


int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    MyQueue myQueue;

    while(n--){
        string query;
        cin>>query;

        if(query == "push"){
            cin>>query;
            myQueue.push(stoi(query));
        }
        else if(query == "pop"){
            cout<<myQueue.pop()<<'\n';
        }
        else if(query == "size"){
            cout<<myQueue.size()<<'\n';
        }
        else if(query == "empty"){
            cout<<myQueue.empty()<<'\n';
        }
        else if(query == "front"){
            cout<<myQueue.front()<<'\n';
        }
        else if(query == "back"){
            cout<<myQueue.back()<<'\n';
        }
    }

    return 0;
}